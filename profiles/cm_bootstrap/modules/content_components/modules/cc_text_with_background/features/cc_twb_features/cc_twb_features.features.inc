<?php
/**
 * @file
 * cc_twb_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cc_twb_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cc_twb_features_image_default_styles() {
  $styles = array();

  // Exported image style: cc_twb_parallax.
  $styles['cc_twb_parallax'] = array(
    'name' => 'cc_twb_parallax',
    'label' => 'cc_twb_parallax',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1800,
          'height' => 1047,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function cc_twb_features_paragraphs_info() {
  $items = array(
    'text_with_background' => array(
      'name' => 'Text With Background',
      'bundle' => 'text_with_background',
      'locked' => '1',
    ),
  );
  return $items;
}
