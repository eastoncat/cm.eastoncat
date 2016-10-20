<?php

/**
 * @file media_cloudcast/includes/themes/media_cloudcast.theme.inc
 *
 * Theme and preprocess functions for Media: Cloudcast.
 */

/**
 * Preprocess function for theme('media_cloudcast_video').
 */
function media_cloudcast_preprocess_media_cloudcast_video(&$variables) {
  $show_video = FALSE;
  $show_thumbnail = FALSE;

  if (isset($variables['node'])) {
    $node = $variables['node'];
    $lang = $node->language;

    // Check if manual control for a video availability
    if (variable_get('media_cloudcast_video_access', 0) && in_array($node->type, array_filter(variable_get('media_cloudcast_node_types', array())))) {
      if (isset($node->cloudcast_field_available) && !empty($node->cloudcast_field_available)) {
        $availability = $node->cloudcast_field_available[$lang][0]['value'];

        if ($availability) {
          $show_video = TRUE;
        }
        else {
          module_load_include('inc', 'media_cloudcast', 'includes/media_cloudcast.admin');

          $bundle_info = media_cloudcast_bundle_load('node', $node->type);
          $video_info = $bundle_info['info']['media_cloudcast'];

          if ($video_info['display']) {
            $show_thumbnail = TRUE;
          }
        }
      }
    }
    else {
      $show_video = TRUE;
    }
  }
  else {
    $show_video = TRUE;
  }

  if ($show_video) {
    // Build the URI.
    $wrapper = file_stream_wrapper_get_instance_by_uri($variables['uri']);
    $parts = $wrapper->get_parameters();
    //$variables['video_id'] = check_plain($parts['v']);

    $variables['client_id'] = check_plain($parts['id']);
    $variables['video_id'] = check_plain($parts['video']);

    // Parse options and build the query string. Only add the option to the query
    // array if the option value is not default. Be careful, depending on the
    // wording in media_cloudcast.formatters.inc, TRUE may be query=0.
    // @see https://developers.google.com/cloudcast/player_parameters#Parameters
    $query = array();

    // Make css z-index work with flash object. Must be the first parameter.
    $query['wmode'] = 'opaque';

    // These queries default to 0. If the option is true, set value to 1.
    foreach (array('autoplay', 'enablejsapi', 'loop', 'modestbranding', 'html5') as $option) {
      if ($variables['options'][$option]) {
        if ($option == 'html5') {
          $query['HTML5'] = 'true';
        }
        else {
          $query[$option] = 1;
        }
      }
    }

    /*

    if ($variables['options']['enablejsapi']) {
      // Add a query ID and identical html ID if js API is set.
      $query['playerapiid'] = drupal_html_id('media-cloudcast-' . $variables['video_id']);
      $variables['api_id_attribute'] = 'id="' . $query['playerapiid'] . '" ';

      //Add the origin for improved security
      $variables['options']['origin'] ? $query['origin'] = $variables['options']['origin'] : '';
    }
    else {
      $variables['api_id_attribute'] = NULL;
    }

  */
    // Currently, loop only works with a playlist. Make fake playlist out of a
    // single video.
    // @see https://developers.google.com/cloudcast/player_parameters#loop
    /*

    if ($variables['options']['loop']) {
      $query['playlist'] = $variables['video_id'];
    }

    // These queries default to 1. If the option is false, set value to 0.
    foreach (array('rel', 'showinfo') as $option) {
      if (!$variables['options'][$option]) {
        $query[$option] = 0;
      }
    }
  */

    // These queries default to 1. Option wording is reversed, so if the option
    // is true, set value to 0.
    // (None right now.)

    // Strings.
    /*

    if ($variables['options']['theme'] != 'dark') {
      $query['theme'] = $variables['options']['theme'];
    }
    if ($variables['options']['color'] != 'red') {
      $query['color'] = $variables['options']['color'];
    }
    if ($variables['options']['autohide'] != '2') {
      $query['autohide'] = $variables['options']['autohide'];
    }

    // Non-query options.
    if ($variables['options']['nocookie']) {
      $url_base = 'cloudcast-nocookie.com';
    }
    else {
      $url_base = 'cloudcast.com';
    }
  */
    if ($variables['options']['protocol_specify']) {
      $protocol = $variables['options']['protocol'];
    }
    else {
      $protocol = '';
    }


    // Add some options as their own template variables.
    foreach (array('width', 'height') as $themevar) {
      $variables[$themevar] = $variables['options'][$themevar];
    }


    // Do something useful with the overridden attributes from the file
    // object. We ignore alt and style for now.
    /*

    if (isset($variables['options']['attributes']['class'])) {
      $variables['classes_array'] = array_merge($variables['classes_array'], $variables['options']['attributes']['class']);
    }
  */

    // Build the iframe URL with options query string.

    //http://cvp.telvue.com/player?id=T01193&video=22578&noplaylistskin=1&width=400&height=300
    //dsm($variables);
    $query['id'] = $variables['client_id'];
    $query['video'] =  $variables['video_id'];
    $query['noplaylistskin'] = 1;
    $query['width'] = 400;
    $query['height'] = 300;

    if ($variables['options']['override_size']) {
      if (isset($parts['width'])) {
        $variables['width'] = $query['width'] = check_plain($parts['width']);
      }
      if (isset($parts['height'])) {
        $variables['height'] = $query['height'] = check_plain($parts['height']);
      }
    }

    $variables['url'] = url($protocol .'//vp.telvue.com/player', array('query' => $query, 'external' => TRUE));
  }
  else if ($show_thumbnail) {
    module_load_include('inc', 'media_cloudcast', '/includes/media_cloudcast.formatters.inc');

    $files = file_load_multiple(array(), array('uri' => $variables['uri']));
    $file = array_shift($files);

    // Get image style configured in file display
    $view_mode = 'default';
    $file_displays = file_displays_load($node->type, $view_mode);

    $image_style = $file_displays[$node->type . '__' . $view_mode . '__' . 'media_cloudcast_image']->settings['image_style'];

    // Set up the settings array with your image style
    $display['settings'] = array('image_style' => $image_style);

    // Get the render array for the thumbnail image
    $image_render_array = media_cloudcast_file_formatter_image_view($file, $display, LANGUAGE_NONE);

    // Render it
    $variables['video_thumbnail'] = render($image_render_array);
  }

  $variables['show_video'] = $show_video;
  $variables['show_thumbnail'] = $show_thumbnail;
}
