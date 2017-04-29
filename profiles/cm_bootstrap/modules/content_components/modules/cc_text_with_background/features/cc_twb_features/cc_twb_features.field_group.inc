<?php
/**
 * @file
 * cc_twb_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cc_twb_features_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config|paragraphs_item|text_with_background|form';
  $field_group->group_name = 'group_config';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_with_background';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Config',
    'weight' => '9',
    'children' => array(
      0 => 'field_cc_twb_bg_color',
      1 => 'field_cc_twb_text_color',
      2 => 'field_cc_twb_display_mode',
      3 => 'field_cc_twb_fwidth_edge',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-config field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_config|paragraphs_item|text_with_background|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|paragraphs_item|text_with_background|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_with_background';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'field_cc_twb_text',
      1 => 'field_cc_twb_bg_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_content|paragraphs_item|text_with_background|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|paragraphs_item|text_with_background|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_with_background';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_content',
      1 => 'group_config',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_tabs|paragraphs_item|text_with_background|form'] = $field_group;

  return $export;
}
