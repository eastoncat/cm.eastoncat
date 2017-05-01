<?php
/**
 * @file
 * cmb_show_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_show_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_show_features_node_info() {
  $items = array(
    'cm_show' => array(
      'name' => t('Show'),
      'base' => 'node_content',
      'description' => t('<b>Community Media</b> - This content type where a Show\'s metadata is stored.  The core content type can be customize to be a digital version of the paper forms producers complete when submitting video. VOD can be added using the Media module.'),
      'has_title' => '1',
      'title_label' => t('Show Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
