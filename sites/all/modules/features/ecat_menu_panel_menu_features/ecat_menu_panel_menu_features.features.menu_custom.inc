<?php
/**
 * @file
 * ecat_menu_panel_menu_features.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ecat_menu_panel_menu_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menu-panel-menu.
  $menus['menu-menu-panel-menu'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'title' => 'Menu Panel',
    'description' => 'Used for menu in "Menu Panel" region. I.e., the menu that slide outs when the "burger" menu icon is clicked.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu Panel');
  t('Used for menu in "Menu Panel" region. I.e., the menu that slide outs when the "burger" menu icon is clicked.');

  return $menus;
}
