<?php
/**
 * @file
 * cmb_search_event_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_search_event_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_search_event_features_node_info() {
  $items = array(
    'cmbs_event' => array(
      'name' => t('CMBS Event'),
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
