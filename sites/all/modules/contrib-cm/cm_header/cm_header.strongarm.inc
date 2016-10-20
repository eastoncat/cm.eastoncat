<?php
/**
 * @file
 * cm_header.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cm_header_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'headerimage_block_1_random_fallback';
  $strongarm->value = 0;
  $export['headerimage_block_1_random_fallback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'headerimage_condition_types';
  $strongarm->value = array(
    'nid' => 'nid',
    'url' => 'url',
    'nodetype' => 'nodetype',
    'taxonomy' => 0,
    'book' => 0,
    'php' => 0,
  );
  $export['headerimage_condition_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'headerimage_node_type';
  $strongarm->value = array(
    'cm_header' => 'cm_header',
    'board_agendas' => 0,
    'cm_project' => 0,
    'cm_show_vod' => 0,
    'cm_slideshow_slide' => 0,
    'cm_vod_feed' => 0,
    'article' => 0,
    'ca_resource' => 0,
    'page' => 0,
  );
  $export['headerimage_node_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'headerimage_teaser';
  $strongarm->value = 0;
  $export['headerimage_teaser'] = $strongarm;

  return $export;
}
