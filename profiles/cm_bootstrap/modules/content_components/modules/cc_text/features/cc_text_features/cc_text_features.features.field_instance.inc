<?php
/**
 * @file
 * cc_text_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cc_text_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-text-field_cc_text_paragraph'
  $field_instances['paragraphs_item-text-field_cc_text_paragraph'] = array(
    'bundle' => 'text',
    'default_value' => array(
      0 => array(
        'value' => '<p>Replace this text with your content.</p>
',
        'format' => 'cc_text_paragraph',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_text_paragraph',
    'label' => 'Text Paragraph',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Text Paragraph');

  return $field_instances;
}
