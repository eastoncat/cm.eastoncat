<?php
/**
 * @file
 * cmb_custom_video_list_context_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function cmb_custom_video_list_context_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_paragraphs_info().
 */
function cmb_custom_video_list_context_features_paragraphs_info() {
  $items = array(
    'custom_video_list_context' => array(
      'name' => 'Custom Video List Context',
      'bundle' => 'custom_video_list_context',
      'locked' => '1',
    ),
  );
  return $items;
}
