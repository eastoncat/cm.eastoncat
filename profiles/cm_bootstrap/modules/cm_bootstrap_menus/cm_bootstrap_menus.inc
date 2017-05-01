<?php

/**
 * 'Navigation Menu' install function
 */
function cm_bootstrap_menus_install_navigation_menu() {
  // Navigation menu
  // Menu placed in the top right of the top navigation.
  // Typical links would be, Log In/Log Out, Burger Menu, etc.
  $navigation_menu = array(
    'menu_name' => 'navigation-menu',
    'title' => 'CMB Navigation Menu',
    'description' => 'Navigation menu. [Menu placed in top right of top navigation, i.e., Login/Logout, Burger Menu, etc.',
  );
  menu_save($navigation_menu);

  // Programmatically place menu block in region
  //
  // This technically runs before the menu block is created,
  // but by the time the module is enabled, the menu block config
  // is already created, so it doesn't matter.
  if (menu_load('navigation-menu')) {
    //if (module_exists('cm_bootstrap_modules') && cm_bootstrap_modules_theme_exists('cm_bootstrap') ) {
      // Check if menu block already exists
      $menu_block_delta = 'cmb-navigation-menu-block';
      $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

      if (!$menu_block_exists) {
        // Place menu block programmatically
        $menu_block = array(
          'module' => 'menu_block',
          'delta' => 'cmb-navigation-menu-block',
          'theme' => 'cmb_theme',
          'status' => 1,
          'weight' => 0,
          'region' => 'navigation',
          'custom' => 0,
          'visibility' => 0,
          'pages' => '',
          'title' => '<none>',
        );
        drupal_write_record('block', $menu_block);
      }

    //}
  }

  // Programmatically create menu links
  $menu_item = array(
    'link_title' => 'Menu',
    'link_path' => '<front>',
    'menu_name' => 'navigation-menu',
    'weight' => 1,
    'plid' => 0,
    'options' => array(
      'attributes' => array(
        'class' => array('menu-panel-trigger'),
      ),
    ),
  );
  menu_link_save($menu_item);

  // Clear menu cache
  cache_clear_all('*', 'cache_menu', TRUE);
}

/**
 * 'Navigation Menu' uninstall function
 */
function cm_bootstrap_menus_uninstall_navigation_menu() {
  // Navigation menu
  // Menu placed in the top right of the top navigation.
  // Typical links would be, Log In/Log Out, Burger Menu, etc.
  $navigation_menu = array(
    'menu_name' => 'navigation-menu',
    'title' => 'Navigation menu',
    'description' => 'Navigation menu.',
  );
  menu_delete($navigation_menu);

  // Delete menu block record
  $menu_block_delta = 'cmb-navigation-menu-block';
  $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

  if ($menu_block_exists) {
    db_delete('block')
      ->condition('delta', $menu_block_delta)
      ->execute();
  }

  // @todo: delete all menu link items
  // Delete all menu links for this menu
  db_delete('menu_links')
    ->condition('menu_name', 'navigation-menu')
    ->execute();

}

/**
 * 'Social Media Menu' install function
 */
function cm_bootstrap_menus_install_social_media_menu() {
  // Social Media Menu
  $menu = array(
    'menu_name' => 'social-media-menu',
    'title' => 'Social Media menu',
    'description' => 'Social Media menu',
  );
  menu_save($menu);

  // Programmatically create menu links
  // Facebook
  $menu_item = array(
    'link_title' => 'Facebook',
    'link_path' => 'https://facebook.com',
    'menu_name' => 'social-media-menu',
    'weight' => 1,
    'plid' => 0,
    'options' => array(
      'attributes' => array(
        'class' => array('facebook'),
        'target' => array('_blank'),
      ),
    ),
  );
  menu_link_save($menu_item);
  // Instagram
  $menu_item = array(
    'link_title' => 'Instagram',
    'link_path' => 'https://instagram.com',
    'menu_name' => 'social-media-menu',
    'weight' => 1,
    'plid' => 0,
    'options' => array(
      'attributes' => array(
        'class' => array('instagram'),
        'target' => array('_blank'),
      ),
    ),
  );
  menu_link_save($menu_item);
  // Twitter
  $menu_item = array(
    'link_title' => 'Twitter',
    'link_path' => 'https://twitter.com',
    'menu_name' => 'social-media-menu',
    'weight' => 1,
    'plid' => 0,
    'options' => array(
      'attributes' => array(
        'class' => array('twitter'),
        'target' => array('_blank'),
      ),
    ),
  );
  menu_link_save($menu_item);
  // Youtube
  $menu_item = array(
    'link_title' => 'Youtube',
    'link_path' => 'https://youtube.com',
    'menu_name' => 'social-media-menu',
    'weight' => 1,
    'plid' => 0,
    'options' => array(
      'attributes' => array(
        'class' => array('youtube'),
        'target' => array('_blank'),
      ),
    ),
  );
  menu_link_save($menu_item);

  // Programmatically generate social media menu block
  /*if (menu_load('social-media-menu')) {
    if (module_exists('cm_bootstrap_modules') && cm_bootstrap_modules_theme_exists('cm_bootstrap') ) {
      // Create social media menu block 1
      $menu_block_delta = 'cmb-social-media-menu-block';
      $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();
      if (!$menu_block_exists) {
        // Place menu block programmatically
        $menu_block = array(
          'module' => 'menu_block',
          'delta' => $menu_block_delta,
          'theme' => 'cm_bootstrap',
          'status' => 1,
          'weight' => 0,
          'region' => 'below_navigation',
          'custom' => 0,
          'visibility' => 0,
          'pages' => '',
          'title' => '<none>',
          'css_class' => 'social-media-menu',
        );
        drupal_write_record('block', $menu_block);
      }
      // Create social media menu block 2
      $menu_block_delta2 = 'cmb-social-media-menu-block2';
      $menu_block_exists2 = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta2))->fetchField();
      if (!$menu_block_exists2) {
        // Place menu block programmatically
        $menu_block2 = array(
          'module' => 'menu_block',
          'delta' => $menu_block_delta2,
          'theme' => 'cm_bootstrap',
          'status' => 1,
          'weight' => 0,
          'region' => 'footer_bottom',
          'custom' => 0,
          'visibility' => 0,
          'pages' => '',
          'title' => '<none>',
          'css_class' => 'social-media-menu',
        );
        drupal_write_record('block', $menu_block2);
      }
    }
  }*/

  // Clear menu cache
  cache_clear_all('*', 'cache_menu', TRUE);
}

/**
 * 'Social Media Menu' uninstall function
 */
function cm_bootstrap_menus_uninstall_social_media_menu() {
  // Delete Social Media Menu
  $menu = array(
    'menu_name' => 'social-media-menu',
    'title' => 'CMB Social Media menu',
    'description' => 'Social Media menu',
  );
  menu_delete($menu);

  // Delete all menu links for this menu
  db_delete('menu_links')
    ->condition('menu_name', 'social-media-menu')
    ->execute();

  // Delete menu block record
  /*$menu_block_delta = 'cmb-social-media-menu-block';
  $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

  if ($menu_block_exists) {
    db_delete('block')
      ->condition('delta', $menu_block_delta)
      ->execute();
  }
  // Delete menu block record
  $menu_block_delta2 = 'cmb-social-media-menu-block2';
  $menu_block_exists2 = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta2))->fetchField();

  if ($menu_block_exists2) {
    db_delete('block')
      ->condition('delta', $menu_block_delta2)
      ->execute();
  }*/
}
