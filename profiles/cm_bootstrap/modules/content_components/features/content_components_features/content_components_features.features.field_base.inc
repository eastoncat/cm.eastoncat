<?php
/**
 * @file
 * content_components_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_components_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_content_components'
  $field_bases['field_content_components'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_content_components',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
