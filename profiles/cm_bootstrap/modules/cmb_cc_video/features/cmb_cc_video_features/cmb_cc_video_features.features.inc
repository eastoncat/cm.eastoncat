<?php
/**
 * @file
 * cmb_cc_video_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_cc_video_features_paragraphs_info() {
  $items = array(
    'cmb_video' => array(
      'name' => 'Video',
      'bundle' => 'cmb_video',
      'locked' => '1',
    ),
  );
  return $items;
}
