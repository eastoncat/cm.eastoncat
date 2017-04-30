<?php

// Get media module version
$media_module = system_get_info($type = 'module', $name = 'media');

define('CMB_MEDIA_MODULE_VER', $media_module['version']);

/**
 * Form constructor
 */
function cm_bootstrap_cp_default_images_form($form, &$form_state) {
  // Get media module version
  $media_module = system_get_info($type = 'module', $name = 'media');
  $media_module_ver = $media_module['version'];

  $content_types = array(
    'cm_show',
    'cm_project',
    'article',
  );

  foreach($content_types as $content_type) {
    $form[$content_type] = array(
      '#type' => 'fieldset',
      '#title' => t($content_type),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      // Need to add this, otherwise form values will not be keyed by content type name.
      '#tree' => TRUE,
    );
    $form[$content_type]['content_type'] = array(
      '#type' => 'hidden',
      '#title' => t('Content Type'),
      '#size' => 5,
      '#default_value' => $content_type,
    );
    $form[$content_type]['default_image'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t($content_type . ': Default Image'),
      '#description' => t('Allowed file types: gif png jpg jpeg <br /> Image should be at least 780px wide x 495px high.'),
      // Needed for Media 7.x-2.0-beta14 (ECAT)
      '#theme' => 'media_widget',
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'gif png jpg jpeg',
          'max_filesize' => '3 MB',
          'types' => array('image'),
        ),
      ),
    );
    $fid = cm_bootstrap_cp_default_images_default_value($content_type);
    // Add logic to account for different versions of media module
    // For Media 2.x it simply is '#default_value => $my_fid,, no array anymore.
    if (CMB_MEDIA_MODULE_VER == '7.x-2.0-beta1'
    || CMB_MEDIA_MODULE_VER == '7.x-2.0-alpha4'
    || CMB_MEDIA_MODULE_VER == '7.x-2.0-beta14') {
      $form[$content_type]['default_image']['#default_value'] = $fid;
    }
    else {
      $form[$content_type]['default_image']['#default_value'] = array('fid' => cm_bootstrap_cp_default_images_default_value($content_type));
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

/**
 * Form submit
 */
function cm_bootstrap_cp_default_images_form_submit($form, &$form_state) {
  //dpm($form_state);
  // @todo do this as a foreach loop so you can easily add content types
  $content_types = array(
    'cm_show',
    'cm_project',
    'article',
  );
  foreach($content_types as $content_type) {
    // Add logic to account for different versions of media module
    if (CMB_MEDIA_MODULE_VER == '7.x-2.0-beta1'
    || CMB_MEDIA_MODULE_VER == '7.x-2.0-alpha4'
    || CMB_MEDIA_MODULE_VER == '7.x-2.0-beta14') {
      $data = array(
        'content_type' => $content_type,
        'fid' => $form_state['values'][$content_type]['default_image'],
      );
    }
    else {
      $data = array(
        'content_type' => $content_type,
        'fid' => $form_state['values'][$content_type]['default_image']['fid'],
      );
    }
    // Write data to database
    $update_record = db_query('SELECT content_type FROM {cm_bootstrap_cp_default_images} WHERE content_type = :content_type',
      array(
        ':content_type' => $content_type,
      ))->fetchField();
      // Update record.
      if ($update_record) {
        drupal_write_record('cm_bootstrap_cp_default_images', $data, array('content_type'));
      }
      // Create new record.
      else {
        drupal_write_record('cm_bootstrap_cp_default_images', $data);
      }
  }

  // Add logic to account for different versions of media module
  if (CMB_MEDIA_MODULE_VER == '7.x-2.0-beta1'
  || CMB_MEDIA_MODULE_VER == '7.x-2.0-alpha4'
  || CMB_MEDIA_MODULE_VER == '7.x-2.0-beta14') {
    // Show
    $show_data = array(
      'content_type' => 'cm_show',
      'fid' => $form_state['values']['cm_show']['default_image'],
    );
    // Series
    $series_data = array(
      'content_type' => 'cm_project',
      'fid' => $form_state['values']['cm_project']['default_image'],
    );
  }
  else {
    // Show
    $show_data = array(
      'content_type' => 'cm_show',
      'fid' => $form_state['values']['cm_show']['default_image']['fid'],
    );
    // Series
    $series_data = array(
      'content_type' => 'cm_project',
      'fid' => $form_state['values']['cm_project']['default_image']['fid'],
    );
  }

}

/**
 * Helper function to get default values for form.
 */
function cm_bootstrap_cp_default_images_default_value($content_type) {
  $default_value = db_query('SELECT fid FROM {cm_bootstrap_cp_default_images} WHERE content_type = :content_type',
    array(
      ':content_type' => $content_type,
    ))->fetchField();
  return $default_value;
}
