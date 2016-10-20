<?php
/**
 * @file
 * om_crew_connect.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function om_crew_connect_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_default_profile2_type().
 */
function om_crew_connect_default_profile2_type() {
  $items = array();
  $items['skills'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "skills",
    "label" : "Volunteer",
    "weight" : "0",
    "data" : { "registration" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
