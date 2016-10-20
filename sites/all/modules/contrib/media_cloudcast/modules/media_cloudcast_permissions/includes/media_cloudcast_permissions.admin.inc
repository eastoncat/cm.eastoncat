<?php

/**
 * @file
 * This file contains the admin functions for the Media: Cloudcast module.
 */

/**
 * The default viewable status for video types in the Media Cloudcast.
 */
define('MEDIACLOUDCAST_VIEWABLE_DEFAULT', 1);

/**
 * The default display method for video types in the Media Cloudcast.
 */
define('MEDIACLOUDCAST_DISPLAY_DEFAULT', 0);

/**
 * The video field name used in the Media Cloudcast.
 */
define('MEDIACLOUDCAST_FIELD_AVAILABLE', 'cloudcast_field_available');


function media_cloudcast_permissions_get_field_instance($bundle, $entity = 'node') {
  return $field_instance = array(
    'field_name'=> MEDIACLOUDCAST_FIELD_AVAILABLE,
    'entity_type'=> $entity,
    'bundle'=> $bundle,
    'label'=> t('Video is available'),
    'description'=> t(''),
    'widget'=> array(
      'type'=> 'options_onoff',
      'weight'=> 10,
      'module' => 'options',
      'active' => 1,
      'settings'=> array(
        'display_label' => 1,
      ),
    ),
    'formatter'=> array(
      'label'=> t('Video is available'),
      'format'=> 'options_onoff'
    ),
    'settings'=> array(
      'user_register_form' => FALSE,
    ),
    'default_value' => array(
      array('value' => 0),
    ),
  );
}

/**
 * Admin configruation form for media browser settings.
 */
function media_cloudcast_permissions_admin_config($form, &$form_state) {
  $form['media_cloudcast_permissions_video_access'] = array(
    '#type' => 'checkbox',
    '#title' => t('Manually control whether a video is available'),
    '#description' => t('If you have checked the box to manually control when a video is available, then you need to also add this field to the content type(s) that your video is connected to. Check the appropriate content types below that you want this field applied to. Then, upon adding a new video, you will need to check/uncheck the available box.'),
    '#default_value' => variable_get('media_cloudcast_permissions_video_access', 0),
  );

  $options = node_type_get_names();

  $form['media_cloudcast_permissions_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' => $options,
    '#default_value' => variable_get('media_cloudcast_permissions_node_types', '') ? variable_get('media_cloudcast_permissions_node_types', '') : array_keys($options),
  );

  $form['media_cloudcast_permissions_add'] = array(
    '#type' => 'submit',
    '#value' => t('Add manual checkbox to content types'),
    '#weight' => 19,
    '#submit' => array('media_cloudcast_permissions_create_field_submit'),
  );
  $form['media_cloudcast_permissions_remove'] = array(
    '#type' => 'submit',
    '#value' => t('Remove manual checkbox from content types'),
    '#weight' => 20,
    '#submit' => array('media_cloudcast_permissions_remove_field_submit'),
  );

  return system_settings_form($form);
}

function media_cloudcast_permissions_create_field_submit(&$form, &$form_state) {

  // check if the field already exists.
  if (!field_info_field(MEDIACLOUDCAST_FIELD_AVAILABLE)) {
    $field = array(
      'field_name' => MEDIACLOUDCAST_FIELD_AVAILABLE,
      'type' => 'list_boolean',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_test' => array(
                'value' => 'field_test_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_test' => array(
                'value' => 'field_test_value',
              ),
            ),
          ),
        ),
      ),
    );
    field_create_field($field);
  }

  $node_types = array_filter($form_state['values']['media_cloudcast_permissions_node_types']);

  foreach ($node_types as $key => $bundle) {
    $prior_instance = field_info_instance('node', MEDIACLOUDCAST_FIELD_AVAILABLE, $bundle);

    if (empty($prior_instance)) {
      $field_instance = media_cloudcast_permissions_get_field_instance($bundle);

      $instance = field_create_instance($field_instance);
      drupal_set_message(t('Field "%field" added to %bundle.', array('%field' => MEDIACLOUDCAST_FIELD_AVAILABLE, '%bundle' => $bundle)));
    }
    else {
      drupal_set_message(t('Field "%field" already existed in %bundle.', array('%field' => MEDIACLOUDCAST_FIELD_AVAILABLE, '%bundle' => $bundle)), 'error');
    }
  }
}

