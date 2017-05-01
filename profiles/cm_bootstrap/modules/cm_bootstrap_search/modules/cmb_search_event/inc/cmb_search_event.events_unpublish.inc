<?php

// Get all expired events and set to unpublished.
function _cmb_search_event_events_unpublish() {
  $current_datetime = date('Y-m-d H:i:s', time());

  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyCondition('type', 'cmbs_event')
    ->fieldCondition('field_cmbs_event_datetime', 'value', $current_datetime, '<=');
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);

    foreach ($nodes as $node) {
      // Unpublish node
      // @todo probably change this to more specific logic?
      $node->status = 0;
      node_save($node);
    }
  }
}
