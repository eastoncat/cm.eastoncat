<?php
/**
 * @file
 * cm_bootstrap_search_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cm_bootstrap_search_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-solr_search-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'solr_search-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'cm_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'cm_admin',
        'weight' => 0,
      ),
      'cmb_theme' => array(
        'region' => 'search_overlay',
        'status' => 1,
        'theme' => 'cmb_theme',
        'weight' => -57,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
