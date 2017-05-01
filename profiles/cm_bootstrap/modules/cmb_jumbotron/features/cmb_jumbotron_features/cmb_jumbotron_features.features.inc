<?php
/**
 * @file
 * cmb_jumbotron_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cmb_jumbotron_features_image_default_styles() {
  $styles = array();

  // Exported image style: cmb_jumbotron_slide.
  $styles['cmb_jumbotron_slide'] = array(
    'label' => 'cmb_jumbotron_slide',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1440,
          'height' => 720,
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
function cmb_jumbotron_features_paragraphs_info() {
  $items = array(
    'cmb_jumbotron' => array(
      'name' => 'CMB Jumbotron',
      'bundle' => 'cmb_jumbotron',
      'locked' => '1',
    ),
    'cmb_jumbotron_item' => array(
      'name' => 'Jumbotron Item',
      'bundle' => 'cmb_jumbotron_item',
      'locked' => '1',
    ),
  );
  return $items;
}
