<?php
/**
 * @file
 * cc_twb_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cc_twb_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_bg_color'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_bg_color'] = array(
    'bundle' => 'text_with_background',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Leave blank for default color.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_bg_color',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_bg_image'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_bg_image'] = array(
    'bundle' => 'text_with_background',
    'deleted' => 0,
    'description' => 'Leave blank for no background image.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'teaser',
        ),
        'type' => 'file_rendered',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_bg_image',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_display_mode'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_display_mode'] = array(
    'bundle' => 'text_with_background',
    'default_value' => array(
      0 => array(
        'value' => 'bg_color',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a display mode.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_display_mode',
    'label' => 'Display Mode',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_fwidth_edge'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_fwidth_edge'] = array(
    'bundle' => 'text_with_background',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this box for full width, edge to edge.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_fwidth_edge',
    'label' => 'Full Width (Edge to Edge)',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_text'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_text'] = array(
    'bundle' => 'text_with_background',
    'default_value' => array(
      0 => array(
        'value' => '<p>Replace this text.</p>
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
        'module' => 'text',
        'settings' => array(
          'trim_length' => 125,
        ),
        'type' => 'text_trimmed',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_text',
    'label' => 'Text',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text_with_background-field_cc_twb_text_color'
  $field_instances['paragraphs_item-text_with_background-field_cc_twb_text_color'] = array(
    'bundle' => 'text_with_background',
    'default_value' => array(
      0 => array(
        'jquery_colorpicker' => '000000',
      ),
    ),
    'deleted' => 0,
    'description' => 'Leave blank for default color.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'jquery_colorpicker',
        'settings' => array(),
        'type' => 'jquery_colorpicker_color_display',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_twb_text_color',
    'label' => 'Text Color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'jquery_colorpicker',
      'settings' => array(),
      'type' => 'jquery_colorpicker',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Color');
  t('Background Image');
  t('Check this box for full width, edge to edge.');
  t('Display Mode');
  t('Full Width (Edge to Edge)');
  t('Leave blank for default color.');
  t('Leave blank for no background image.');
  t('Select a display mode.');
  t('Text');
  t('Text Color');

  return $field_instances;
}
