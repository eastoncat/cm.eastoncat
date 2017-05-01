<?php

/**
 * Callback for module settings page.
 */
function telvue_airing_import_settings_form($form, &$form_state) {
  $form = array();

  $form['telvue_airing_import']['telvue_airing_import_xml_feed_url_1'] = array(
    '#type' => 'textfield',
    '#title' => t('XML Feed/Source URL 1'),
    '#default_value' => variable_get('telvue_airing_import_xml_feed_url_1', ''),
    '#description' => 'Set the base url from which to retrieve the airings xml feed.',
    '#size' => 120,
  );

  $form['telvue_airing_import']['telvue_airing_import_xml_feed_url_2'] = array(
    '#type' => 'textfield',
    '#title' => t('XML Feed/Source URL 2'),
    '#default_value' => variable_get('telvue_airing_import_xml_feed_url_2', ''),
    '#description' => 'Set the base url from which to retrieve the airings xml feed.',
    '#size' => 120,
  );

  $form['telvue_airing_import']['telvue_airing_import_xml_feed_url_3'] = array(
    '#type' => 'textfield',
    '#title' => t('XML Feed/Source URL 3'),
    '#default_value' => variable_get('telvue_airing_import_xml_feed_url_3', ''),
    '#description' => 'Set the base url from which to retrieve the airings xml feed.',
    '#size' => 120,
  );

  $form['telvue_airing_import']['telvue_airing_import_xml_feed_url_4'] = array(
    '#type' => 'textfield',
    '#title' => t('XML Feed/Source URL 4'),
    '#default_value' => variable_get('telvue_airing_import_xml_feed_url_4', ''),
    '#description' => 'Set the base url from which to retrieve the airings xml feed.',
    '#size' => 120,
  );

  return system_settings_form($form);
}

/**
 * Delete all Form
 */
function telvue_airing_import_delete_all_form($form, &$form_state) {
  $form['telvue_airing_import_message'] = array (
    '#type' => 'item',
    '#markup' => 'Clicking this button will delete **ALL** Airing entities and related field data.',
  );

  $form['telvue_airing_import_delete_all'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Delete all Form Submit
 */
function telvue_airing_import_delete_all_form_submit($form, &$form_state) {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'airing');
  $result = $query->execute();

  if (isset($result['airing'])) {
    $airing_ids = array_keys($result['airing']);
    // Delete all airing entities + any related field data.
    cm_airing_delete_multiple($airing_ids);

    drupal_set_message('All airings and related field data deleted! Really hope you intended to do this. :/');
  }
}
