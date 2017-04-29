<?php
/**
 * @file
 * cmb_show_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmb_show_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page1a|node|cm_show|form';
  $field_group->group_name = 'group_page1a';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_show';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Producer',
    'weight' => '16',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page1a field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page1a|node|cm_show|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Producer');

  return $field_groups;
}
