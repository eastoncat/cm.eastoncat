<?php
/**
 * @file
 * cmb_landing_page_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cmb_landing_page_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cmb_landing_page-field_content_components'.
  $field_instances['node-cmb_landing_page-field_content_components'] = array(
    'bundle' => 'cmb_landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
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
        'cmb_block_reference' => 'cmb_block_reference',
        'cmb_jumbotron' => 'cmb_jumbotron',
        'cmb_jumbotron_item' => -1,
        'content_list' => -1,
        'content_list_item' => -1,
        'custom_video_list' => 'custom_video_list',
        'custom_video_list_context' => 'custom_video_list_context',
        'image' => -1,
        'slider' => -1,
        'slider_item' => -1,
        'text' => -1,
        'text_and_image' => -1,
        'text_with_background' => -1,
      ),
      'bundle_weights' => array(
        'cmb_block_reference' => 2,
        'cmb_jumbotron' => 3,
        'cmb_jumbotron_item' => 4,
        'content_list' => 5,
        'content_list_item' => 6,
        'custom_video_list' => 7,
        'custom_video_list_context' => 8,
        'image' => 9,
        'slider' => 10,
        'slider_item' => 11,
        'text' => 12,
        'text_and_image' => 13,
        'text_with_background' => 14,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Paragraphs');

  return $field_instances;
}
