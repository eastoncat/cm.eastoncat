<?php
/**
 * @file
 * cmb_blog_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cmb_blog_features_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legacy|node|blog|form';
  $field_group->group_name = 'group_legacy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Legacy',
    'weight' => '12',
    'children' => array(
      0 => 'body',
      1 => 'field_custom_video_list',
      2 => 'field_legacy_toggle',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-legacy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_legacy|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|blog|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '11',
    'children' => array(
      0 => 'field_blog_image',
      1 => 'field_content_components',
      2 => 'field_full_width',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_main|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|blog|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_main',
      1 => 'group_legacy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs|node|blog|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Legacy');
  t('Main');
  t('Tabs');

  return $field_groups;
}
