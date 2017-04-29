<?php

/**
 * Implements hook_drush_command().
 */
function ecat_series_import_drush_command() {
  $items['cmb-series-delete-all'] = array(
    'callback' => 'ecat_series_import_series_delete_all',
    'description' => 'Deletes all Series data including fields. Only use this for debugging.',
    'aliases' => array('cmbserda'),
  );

  return $items;
}

/**
 * Callback function.
 */
function ecat_series_import_series_delete_all() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'cm_project');
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    node_delete_multiple($nids);

    drush_print('All Series nodes and related field data deleted! Really hope you intended to do this. :/');
  }
}
