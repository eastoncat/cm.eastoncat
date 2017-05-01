<?php
/**
 * @file
 * cmb_archive_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_archive_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_archive_features_node_info() {
  $items = array(
    'archive_content_type' => array(
      'name' => t('Archive (Content Type)'),
      'base' => 'node_content',
      'description' => t('Create archive pgs for specific content types.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'archive_node_ref' => array(
      'name' => t('Archive (Node Ref)'),
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
