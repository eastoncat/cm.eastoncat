<?php
/**
 * @file
 * cmb_ct_custom_video_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_ct_custom_video_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_ct_custom_video_list_node_info() {
  $items = array(
    'custom_video_list' => array(
      'name' => t('Custom Video List'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
