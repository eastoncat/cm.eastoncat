<?php
/**
 * @file
 * cc_image_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cc_image_features_image_default_styles() {
  $styles = array();

  // Exported image style: cc_image.
  $styles['cc_image'] = array(
    'name' => 'cc_image',
    'label' => 'cc_image',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1500,
          'height' => '',
          'upscale' => 1,
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
function cc_image_features_paragraphs_info() {
  $items = array(
    'image' => array(
      'name' => 'Image',
      'bundle' => 'image',
      'locked' => '1',
    ),
  );
  return $items;
}