function media_cloudcast_permissions_remove_field_submit(&$form, &$form_state) {
  $node_types = array_filter($form_state['values']['media_cloudcast_permissions_node_types']);

  foreach ($node_types as $key => $bundle) {
    $field_instance = media_cloudcast_permissions_get_field_instance($bundle);

    field_delete_instance($field_instance, TRUE);
    drupal_set_message(t('Field "%field" has been removed from %bundle.', array('%field' => MEDIACLOUDCAST_FIELD_AVAILABLE, '%bundle' => $bundle)));
  }
}

/**
 * Add the video options to the content type form.
 *
 * Caller is responsible for ensuring media_cloudcast_permissions_bundle_settings_save()
 * is called during submission.
 */
function media_cloudcast_permissions_add_bundle_settings(array &$form, array &$form_state, $entity, $bundle) {
  $entity_info = media_cloudcast_permissions_get_video_info($entity);

  if (!isset($bundle) && isset($entity_info['bundle keys']['bundle'])) {
   $bundle_key = $entity_info['bundle keys']['bundle'];
   if (isset($form[$bundle_key]['#value'])) {
     $bundle = $form[$bundle_key]['#value'];
   }
   elseif (isset($form[$bundle_key]['#default_value'])) {
     $bundle = $form[$bundle_key]['#default_value'];
   }
  }

  $bundle_info = media_cloudcast_permissions_bundle_load($entity, $bundle);
  $video_info = $bundle_info['info']['media_cloudcast_permissions'];

  $form['media_cloudcast_permissions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Media Cloudcast settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#access' => user_access('administer media cloudcast'),
    '#group' => 'additional_settings',
    '#attached' => array(
      'js' => array(
        'vertical-tabs' => drupal_get_path('module', 'media_cloudcast_permissions') . '/js/media_cloudcast_permissions.verticaltabs.js',
      ),
    ),
    '#tree' => TRUE,
    '#entity' => $entity,
    '#bundle' => $bundle,
    '#entity_info' => $entity_info,
    '#bundle_info' => $bundle_info,
  );

  // Hack to remove fieldset summary if Vertical tabs is not enabled.
  if (!isset($form['additional_settings'])) {
    unset($form['media_cloudcast_permissions']['#attached']['js']['vertical-tabs']);
  }

  $form['media_cloudcast_permissions']['viewable'] = array(
    '#type' => 'select',
    '#title' => t('By default all videos should be'),
    '#options' => array(
      1 => 'viewable',
      0 => 'not viewable',
    ),
    '#default_value' => $video_info['viewable'],
  );
  $form['media_cloudcast_permissions']['display'] = array(
    '#type' => 'select',
    '#title' => t('When a video is not viewable'),
    '#options' => array(
      0 => 'hide the field',
      1 => 'show thumbnail',
    ),
    '#default_value' => $video_info['display'],
    '#states' => array(
      'invisible' => array(
        'select[name="media_cloudcast_permissions[viewable]"]' => array('value' => '1'),
      ),
    ),
  );

  $form += array('#submit' => array());
  array_unshift($form['#submit'], 'media_cloudcast_permissions_bundle_settings_form_submit');

  if (isset($form['submit'])) {
    $form['submit'] += array('#weight' => 40);
  }
  if (isset($form['delete'])) {
    $form['delete'] += array('#weight' => 50);
  }
}

