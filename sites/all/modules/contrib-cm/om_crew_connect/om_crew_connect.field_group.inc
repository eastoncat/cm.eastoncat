<?php
/**
 * @file
 * om_crew_connect.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function om_crew_connect_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills|profile2|skills|form';
  $field_group->group_name = 'group_skills';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'skills';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '2',
    'children' => array(
      0 => 'field_skill_camera',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please rate yourself in the following skills.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_skills|profile2|skills|form'] = $field_group;

  return $export;
}
