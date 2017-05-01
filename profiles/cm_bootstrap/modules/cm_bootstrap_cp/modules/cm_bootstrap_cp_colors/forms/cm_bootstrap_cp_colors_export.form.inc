<?php

/**
 * Form constructor
 */
function cm_bootstrap_cp_colors_export_form($form, &$form_state) { 
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Export Colors',
  );
  return $form;
}

/**
 * Form submit
 */
function cm_bootstrap_cp_colors_export_form_submit($form, &$form_state) {  
  // @todo fix php warnings, even though they don't matter right now.
  // Headers
  drupal_add_http_header("Cache-Control: public");
  drupal_add_http_header("Content-Type: application/octet-stream");
  drupal_add_http_header("Cache-Control: no-store, no-cache, must-revalidate");
  drupal_add_http_header("Cache-Control: post-check=0, pre-check=0");
  drupal_add_http_header('Content-Disposition', 'attachment; filename = colors-expost.csv');
  drupal_add_http_header("Content-Transfer-Encoding: binary");

  $output = fopen('php://output', 'w');  
  // Get colors from database      
  $colors = cm_bootstrap_cp_colors_get();
  // Set column field headings
  foreach($colors as $key => $color) {
    $keys[] = $key;
  }
  fputcsv($output, $keys); 
  // Set color values
  foreach($colors as $key => $color) {
    $color_values[] = $color;   
  }
  fputcsv($output, $color_values);
  fclose($output);
  drupal_exit();
}