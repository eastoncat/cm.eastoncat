<?php

/**
 * 'User Add Content Menu' install function
 */
function cm_bootstrap_community_install_user_add_content_menu() {
  // Create menu
  $menu = array(
    'menu_name' => 'user-add-content-menu',
    'title' => 'Use Add Content menu',
    'description' => 'Use Add Content menu',
  );
  menu_save($menu);

  // Programmatically place menu block in region
  if (menu_load('user-add-content-menu')) {
    if (module_exists('cmb_helper') && cmb_helper_theme_exists('cmb_theme') ) {
      // Check if menu block already exists
      $menu_block_delta = 'cmb-user-add-content-menu-block';
      $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

      if (!$menu_block_exists) {
        // Place menu block programmatically
        $menu_block = array(
          'module' => 'menu_block',
          'delta' => 'cmb-user-add-content-menu-block',
          'theme' => 'cm_bootstrap',
          'status' => 1,
          'weight' => 0,
          'region' => 'sidebar_second',
          'custom' => 0,
          'visibility' => BLOCK_VISIBILITY_LISTED,
          // Not letting us add to multiple pages here...
          'pages' => 'user/*',
          'title' => '<none>',
        );
        drupal_write_record('block', $menu_block);
      }

    }
  }

  // Programmatically create menu links
  $menu_item1 = array(
    'link_title' => 'Add Series',
    'link_path' => 'node/add/cm-project',
    'menu_name' => 'user-add-content-menu',
    'weight' => 1,
    'plid' => 0,
  );
  menu_link_save($menu_item1);

  $menu_item2 = array(
    'link_title' => 'Add Show',
    'link_path' => 'node/add/cm-show',
    'menu_name' => 'user-add-content-menu',
    'weight' => 2,
    'plid' => 0,
  );
  menu_link_save($menu_item2);

  // Clear menu cache
  cache_clear_all('*', 'cache_menu', TRUE);
}

/**
 * 'User Add Content Menu' uninstall function
 */
function cm_bootstrap_community_uninstall_user_add_content_menu() {
  // Delete menu
  $menu = array(
    'menu_name' => 'user-add-content-menu',
    'title' => 'Use Add Content menu',
    'description' => 'Use Add Content menu',
  );
  menu_delete($menu);

  // Delete menu block record
  $menu_block_delta = 'cmb-user-add-content-menu-block';
  $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

  if ($menu_block_exists) {
    db_delete('block')
      ->condition('delta', $menu_block_delta)
      ->execute();
  }

  // @todo: delete all menu link items
  // Delete all menu links for this menu
  db_delete('menu_links')
    ->condition('menu_name', 'user-add-content-menu')
    ->execute();

}


/**
 * 'User Profile' Menu install function
 */
function cm_bootstrap_community_install_user_profile_menu() {
  // Create menu
  $menu = array(
    'menu_name' => 'user-profile-menu',
    'title' => 'User Profile menu',
    'description' => 'User Profile menu',
  );
  menu_save($menu);

  // Programmatically place menu block in region
  if (menu_load('user-profile-menu')) {
    if (module_exists('cmb_helper') && cmb_helper_theme_exists('cmb_theme')) {
      // Check if menu block already exists
      $menu_block_delta = 'cmb-user-profile-menu-block';
      $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

      if (!$menu_block_exists) {
        // Place menu block programmatically
        $menu_block = array(
          'module' => 'menu_block',
          'delta' => 'cmb-user-profile-menu-block',
          'theme' => 'cm_bootstrap',
          'status' => 1,
          'weight' => 2,
          'region' => 'above_content',
          'custom' => 0,
          'visibility' => BLOCK_VISIBILITY_LISTED,
          'pages' => "user/*\nnproducer-hub",
          'title' => '<none>',
        );
        drupal_write_record('block', $menu_block);
      }

    }
  }

  // Clear menu route cache so when these menu items are created,
  // custom routes defined in .module are already loaded and working.
  $menu_rebuild = menu_rebuild();

  if ($menu_rebuild) {
    // Programmatically create menu links
    $menu_item1 = array(
      'link_title' => 'My Feed',
      'link_path' => 'user/feed',
      'menu_name' => 'user-profile-menu',
      'weight' => 1,
      'plid' => 0,
    );
    menu_link_save($menu_item1);

    $menu_item2 = array(
      'link_title' => 'My Profile',
      'link_path' => 'user',
      'menu_name' => 'user-profile-menu',
      'weight' => 2,
      'plid' => 0,
    );
    menu_link_save($menu_item2);

    // @todo this route might not be on every site, so will this fail b/c the route doenst exist yet here?
    // Disable this for now, talk to Emily tomorrow, should probs just include the producer-hub view w/ this module.
    /*$menu_item3 = array(
      'link_title' => 'My Videos',
      'link_path' => 'producer-hub',
      'menu_name' => 'user-profile-menu',
      'weight' => 3,
      'plid' => 0,
    );
    menu_link_save($menu_item3);*/

    // Clear menu cache
    cache_clear_all('*', 'cache_menu', TRUE);
  }
}

/**
 * 'User Profile' menu uninstall function
 */
function cm_bootstrap_community_uninstall_user_profile_menu() {
  // Delete menu
  $menu = array(
    'menu_name' => 'user-profile-menu',
    'title' => 'User Profile menu',
    'description' => 'User Profile menu',
  );
  menu_delete($menu);

  // Delete menu block record
  $menu_block_delta = 'cmb-user-profile-menu-block';
  $menu_block_exists = db_query("SELECT delta FROM {block} WHERE delta = :delta", array(':delta' => $menu_block_delta))->fetchField();

  if ($menu_block_exists) {
    db_delete('block')
      ->condition('delta', $menu_block_delta)
      ->execute();
  }

  // Delete all menu links for this menu
  db_delete('menu_links')
    ->condition('menu_name', 'user-profile-menu')
    ->execute();

}
