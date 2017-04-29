<?php

/**
 * Query All Civi Events
 */
function cmb_search_event_query_events() {
  // Get current datetime
  $current_datetime = date('Y-m-d H:i:s', time());

  $civi_events = db_query('SELECT id, title, summary, description, start_date, end_date FROM {civicrm_event} WHERE is_public = :is_public AND start_date > :current_datetime',
  array(
    ':is_public' => 1,
    ':current_datetime' => $current_datetime,
  ))->fetchAll();

  return $civi_events;
}

/**
 * Helper function to check if event node already exists
 */
function cmb_search_event_node_exists($event_id) {
  // Check if event node type exists for this user
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyCondition('type', 'cmbs_event')
    ->fieldCondition('field_cmbs_event_civi_id', 'value', $event_id, '=');
  $result = $query->execute();

  if (isset($result['node'])) {
    $nid = array_keys($result['node']);
    $nid = $nid[0];
    return $nid;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper function to update event node
 */
function cmb_search_event_update_node($event, $nid) {
  $node = node_load($nid);
  $node->title = $event->title;

  // Update fields

  // Start Date: Convert datetime to UTC
  if ($event->start_date != 'null') {
    $start_date = cmb_search_event_convert_datetime_to_ut($event->start_date);
    $node->field_cmbs_event_date[LANGUAGE_NONE][0]['value'] = $start_date;
    $node->field_cmbs_event_datetime[LANGUAGE_NONE][0]['value'] = $event->start_date;
  }

  // End Date: Convert datetime to UTC
  if ($event->end_date != 'null') {
    $end_date = cmb_search_event_convert_datetime_to_ut($event->end_date);
    $node->field_cmbs_event_date[LANGUAGE_NONE][0]['value2'] = $end_date;
    $node->field_cmbs_event_datetime[LANGUAGE_NONE][0]['value2'] = $event->end_date;
  }

  // Summary
  if ($event->summary != 'null') {
    $node->field_cmbs_event_summary[LANGUAGE_NONE][0]['value'] = $event->summary;
  }

  // Description
  if ($event->description != 'null') {
    $node->field_cmbs_event_descr[LANGUAGE_NONE][0]['value'] = $event->description;
  }

  node_save($node);
}


/**
 * Helper function to create Event node
 */
function cmb_search_event_create_node($event) {
  $node = new stdClass();
  $node->title = $event->title;
  $node->type = 'cmbs_event';
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;
  $node->uid = 1;
  $node->status = 1;
  $node->promote = 0;
  $node->comment = 0;

  // Fields
  $node->field_cmbs_event_civi_id[$node->language][]['value'] = $event->id;

  //$test = $event;

  // Start Date: Convert datetime to UTC
  if ($event->start_date != 'null') {
    //$start_date = cmb_search_event_convert_datetime_to_ut($event->start_date);
    //$node->field_cmbs_event_date[$node->language][0]['value'] = $start_date;
    $node->field_cmbs_event_datetime[$node->language][0]['value'] = $event->start_date;
  }

  // End Date: Convert datetime to UTC
  if ($event->end_date != 'null') {
    //$end_date = cmb_search_event_convert_datetime_to_ut($event->end_date);
    //$node->field_cmbs_event_date[$node->language][0]['value2'] = $end_date;
    $node->field_cmbs_event_datetime[$node->language][0]['value2'] = $event->end_date;
  }

  // Summary
  if ($event->summary != 'null') {
    $node->field_cmbs_event_summary[$node->language][]['value'] = $event->summary;
  }

  // Description
  if ($event->description != 'null') {
    $node->field_cmbs_event_descr[$node->language][]['value'] = $event->description;
  }

  $node = node_submit($node);
  node_save($node);
}

/**
 * Helper function to convert datetime to unix timestamp
 */
function cmb_search_event_convert_datetime_to_ut($date) {
  $datetime = $date;
  $dt = new DateTime($datetime);
  $dt->setTimezone(new DateTimeZone('UTC'));
  $date_utc = $dt->format('Y-m-d H:i:s');
  $date_ut = strtotime($date_utc);
  return $date_ut;
}