function media_cloudcast_permissions_bundle_settings_form_submit($form, &$form_state) {
  $entity = $form['media_cloudcast_permissions']['#entity'];
  $bundle = $form['media_cloudcast_permissions']['#bundle'];

  // Handle new bundles by fetching the proper bundle key value from the form
  // state values.
  if (empty($bundle)) {
    $entity_info = $form['media_cloudcast_permissions']['#entity_info'];
    if (isset($entity_info['bundle keys']['bundle'])) {
      $bundle_key = $entity_info['bundle keys']['bundle'];
      if (isset($form_state['values'][$bundle_key])) {
        $bundle = $form_state['values'][$bundle_key];
        $form['media_cloudcast_permissions']['#bundle'] = $bundle;
      }
    }
  }

  media_cloudcast_permissions_bundle_settings_save($entity, $bundle, $form_state['values']['media_cloudcast_permissions']);

  $entity_info = $form['media_cloudcast_permissions']['#entity_info'];
  drupal_set_message(t('Media Cloudcast settings for the %bundle have been saved.', array('%bundle' => $entity_info['bundles'][$bundle]['label'])));

  // Unset the form values since we have already saved the bundle settings and
  // we don't want these values to get saved as variables in-case this form
  // also uses system_settings_form().
  unset($form_state['values']['media_cloudcast_permissions']);
}

function media_cloudcast_permissions_bundle_settings_save($entity, $bundle, $settings) {
  variable_set("media_cloudcast_permissions_settings_{$entity}_{$bundle}", $settings);
  cache_clear_all('media_cloudcast_permissions:video_info:', 'cache', TRUE);
  //media_cloudcast_permissions_get_video_info(NULL, TRUE);
}

/**
 * Returns information about supported Cloudcast video types.
 *
 * @param $type
 *   (optional) The video type to return information for. If omitted,
 *   information for all video types is returned.
 * @param $reset
 *   (optional) Boolean whether to reset the static cache and do nothing. Only
 *   used for tests.
 */
function media_cloudcast_permissions_get_video_info($type = NULL, $reset = FALSE) {
  global $language;
  $video_info = &drupal_static(__FUNCTION__);

  if ($reset) {
    $video_info = NULL;
    cache_clear_all('media_cloudcast_permissions:video_info:', 'cache', TRUE);
  }

  if (!isset($video_info)) {
    $cid = 'media_cloudcast_permissions:video_info:' . $language->language;
    if ($cache = cache_get($cid)) {
      $video_info = $cache->data;
    }
    else {
      entity_info_cache_clear();
      $video_info = entity_get_info();

      $video_info = array_merge($video_info, module_invoke_all('media_cloudcast_permissions_video_info'));

      foreach ($video_info as $key => &$info) {
        $info += array(
          'type' => $key,
          'base table' => FALSE,
          'bundles' => array(),
          'media_cloudcast_permissions' => array(),
        );
        foreach ($info['bundles'] as $bundle => &$bundle_info) {
          $bundle_info += array(
            'media_cloudcast_permissions' => array(),
          );
          $bundle_info['media_cloudcast_permissions'] += media_cloudcast_permissions_bundle_load($key, $bundle, FALSE);
        }
      }

      drupal_alter('media_cloudcast_permissions_video_info', $video_info);
      ksort($video_info);
      // Cache by language since this info contains translated strings.
      cache_set($cid, $video_info);
    }
  }

  if (isset($type)) {
    return isset($video_info[$type]) ? $video_info[$type] : NULL;
  }

  return $video_info;
}

function media_cloudcast_permissions_bundle_load($entity, $bundle, $load_bundle_info = TRUE) {
  $info = array(
    'entity' => $entity,
    'bundle' => $bundle,
  );
  if ($load_bundle_info) {
    $entity_info = media_cloudcast_permissions_get_video_info($entity);
    if (isset($entity_info['bundles'][$bundle])) {
      $info['info'] = $entity_info['bundles'][$bundle];
    }
  }

  $info += variable_get("media_cloudcast_permissions_settings_{$entity}_{$bundle}", array());
  $info += array(
    'viewable' => MEDIACLOUDCAST_VIEWABLE_DEFAULT,
    'display' => MEDIACLOUDCAST_DISPLAY_DEFAULT,
  );

  return $info;
}
