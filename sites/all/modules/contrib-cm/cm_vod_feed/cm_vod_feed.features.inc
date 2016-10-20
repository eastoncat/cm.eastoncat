<?php
/**
 * @file
 * cm_vod_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cm_vod_feed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cm_vod_feed_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cm_vod_feed_node_info() {
  $items = array(
    'cm_vod_feed' => array(
      'name' => t('Video on Demand Feed'),
      'base' => 'node_content',
      'description' => t('<b>Community Media</b> - This content type is used to allow different URLs to share the same MediaRSS Feed Mapper.  This can be used to add a VOD feed for different Projects.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
