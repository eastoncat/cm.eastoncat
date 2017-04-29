<?php
/**
 * @file
 * cc_slider_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cc_slider_features_image_default_styles() {
  $styles = array();

  // Exported image style: cc_slider_image.
  $styles['cc_slider_image'] = array(
    'label' => 'cc_slider_image',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1520,
          'height' => 854,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: cc_slider_image_thumbnail.
  $styles['cc_slider_image_thumbnail'] = array(
    'label' => 'CC Slider Image Thumbnail',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 279,
          'height' => 139.5,
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
function cc_slider_features_paragraphs_info() {
  $items = array(
    'slider' => array(
      'name' => 'Slider',
      'bundle' => 'slider',
      'locked' => '1',
    ),
    'slider_item' => array(
      'name' => 'Slider Item',
      'bundle' => 'slider_item',
      'locked' => '1',
    ),
  );
  return $items;
}
