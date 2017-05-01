<?php

function cm_bootstrap_metatag_cm_show_image() {
  if ($node = menu_get_object()) {
    // Switch to account for cloudcast, vimeo, youtube, etc.
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
    }
    else {
      if (module_exists('cm_bootstrap_cp_default_images')) {
        $file = cm_bootstrap_cp_default_images_load_image($node->type);
        $image_uri = $file->uri;
      }
      else {
        $img_src = '';
      }
    }
    $img_src = image_style_url('500x281', $image_uri);

    $og_image = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image',
        'content' => $img_src,
      ),
    );
    drupal_add_html_head($og_image, 'og:image');

    $og_image_width = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image:width',
        'content' => '500',
      ),
    );
    drupal_add_html_head($og_image_width, 'og:image:width');

    $og_image_height = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image:height',
        'content' => '281',
      ),
    );
    drupal_add_html_head($og_image_height, 'og:image:height');
  }
}
