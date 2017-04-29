<?php
/**
 * @file
 * cc_slider_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cc_slider_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-slider-field_cc_s_items'.
  $field_instances['paragraphs_item-slider-field_cc_s_items'] = array(
    'bundle' => 'slider',
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
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_s_items',
    'label' => 'Slider Items',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'content_list' => -1,
        'content_list_item' => -1,
        'image' => -1,
        'slider' => -1,
        'slider_item' => 'slider_item',
        'text' => -1,
        'text_and_image' => -1,
      ),
      'bundle_weights' => array(
        'content_list' => 2,
        'content_list_item' => 3,
        'image' => 4,
        'slider' => 5,
        'slider_item' => 6,
        'text' => 7,
        'text_and_image' => 8,
      ),
      'default_edit_mode' => 'preview',
      'title' => 'Slider Item',
      'title_multiple' => 'Slider Items',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slider-field_cc_s_thumbnails_toggle'.
  $field_instances['paragraphs_item-slider-field_cc_s_thumbnails_toggle'] = array(
    'bundle' => 'slider',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this box to display thumbnails below the slider.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_cc_s_thumbnails_toggle',
    'label' => 'Display Thumbnails',
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

  // Exported field_instance: 'paragraphs_item-slider-field_cc_s_title'.
  $field_instances['paragraphs_item-slider-field_cc_s_title'] = array(
    'bundle' => 'slider',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_s_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slider_item-field_cc_s_item_display_mode'.
  $field_instances['paragraphs_item-slider_item-field_cc_s_item_display_mode'] = array(
    'bundle' => 'slider_item',
    'default_value' => array(
      0 => array(
        'value' => 'full_width',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select "Full Width" to have media go full width. Select "Text and Media" to have a text box next to the media.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_s_item_display_mode',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slider_item-field_cc_s_item_media'.
  $field_instances['paragraphs_item-slider_item-field_cc_s_item_media'] = array(
    'bundle' => 'slider_item',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'file_styles_thumbnail',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_s_item_media',
    'label' => 'Media',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => '',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'bliptv' => 0,
          'private' => 0,
          'public' => 'public',
          'vimeo' => 'vimeo',
          'youtube' => 'youtube',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-slider_item-field_cc_s_item_text'.
  $field_instances['paragraphs_item-slider_item-field_cc_s_item_text'] = array(
    'bundle' => 'slider_item',
    'default_value' => array(
      0 => array(
        'value' => '<p>If using "Text and Media" display mode, change this text. Otherwise just leave as is.</p>
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
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_s_item_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Check this box to display thumbnails below the slider.');
  t('Display Mode');
  t('Display Thumbnails');
  t('Media');
  t('Select "Full Width" to have media go full width. Select "Text and Media" to have a text box next to the media.');
  t('Slider Items');
  t('Text');
  t('Title');

  return $field_instances;
}
