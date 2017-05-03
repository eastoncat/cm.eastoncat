<?php
/**
 * @file
 * telvue_airing_import_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function telvue_airing_import_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'airing-airing-field_airing_guid'.
  $field_instances['airing-airing-field_airing_guid'] = array(
    'bundle' => 'airing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'airing',
    'field_name' => 'field_airing_guid',
    'label' => 'GUID',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'airing-airing-field_no_reference_project'.
  $field_instances['airing-airing-field_no_reference_project'] = array(
    'bundle' => 'airing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'airing',
    'field_name' => 'field_no_reference_project',
    'label' => 'No Reference Series',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'airing-airing-field_no_reference_show'.
  $field_instances['airing-airing-field_no_reference_show'] = array(
    'bundle' => 'airing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'airing',
    'field_name' => 'field_no_reference_show',
    'label' => 'No Reference Show',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('GUID');
  t('No Reference Series');
  t('No Reference Show');

  return $field_instances;
}
