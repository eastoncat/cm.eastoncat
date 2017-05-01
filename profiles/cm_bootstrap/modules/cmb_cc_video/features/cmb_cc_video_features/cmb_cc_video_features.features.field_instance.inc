<?php
/**
 * @file
 * cmb_cc_video_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cmb_cc_video_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-cmb_video-field_cc_cmb_v_video'.
  $field_instances['paragraphs_item-cmb_video-field_cc_cmb_v_video'] = array(
    'bundle' => 'cmb_video',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'full',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cc_cmb_v_video',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'mov mp4 m4a m4v mpeg avi ogg oga ogv wmv flv jpg png',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'bliptv' => 0,
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 'youtube',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 0,
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 'media_internet',
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Video');

  return $field_instances;
}
