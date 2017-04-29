<?php
/**
 * @file
 * cmb_landing_page_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_landing_page_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_landing_page_features_node_info() {
  $items = array(
    'cmb_landing_page' => array(
      'name' => t('CMB Landing Page'),
      'base' => 'node_content',
      'description' => t('CMB Landing Page content type. Used mainly for homepage, but can be used for other pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
