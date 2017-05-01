<?php
/**
 * @file
 * cc_text_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cc_text_features_paragraphs_info() {
  $items = array(
    'text' => array(
      'name' => 'Text',
      'bundle' => 'text',
      'locked' => '1',
    ),
  );
  return $items;
}
