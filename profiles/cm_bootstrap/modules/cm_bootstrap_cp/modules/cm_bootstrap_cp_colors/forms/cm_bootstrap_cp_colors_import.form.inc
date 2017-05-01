<?php

/**
 * Form constructor
 */
function cm_bootstrap_cp_colors_import_form($form, &$form_state) { 
  $form['file'] = array(
    '#type' => 'file',
    '#title' => t('Upload CSV Colors file'),
    '#description' => t('.csv upload for colors'),
  );  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Import Colors',
  );
  return $form;
}

/**
 * Form validate
 */
function cm_bootstrap_cp_colors_import_form_validate($form, &$form_state) {
  $file = file_save_upload('file', array(
    'file_validate_extensions' => array('csv'), // Validate extensions.
    FILE_EXISTS_REPLACE
  ));
  // If the file passed validation:
  if ($file) {
    // Move the file, into the Drupal file system
    if ($file = file_move($file, 'public://')) {
      // Save the file for use in the submit handler.
      $form_state['values']['file'] = $file;
    }
    else {
      form_set_error('file', t('Failed to write the uploaded file the site\'s file folder.'));
    }
  }
  else {
    form_set_error('file', t('No file was uploaded.'));
  }
}

/**
 * Form submit
 */
function cm_bootstrap_cp_colors_import_form_submit($form, &$form_state) {
  $file_object = $form_state['values']['file'];    
  $csv = cm_bootstrap_cp_colors_import_csv_to_array( drupal_realpath($file_object->uri) );
  //dpm($csv);
  foreach($csv[0] as $key => $value) {
    $data = array(
      'name' => $key,
      'value' => $value,
    );      
    //dpm($data);          
    // Check if the record exists, to determine if it's a new record or an update.
    $update_record = db_query('SELECT name FROM {cmb_cp_colors} WHERE name = :name', 
      array(
        ':name' => $data['name'],
      ))->fetchField();
    // Update record.
    if ($update_record) {
      drupal_write_record('cmb_cp_colors', $data, array('name'));
    } 
    // Create new record.
    else {
      drupal_write_record('cmb_cp_colors', $data);
    }
  }
}

/**
 * Converts CSV file into php array
 */
function cm_bootstrap_cp_colors_import_csv_to_array($file) {
  $rows = array();
  $headers = array();
  if (file_exists($file) && is_readable($file)) {
    $handle = fopen($file, 'r');
    while (!feof($handle)) {
      $row = fgetcsv($handle, 10240, ',', '"');
      if (empty($headers))
        $headers = $row;
      else if (is_array($row)) {
        array_splice($row, count($headers));
        $rows[] = array_combine($headers, $row);
      }
    }
    fclose($handle);
  } 
  else {
    throw new Exception($file . ' doesn`t exist or is not readable.');
  }
  return $rows;
}