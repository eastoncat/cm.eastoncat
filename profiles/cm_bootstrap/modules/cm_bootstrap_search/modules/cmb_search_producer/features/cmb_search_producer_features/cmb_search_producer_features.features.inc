<?php
/**
 * @file
 * cmb_search_producer_features.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cmb_search_producer_features_node_info() {
  $items = array(
    'cmbs_producer' => array(
      'name' => t('Producer'),
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
