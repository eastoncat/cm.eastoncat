<?php
/**
 * @file
 * cmb_basic_page_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cmb_basic_page_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-page-body'.
  $field_instances['node-page-body'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-page-field_content_components'.
  $field_instances['node-page-field_content_components'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content_components',
    'label' => 'Paragraphs',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'content_list' => 'content_list',
        'content_list_item' => -1,
        'custom_video_list' => 'custom_video_list',
        'custom_video_list_context' => 'custom_video_list_context',
        'image' => 'image',
        'slider' => 'slider',
        'slider_item' => -1,
        'text' => 'text',
        'text_and_image' => 'text_and_image',
        'text_with_background' => 'text_with_background',
      ),
      'bundle_weights' => array(
        'content_list' => 6,
        'content_list_item' => 7,
        'custom_video_list' => 17,
        'custom_video_list_context' => -20,
        'image' => 4,
        'slider' => 12,
        'slider_item' => 13,
        'text' => 2,
        'text_and_image' => -10,
        'text_with_background' => -16,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-page-field_full_width'.
  $field_instances['node-page-field_full_width'] = array(
    'bundle' => 'page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this box to force this page to go full width. If set to full width, even if blocks are set to appear in the sidebar, this setting will override that, and force the page to go full width, and not display the sidebar blocks.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_full_width',
    'label' => 'Full Width',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-page-field_legacy_toggle'.
  $field_instances['node-page-field_legacy_toggle'] = array(
    'bundle' => 'page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Toggle "legacy" mode ON or OFF. Use "ON" to continue using the legacy body field. Use "OFF" if page is being created with Paragraphs.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_legacy_toggle',
    'label' => 'Legacy Toggle',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Check this box to force this page to go full width. If set to full width, even if blocks are set to appear in the sidebar, this setting will override that, and force the page to go full width, and not display the sidebar blocks.');
  t('Full Width');
  t('Legacy Toggle');
  t('Paragraphs');
  t('Toggle "legacy" mode ON or OFF. Use "ON" to continue using the legacy body field. Use "OFF" if page is being created with Paragraphs.');

  return $field_instances;
}
