<?php
/**
 * @file
 * cmb_custom_video_list_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cmb_custom_video_list_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cc_cvl_er'.
  $field_bases['field_cc_cvl_er'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cc_cvl_er',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'custom_video_list' => 'custom_video_list',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
