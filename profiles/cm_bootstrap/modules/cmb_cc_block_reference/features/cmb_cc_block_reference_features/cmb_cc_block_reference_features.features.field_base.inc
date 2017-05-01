<?php
/**
 * @file
 * cmb_cc_block_reference_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cmb_cc_block_reference_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cmb_cc_br_bg_color'.
  $field_bases['field_cmb_cc_br_bg_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cmb_cc_br_bg_color',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'jquery_colorpicker',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'jquery_colorpicker',
  );

  // Exported field_base: 'field_cmb_cc_br_block_reference'.
  $field_bases['field_cmb_cc_br_block_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cmb_cc_br_block_reference',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'moddelta' => array(
        0 => 'moddelta',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(),
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_cmb_cc_br_full_width'.
  $field_bases['field_cmb_cc_br_full_width'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cmb_cc_br_full_width',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
