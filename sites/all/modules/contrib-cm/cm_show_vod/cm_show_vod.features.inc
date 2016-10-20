<?php
/**
 * @file
 * cm_show_vod.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cm_show_vod_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

