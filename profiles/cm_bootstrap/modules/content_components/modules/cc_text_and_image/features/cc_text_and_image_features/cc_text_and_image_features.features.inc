<?php
/**
 * @file
 * cc_text_and_image_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cc_text_and_image_features_paragraphs_info() {
  $items = array(
    'text_and_image' => array(
      'name' => 'Text and Image',
      'bundle' => 'text_and_image',
      'locked' => '1',
    ),
  );
  return $items;
}
