<?php
/**
 * @file
 * cm_show_vod.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function cm_show_vod_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cm_show_vod';
  $strongarm->value = array();
  $export['menu_options_cm_show_vod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cm_show_vod';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cm_show_vod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cm_show_vod';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cm_show_vod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cm_show_vod';
  $strongarm->value = '1';
  $export['node_preview_cm_show_vod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cm_show_vod';
  $strongarm->value = 0;
  $export['node_submitted_cm_show_vod'] = $strongarm;

  return $export;
}
