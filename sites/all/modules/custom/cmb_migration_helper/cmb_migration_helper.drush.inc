<?php

/**
 * Implements hook_drush_command().
 */
function cmb_migration_helper_drush_command() {
  $items['cmb-module-check'] = array(
    'callback' => 'cmb_migration_helper_module_check',
    'description' => 'Enable/Disable Modules.',
    'aliases' => array('cmbmc'),
  );

  return $items;
}

/**
 * Callback function to enable/disable modules
 */
function cmb_migration_helper_module_check() {
  // Clear all cache
  drush_invoke($command = 'cc', $arguments = array('all'));

  // Modules to disable.
  $disabled_modules = array(
    'overlay',
    'fitvids',
    'toolbar',
    'environment_indicator',
    'telvue_push',
    'cm_vod_feed',
    'cm_vod_feed_cloudcast_lookup',
    'cm_vod_feed_youtube_lookup',
    'headerimage',
    'cm_header',
    'css_injector',
    'workbench',
    'workbench_moderation',
    'flexslider',
    'wysiwyg',
  );

  // Disable
  module_disable($disabled_modules, $disable_dependents = TRUE);


  // Modules to enable.
  $enable_modules = array(
    'admin_menu',
    'admin_menu_toolbar',
    'metatag',
    'paragraphs',
    'smart_trim',
    'advanced_link',
    'search_api',
    'search_api_views',
    'search_api_solr',
    'views_ef_fieldset',
    'ckeditor',
    //'features_extra',
    'features_diff',
    'diff',
    'elysia_cron',
    'contextual',
    'cmb_helper',
    'cmb_show',
    'cmb_show_features',
    'ecat_show_import',
    'cm_bootstrap_custom_blocks',
    'cm_bootstrap_community',
    'cm_bootstrap_cp',
    'cm_bootstrap_cp_default_images',
    'cm_bootstrap_cp_colors',
    'media_cc_chapters',
    'socialmedia',
    'widgets',
    'ecat_helper',
  );

  module_enable($enable_modules, TRUE);

  // Disable blocks
  cmb_migration_helper_disable_block($module = 'system', $delta = 'navigation');
  cmb_migration_helper_disable_block($module = 'system', $delta = 'user-menu');
  cmb_migration_helper_disable_block($module = 'system', $delta = 'main-menu');
  cmb_migration_helper_disable_block($module = 'menu_block', $delta = '13');
  cmb_migration_helper_disable_block($module = 'block', $delta = '9');
  cmb_migration_helper_disable_block($module = 'block', $delta = '12');
  cmb_migration_helper_disable_block($module = 'book', $delta = 'navigation');

  // Global disable Elysia cron for now
  variable_set('elysia_cron_disabled', 1);

  // Return unhelpful, very generic message.
  drush_print('CMB Modules check done 2!');
}

/**
 * Helper function to disable blocks.
 */
function cmb_migration_helper_disable_block($module, $delta) {
  $query = db_update('block')
    ->fields([
    'status' => 0,
  ])
  //->condition('theme', 'your_theme')
  ->condition('module', $module)
  ->condition('delta', $delta)
  ->execute();
}
