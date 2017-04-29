<?php

/**
 * @file
 * template.php
 */

/**
 * Implements template_preprocess_html(&$variables).
 */
function cmb_theme_preprocess_html(&$variables) {
  foreach($variables['user']->roles as $role){
    $variables['classes_array'][] = 'role-' . drupal_html_class($role);
  }
}

/**
 * Implements template_preprocess_page(&$variables).
 */
function cmb_theme_preprocess_page(&$variables) {
  if (!drupal_is_front_page()) {
    //
    if (isset($variables['node'])) {
      $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    }
  }

  // Add a legacy tpl for page
  if (isset($variables['node'])) {
    $node = $variables['node'];

    switch ($node->type) {
      case 'page':
      case 'blog':
        $field_legacy_toggle = TRUE;
        if (isset($node->field_legacy_toggle[LANGUAGE_NONE])) {
          $field_legacy_toggle = $node->field_legacy_toggle[LANGUAGE_NONE][0]['value'];
        }

        if ($field_legacy_toggle) {
          $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type . '__legacy';
        }
        break;
    }

  }

  // Full width toggle for Basic Page/Paragraphs
  if (isset($variables['node'])) {
    $node = $variables['node'];

    if ($node->type == 'page' || $node->type == 'blog') {
      // Check if field has a value.
      if (isset($node->field_full_width[LANGUAGE_NONE])) {
        $full_width = $node->field_full_width[LANGUAGE_NONE][0]['value'];

        // Set full width
        if ($full_width) {
          $variables['full_width_toggle'] = TRUE;
          $variables['region__content_cols'] = 'col-sm-12';
          $variables['container_class'] = 'container-fluid';
        }
        // Allow sidebar
        else {
          $variables['full_width_toggle'] = FALSE;
          $variables['container_class'] = 'container';

          if (empty($variables['page']['sidebar_second'])) {
            $variables['region__content_cols'] = 'col-sm-12';
          }
          else {
            $variables['region__content_cols'] = 'col-sm-8';
            $variables['region__sidebar_second_cols'] = 'col-sm-4';
          }
        }
      }
      // If no field value, default to sidebar.
      else {
        $variables['full_width_toggle'] = FALSE;
        $variables['container_class'] = 'container';

        // No block in sidebar, go full width
        if (empty($variables['page']['sidebar_second'])) {
          $variables['region__content_cols'] = 'col-sm-12';
        }
        else {
          $variables['region__content_cols'] = 'col-sm-8';
          $variables['region__sidebar_second_cols'] = 'col-sm-4';
        }
      }
    }
  }

  //dpm($variables);
}

/**
 * Implements template_preprocess_node(&$variables)
 */
function cmb_theme_preprocess_node(&$variables) {
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['nid'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Search index view mode
  if ($variables['view_mode'] == 'search_index') {
    include_once dirname(__FILE__) . '/preprocess_node/node--search-index.php';
    _node__search_index($variables);
  }

  // Preprocess node files
  $file = dirname(__FILE__) . '/preprocess_node/node--' . $variables['node']->type . '.php';
  if (file_exists($file)) {
    include_once $file;
    $function = '_node__' . $variables['node']->type;
    $function($variables);
  }
}

/**
 * Implements template_preprocess_user_profile
 *
 * @param type $variables
 */
function cmb_theme_preprocess_user_profile(&$variables) {
//  die("<pre>".var_export($variables, true));
  $account = $variables['elements']['#account'];

  if (module_exists('cm_bootstrap_community')) {
    if (!empty($variables['field_featured_video']))
      $variables['featured_video'] = field_view_field('node', $variables['field_featured_video'][0]['entity'], 'field_show_vod', 'Full content');
    else
      $variables['featured_video'] = false;
    $variables['recent_videos'] = _cm_bootstrap_community_get_recent_videos($account->uid);
    $variables['following'] = _cm_bootstrap_community_get_following($account->uid);
    $variables['follows'] = _cm_bootstrap_community_get_follows($account->uid);
    $variables['likes'] = _cm_bootstrap_community_get_likes($account->uid);
    $variables['video_count'] = _cm_bootstrap_community_get_user_video_count($account->uid);
  }
}

/**
 * Implements theme_menu_link(array $variables).
 *
 * Overrides bootstrap's theme/menu/menu-link.func.php:bootstrap_menu_link(array $variables)
 * To remove the drop-down menus and other crap that bootstrap adds.
 * This resets theme_menu_link to its default code.
 */
function cmb_theme_menu_link(array $variables) {
  $element = $variables ['element'];
  $sub_menu = '';

  if ($element ['#below']) {
    $sub_menu = drupal_render($element ['#below']);
  }
  $output = l($element ['#title'], $element ['#href'], $element ['#localized_options']);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements template_preprocess_search_result(&$variables)
 */
function cmb_theme_preprocess_search_result(&$variables) {
  //dpm($variables);
  if (isset($variables['result']['node'])) {
    $node = $variables['result']['node'];
    if (isset($node->field_show_vod['und'])) {
      switch($node->field_show_vod['und'][0]['filemime']) {
        case 'video/cloudcast':
          $image_uri = 'media-cloudcast/' . $node->field_show_vod['und'][0]['filename']  . '.jpg';
          break;
        case 'video/vimeo':
          $image_uri = str_replace('vimeo://v/', 'media-vimeo/', $node->field_show_vod['und'][0]['uri']);
          $image_uri = $image_uri . '.jpg';
          break;
        case 'video/youtube':
          $image_uri = str_replace('youtube://v/', 'media-youtube/', $node->field_show_vod['und'][0]['uri']);
          $image_uri = $image_uri . '.jpg';
          break;
      }
      $variables['cm_show_img'] = image_style_url('medium', $image_uri);
    }

    // Add series
    if (isset($node->og_group_ref['und'])) {
      $series_nid = $node->og_group_ref['und'][0]['target_id'];
      $series_node = node_load($series_nid);
      if ($series_node) {
        //dpm($series_node);
        $variables['cm_series'] = array(
          'title' => $series_node->title,
          'url' => url('node/' . $series_node->nid),
        );
      }
    }

  }
}

/**
 * - Temporary fix to disable popcorn support under mobile. To be removed when
 * https://github.com/mozilla/popcorn-js/issues/320 is fixed
 * - disable popcorn when there are no cue field
 */
function cmb_theme_preprocess_media_youtube_video(&$variables) {
  // Skip iOS, until popcorn mobile support is fixed
  /*$variables['is_iOS'] = FALSE;

  if (_retn_custom_is_ios()) {
    $variables['is_iOS'] = TRUE;
  }*/

  // @todo commenting out below lets video go full width, but chapter clicking doesnt work
  // leaving this code in, chapter click works, but videos dont go full width...
  // check for cue field
  $variables['has_cue_points'] = TRUE;

  $file = file_load($variables['popcorn_fid']);

  if (!isset($file->cue_points) || (isset($file->cue_points) && empty($file->cue_points))) {
    $variables['has_cue_points'] = FALSE;
  }
}
