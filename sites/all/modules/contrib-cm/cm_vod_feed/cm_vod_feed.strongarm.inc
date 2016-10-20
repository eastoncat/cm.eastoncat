<?php
/**
 * @file
 * cm_vod_feed.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cm_vod_feed_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cm_vod_feed';
  $strongarm->value = 0;
  $export['comment_anonymous_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cm_vod_feed';
  $strongarm->value = '1';
  $export['comment_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cm_vod_feed';
  $strongarm->value = 1;
  $export['comment_default_mode_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cm_vod_feed';
  $strongarm->value = '50';
  $export['comment_default_per_page_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cm_vod_feed';
  $strongarm->value = 1;
  $export['comment_form_location_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cm_vod_feed';
  $strongarm->value = '1';
  $export['comment_preview_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cm_vod_feed';
  $strongarm->value = 1;
  $export['comment_subject_field_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cm_vod_feed';
  $strongarm->value = array();
  $export['menu_options_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cm_vod_feed';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cm_vod_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cm_vod_feed';
  $strongarm->value = '1';
  $export['node_preview_cm_vod_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cm_vod_feed';
  $strongarm->value = 0;
  $export['node_submitted_cm_vod_feed'] = $strongarm;

  return $export;
}
