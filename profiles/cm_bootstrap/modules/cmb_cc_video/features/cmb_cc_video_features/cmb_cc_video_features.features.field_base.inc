<?php
/**
 * @file
 * cmb_cc_video_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cmb_cc_video_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cc_cmb_v_video'.
  $field_bases['field_cc_cmb_v_video'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cmb_v_video',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'field_permissions' => array(
        'create' => 0,
        'edit' => 0,
        'edit own' => 0,
        'view' => 'view',
        'view own' => 'view own',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
