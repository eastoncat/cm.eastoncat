<?php
/**
 * @file
 * cmb_custom_video_list_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_custom_video_list_features_paragraphs_info() {
  $items = array(
    'custom_video_list' => array(
      'name' => 'Custom Video List',
      'bundle' => 'custom_video_list',
      'locked' => '1',
    ),
  );
  return $items;
}
