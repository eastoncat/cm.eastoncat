<?php
/**
 * @file
 * cmb_cc_block_reference_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cmb_cc_block_reference_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-cmb_block_reference-field_cmb_cc_br_bg_color'.
  $field_instances['paragraphs_item-cmb_block_reference-field_cmb_cc_br_bg_color'] = array(
    'bundle' => 'cmb_block_reference',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => 'e7e6e1',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
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
        ),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_cc_br_bg_color',
    'label' => 'Background Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(),
      'type' => 'jquery_colorpicker',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_block_reference-field_cmb_cc_br_block_reference'.
  $field_instances['paragraphs_item-cmb_block_reference-field_cmb_cc_br_block_reference'] = array(
    'bundle' => 'cmb_block_reference',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'blockreference',
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
          'show_empty_blocks' => FALSE,
        ),
        'type' => 'blockreference_default',
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
    'field_name' => 'field_cmb_cc_br_block_reference',
    'label' => 'Block Reference',
    'required' => 1,
    'settings' => array(
      'blockreference_modules' => array(
        'block' => 0,
        'calendar' => 0,
        'civicrm' => 0,
        'cm_bootstrap_archive' => 0,
        'cm_bootstrap_community' => 0,
        'cm_bootstrap_custom_blocks' => 'cm_bootstrap_custom_blocks',
        'cm_bootstrap_dropdown_menu' => 0,
        'cm_bootstrap_jumbotron' => 0,
        'devel' => 0,
        'diff' => 0,
        'fullcalendar_legend' => 0,
        'logintoboggan' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'print' => 0,
        'print_ui' => 0,
        'retn_mailchimp' => 0,
        'search' => 0,
        'system' => 0,
        'telvue_blocks' => 0,
        'user' => 0,
        'views' => 'views',
        'widgets' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-cmb_block_reference-field_cmb_cc_br_full_width'.
  $field_instances['paragraphs_item-cmb_block_reference-field_cmb_cc_br_full_width'] = array(
    'bundle' => 'cmb_block_reference',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cmb_cc_br_full_width',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Color');
  t('Block Reference');
  t('Full Width');

  return $field_instances;
}
