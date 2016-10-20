<?php
/**
 * @file
 * om_crew_connect.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function om_crew_connect_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_from_mail_om_crew_connect_find:om_crew_connect_find';
  $strongarm->value = 'kreynen+git7@gmail.com';
  $export['views_send_from_mail_om_crew_connect_find:om_crew_connect_find'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_from_name_om_crew_connect_find:om_crew_connect_find';
  $strongarm->value = 'admin';
  $export['views_send_from_name_om_crew_connect_find:om_crew_connect_find'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_om_crew_connect_find:om_crew_connect_find';
  $strongarm->value = 'Looking for Volunteers for My Project';
  $export['views_send_subject_om_crew_connect_find:om_crew_connect_find'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_om_crew_connect_find:om_crew_connect_find';
  $strongarm->value = 'users_profile_mail';
  $export['views_send_to_mail_om_crew_connect_find:om_crew_connect_find'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_om_crew_connect_find:om_crew_connect_find';
  $strongarm->value = 'users_profile_name';
  $export['views_send_to_name_om_crew_connect_find:om_crew_connect_find'] = $strongarm;

  return $export;
}
