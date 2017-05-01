<?php
/**
 * @file
 * ecat_menu_panel_menu_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ecat_menu_panel_menu_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-menu-panel-menu_about-ecat:node/549637.
  $menu_links['menu-menu-panel-menu_about-ecat:node/549637'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549637',
    'router_path' => 'node/%',
    'link_title' => 'About ECAT',
    'options' => array(
      'attributes' => array(
        'title' => 'About ECAT',
      ),
      'identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-panel-menu_become-a-member:civicrm/contribute/transact.
  $menu_links['menu-menu-panel-menu_become-a-member:civicrm/contribute/transact'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'civicrm/contribute/transact',
    'router_path' => 'civicrm',
    'link_title' => 'Become a Member',
    'options' => array(
      'query' => array(
        'reset' => 1,
        'id' => 1,
      ),
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_become-a-member:civicrm/contribute/transact',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_connect:node/206',
  );
  // Exported menu link: menu-menu-panel-menu_blog:node/549634.
  $menu_links['menu-menu-panel-menu_blog:node/549634'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549634',
    'router_path' => 'node/%',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_blog:node/549634',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_connect:node/206.
  $menu_links['menu-menu-panel-menu_connect:node/206'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/206',
    'router_path' => 'node/%',
    'link_title' => 'Connect',
    'options' => array(
      'attributes' => array(
        'title' => 'Connect',
      ),
      'identifier' => 'menu-menu-panel-menu_connect:node/206',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-panel-menu_contact:node/727.
  $menu_links['menu-menu-panel-menu_contact:node/727'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/727',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_contact:node/727',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-panel-menu_directions:node/217.
  $menu_links['menu-menu-panel-menu_directions:node/217'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/217',
    'router_path' => 'node/%',
    'link_title' => 'Directions',
    'options' => array(
      'identifier' => 'menu-menu-panel-menu_directions:node/217',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_facility-and-gear:node/549639.
  $menu_links['menu-menu-panel-menu_facility-and-gear:node/549639'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549639',
    'router_path' => 'node/%',
    'link_title' => 'Facility and Gear',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_facility-and-gear:node/549639',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_groups:groups.
  $menu_links['menu-menu-panel-menu_groups:groups'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Groups',
    'options' => array(
      'identifier' => 'menu-menu-panel-menu_groups:groups',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-panel-menu_home:<front>.
  $menu_links['menu-menu-panel-menu_home:<front>'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-panel-menu_make-a-tv-program:node/207.
  $menu_links['menu-menu-panel-menu_make-a-tv-program:node/207'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/207',
    'router_path' => 'node/%',
    'link_title' => 'Make a TV Program',
    'options' => array(
      'identifier' => 'menu-menu-panel-menu_make-a-tv-program:node/207',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_connect:node/206',
  );
  // Exported menu link: menu-menu-panel-menu_our-services:node/549637.
  $menu_links['menu-menu-panel-menu_our-services:node/549637'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549637',
    'router_path' => 'node/%',
    'link_title' => 'Our Services',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_our-services:node/549637',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_policies:node/549656.
  $menu_links['menu-menu-panel-menu_policies:node/549656'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549656',
    'router_path' => 'node/%',
    'link_title' => 'Policies',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_policies:node/549656',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_request-event-coverage:node/549655.
  $menu_links['menu-menu-panel-menu_request-event-coverage:node/549655'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549655',
    'router_path' => 'node/%',
    'link_title' => 'Request Event Coverage',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_request-event-coverage:node/549655',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_connect:node/206',
  );
  // Exported menu link: menu-menu-panel-menu_staff-and-board:node/549638.
  $menu_links['menu-menu-panel-menu_staff-and-board:node/549638'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549638',
    'router_path' => 'node/%',
    'link_title' => 'Staff and Board',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_staff-and-board:node/549638',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_about-ecat:node/549637',
  );
  // Exported menu link: menu-menu-panel-menu_submit-a-program:node/549654.
  $menu_links['menu-menu-panel-menu_submit-a-program:node/549654'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/549654',
    'router_path' => 'node/%',
    'link_title' => 'Submit a Program',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-menu-panel-menu_submit-a-program:node/549654',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_connect:node/206',
  );
  // Exported menu link: menu-menu-panel-menu_tv-schedules:node/325.
  $menu_links['menu-menu-panel-menu_tv-schedules:node/325'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/325',
    'router_path' => 'node/%',
    'link_title' => 'TV Schedules',
    'options' => array(
      'identifier' => 'menu-menu-panel-menu_tv-schedules:node/325',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_watch:node/215',
  );
  // Exported menu link: menu-menu-panel-menu_volunteer:node/208.
  $menu_links['menu-menu-panel-menu_volunteer:node/208'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/208',
    'router_path' => 'node/%',
    'link_title' => 'Volunteer',
    'options' => array(
      'identifier' => 'menu-menu-panel-menu_volunteer:node/208',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_connect:node/206',
  );
  // Exported menu link: menu-menu-panel-menu_watch-online:node/215.
  $menu_links['menu-menu-panel-menu_watch-online:node/215'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/215',
    'router_path' => 'node/%',
    'link_title' => 'Watch Online',
    'options' => array(
      'attributes' => array(
        'title' => 'watch on demand',
      ),
      'identifier' => 'menu-menu-panel-menu_watch-online:node/215',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-menu-panel-menu_watch:node/215',
  );
  // Exported menu link: menu-menu-panel-menu_watch:node/215.
  $menu_links['menu-menu-panel-menu_watch:node/215'] = array(
    'menu_name' => 'menu-menu-panel-menu',
    'link_path' => 'node/215',
    'router_path' => 'node/%',
    'link_title' => 'Watch',
    'options' => array(
      'attributes' => array(
        'title' => 'Watch',
      ),
      'identifier' => 'menu-menu-panel-menu_watch:node/215',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About ECAT');
  t('Become a Member');
  t('Blog');
  t('Connect');
  t('Contact');
  t('Directions');
  t('Facility and Gear');
  t('Groups');
  t('Home');
  t('Make a TV Program');
  t('Our Services');
  t('Policies');
  t('Request Event Coverage');
  t('Staff and Board');
  t('Submit a Program');
  t('TV Schedules');
  t('Volunteer');
  t('Watch');
  t('Watch Online');

  return $menu_links;
}
