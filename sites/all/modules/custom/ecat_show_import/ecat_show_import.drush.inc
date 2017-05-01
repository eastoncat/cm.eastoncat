<?php

/**
 * Implements hook_drush_command().
 */
function ecat_show_import_drush_command() {
  $items['cmb-show-delete-all'] = array(
    'callback' => 'ecat_show_import_show_delete_all',
    'description' => 'Deletes all Show data including fields. Only use this for debugging.',
    'aliases' => array('cmbsda'),
  );

  return $items;
}

/**
 * Callback function.
 */
function ecat_show_import_show_delete_all() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'cm_show');
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    node_delete_multiple($nids);

    drush_print('All Show nodes and related field data deleted! Really hope you intended to do this. :/');
  }
}
