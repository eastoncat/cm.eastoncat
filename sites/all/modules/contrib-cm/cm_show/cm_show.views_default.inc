<?php
// $Id: cm_show.views_default.inc,v 1.1.2.2.2.2 2010/06/09 22:33:09 kreynen Exp $
/**
 * Implements hook_views_default_views().
 */
function cm_show_views_default_views() {
  /*
   * View 'Shows'
   */
  $view = new view;
  $view->name = 'Shows';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'votingapi_cache' => array(
      'label' => 'Voting results',
      'required' => 0,
      'votingapi' => array(
        'value_type' => '',
        'tag' => '',
        'function' => 'average',
      ),
      'id' => 'votingapi_cache',
      'table' => 'node',
      'field' => 'votingapi_cache',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'votingapi_cache_1' => array(
      'id' => 'votingapi_cache_1',
      'table' => 'node',
      'field' => 'votingapi_cache',
    ),
  ));
  $handler->override_option('fields', array(
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => '200 pixels bounding box_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'relationship' => 'none',
    ),
    'group_nid' => array(
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'value' => array(
      'id' => 'value',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache',
    ),
    'group_nid_1' => array(
      'id' => 'group_nid_1',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'function' => array(
      'order' => 'DESC',
      'id' => 'function',
      'table' => 'votingapi_cache',
      'field' => 'function',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => FALSE,
        'operator' => 'field_cm_show_theme_nid_op',
        'identifier' => 'field_cm_show_theme_nid',
        'label' => 'Content: Timeslot Theme',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
    ),
    'field_cm_share_value' => array(
      'operator' => 'or',
      'value' => array(
        '1' => '1',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_cm_share_value',
      'table' => 'node_data_field_cm_share',
      'field' => 'field_cm_share_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'field_cm_locally_produced_value' => array(
      'id' => 'field_cm_locally_produced_value',
      'table' => 'node_data_field_cm_locally_produced',
      'field' => 'field_cm_locally_produced_value',
    ),
    'group_nid' => array(
      'operator' => '=',
      'value' => array(
        'min' => '',
        'max' => '',
        'value' => '',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => FALSE,
        'operator' => 'group_nid_op',
        'identifier' => 'group_nid',
        'label' => 'Organic groups: Groups',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
      ),
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 0);
  $handler->override_option('use_pager', 'mini');
  $handler = $view->new_display('page', 'New Shows', 'page_1');
  $handler->override_option('fields', array(
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'video thumbnail 120 x 85_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'group_nid' => array(
      'label' => '',
      'type' => 'separator',
      'separator' => ', ',
      'empty' => '',
      'exclude' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_cm_show_episode_number_value' => array(
      'label' => 'Episode',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_episode_number_value',
      'table' => 'node_data_field_cm_show_episode_number',
      'field' => 'field_cm_show_episode_number_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'value' => array(
      'label' => '',
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'appearance' => 'fivestar_views_value_display_handler',
      'exclude' => 0,
      'id' => 'value',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search: ',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_cm_show_theme_nid_op',
        'identifier' => 'field_cm_show_theme_nid',
        'label' => 'Theme:',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'New Shows');
  $handler->override_option('header', '

    ');
  $handler->override_option('header_format', '2');
  $handler->override_option('path', 'shows/all');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Show Archive',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Shows',
    'description' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('page', 'Show Status', 'page_2');
  $handler->override_option('relationships', array());
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => '200 pixels bounding box_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'name' => array(
      'label' => 'From',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => 'Post date',
      'date_format' => 'small',
      'custcm_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_mpeg2_fid' => array(
      'label' => 'MPEG',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_mpeg2_fid',
      'table' => 'node_data_field_cm_show_mpeg2',
      'field' => 'field_cm_show_mpeg2_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_flash_fid' => array(
      'label' => 'FLV',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'path_plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_flash_fid',
      'table' => 'node_data_field_cm_show_flash',
      'field' => 'field_cm_show_flash_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_capture_fid_1' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid_1',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_duration_value' => array(
      'label' => 'Duration',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_duration_value',
      'table' => 'node_data_field_cm_show_duration',
      'field' => 'field_cm_show_duration_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'group_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'group_nid_op',
        'identifier' => 'group_nid',
        'label' => 'Organic groups: Groups',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Shows Status');
  $handler->override_option('items_per_page', 25);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'field_cm_creator_value' => 'field_cm_creator_value',
      'field_cm_show_capture_fid' => 'field_cm_show_capture_fid',
      'name' => 'name',
      'created' => 'created',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_cm_creator_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_cm_show_capture_fid' => array(
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'created' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'shows/status');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Status',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Popular Shows', 'page_3');
  $handler->override_option('relationships', array(
    'votingapi_cache_1' => array(
      'label' => 'Rating Average',
      'required' => 1,
      'votingapi' => array(
        'value_type' => 'percent',
        'tag' => 'vote',
        'function' => 'average',
      ),
      'id' => 'votingapi_cache_1',
      'table' => 'node',
      'field' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'votingapi_cache' => array(
      'label' => 'Voting Count',
      'required' => 1,
      'votingapi' => array(
        'value_type' => 'percent',
        'tag' => 'vote',
        'function' => 'count',
      ),
      'id' => 'votingapi_cache',
      'table' => 'node',
      'field' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'video thumbnail 120 x 85_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'group_nid' => array(
      'label' => '',
      'type' => 'separator',
      'separator' => ', ',
      'empty' => '',
      'exclude' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'value_1' => array(
      'label' => '',
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => ' members rated this show an average of',
      'appearance' => '',
      'exclude' => 0,
      'id' => 'value_1',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'value' => array(
      'label' => '',
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'appearance' => 'fivestar_views_value_display_handler',
      'exclude' => 0,
      'id' => 'value',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache_1',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('sorts', array(
    'value_1' => array(
      'order' => 'DESC',
      'id' => 'value_1',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'value' => array(
      'order' => 'DESC',
      'id' => 'value',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache_1',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_cm_show_theme_nid_op',
        'identifier' => 'field_cm_show_theme_nid',
        'label' => 'Theme:',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Popular Shows');
  $handler->override_option('header', '
    ');
  $handler->override_option('header_format', '2');
  $handler->override_option('path', 'shows/popular');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Popular',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Popular',
    'description' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->override_option('relationships', array(
    'votingapi_cache' => array(
      'label' => 'Voting Average',
      'required' => 0,
      'votingapi' => array(
        'value_type' => '',
        'tag' => '',
        'function' => 'average',
      ),
      'id' => 'votingapi_cache',
      'table' => 'node',
      'field' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'votingapi_cache_1' => array(
      'label' => 'Voting Count',
      'required' => 0,
      'votingapi' => array(
        'value_type' => '',
        'tag' => '',
        'function' => 'count',
      ),
      'id' => 'votingapi_cache_1',
      'table' => 'node',
      'field' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'value' => array(
      'order' => 'DESC',
      'id' => 'value',
      'table' => 'votingapi_cache',
      'field' => 'value',
      'relationship' => 'votingapi_cache_1',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'function' => array(
      'order' => 'DESC',
      'id' => 'function',
      'table' => 'votingapi_cache',
      'field' => 'function',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', 'node_rss');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'item_length' => 'default',
  ));
  $handler->override_option('path', 'shows/top10/feed');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler->override_option('displays', array(
    'page_3' => 'page_3',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('feed', 'Feed', 'feed_2');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => FALSE,
        'operator' => 'field_cm_show_theme_nid_op',
        'identifier' => 'field_cm_show_theme_nid',
        'label' => 'Content: Timeslot Theme',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
    ),
    'field_cm_share_value' => array(
      'operator' => 'or',
      'value' => array(
        '1' => '1',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_cm_share_value',
      'table' => 'node_data_field_cm_share',
      'field' => 'field_cm_share_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'field_cm_locally_produced_value' => array(
      'operator' => 'or',
      'value' => array(
        '1' => '1',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_cm_locally_produced_value',
      'table' => 'node_data_field_cm_locally_produced',
      'field' => 'field_cm_locally_produced_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', 'node_rss');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'item_length' => 'default',
  ));
  $handler->override_option('path', 'shows/top10/local/feed');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler->override_option('displays', array(
    'page_3' => 'page_3',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('page', 'Shows by Project', 'page_4');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_project' => 'cm_project',
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => FALSE,
        'identifier' => 'type',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => FALSE,
        'operator' => 'field_cm_show_theme_nid_op',
        'identifier' => 'field_cm_show_theme_nid',
        'label' => 'Content: Timeslot Theme',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
    ),
    'field_cm_share_value' => array(
      'operator' => 'or',
      'value' => array(
        '1' => '1',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_cm_share_value',
      'table' => 'node_data_field_cm_share',
      'field' => 'field_cm_share_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Shows by Project');
  $handler->override_option('path', 'admin/shows/project');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Shows without Timeslot', 'page_5');
  $handler->override_option('relationships', array());
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_cm_show_duration_value' => array(
      'label' => 'Duration',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_duration_value',
      'table' => 'node_data_field_cm_show_duration',
      'field' => 'field_cm_show_duration_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'operator' => 'not',
      'value' => array(
        '12309' => '12309',
        '12285' => '12285',
        '12305' => '12305',
        '12310' => '12310',
        '14422' => '14422',
        '12307' => '12307',
        '12304' => '12304',
        '12286' => '12286',
        '12284' => '12284',
        '12308' => '12308',
        '12303' => '12303',
        '12306' => '12306',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'field_cm_show_theme_nid_op',
        'label' => 'Content: Timeslot Theme',
        'use_operator' => FALSE,
        'identifier' => 'field_cm_show_theme_nid',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('items_per_page', 50);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'field_cm_show_duration_value' => 'field_cm_show_duration_value',
      'field_cm_show_legacy_tb_prim_nid_value' => 'field_cm_show_legacy_tb_prim_nid_value',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_cm_show_duration_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_cm_show_legacy_tb_prim_nid_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('row_options', array(
    'inline' => array(
      'group_nid' => 'group_nid',
      'title' => 'title',
    ),
    'separator' => '|',
  ));
  $handler->override_option('path', 'admin/shows/notimeslot');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;

  /*
   * View 'front_page_thumbnail_rotator'
   */
  $view = new view;
  $view->name = 'front_page_thumbnail_rotator';
  $view->description = 'Front Page Thumbnail Rotator';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'votingapi_cache' => array(
      'id' => 'votingapi_cache',
      'table' => 'node',
      'field' => 'votingapi_cache',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'random' => array(
      'id' => 'random',
      'table' => 'views',
      'field' => 'random',
    ),
  ));
  $handler->override_option('filters', array(
    'status_extra' => array(
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header', '<a href="/auction">DOM\'s Valentine Inspired Auction is Community for Bids</a>');
  $handler->override_option('header_format', '2');
  $handler->override_option('header_empty', 0);
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 12);
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'columns' => '4',
    'alignment' => 'horizontal',
  ));
  $handler = $view->new_display('block', 'Project Videos', 'block_3');
  $handler->override_option('fields', array(
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'front_page_video_thumbnails_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'picg' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'picg',
      'table' => 'og_ancestry',
      'field' => 'picg',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('header', '');
  $handler->override_option('items_per_page', 10);
  $handler->override_option('style_plugin', 'viewscarousel');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'skin' => 'ie7',
    'vertical' => 0,
    'start' => '1',
    'scroll' => '3',
    'visible' => 0,
    'animation' => '0',
    'easing' => '',
    'auto' => '0',
    'wrap' => '0',
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Random Videos', 'block_4');
  $handler->override_option('relationships', array());
  $handler->override_option('fields', array(
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'front_page_video_thumbnails_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'random' => array(
      'order' => 'ASC',
      'id' => 'random',
      'table' => 'views',
      'field' => 'random',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status_extra' => array(
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('header', '');
  $handler->override_option('use_pager', '0');
  $handler->override_option('style_plugin', 'viewscarousel');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'skin' => 'ie7',
    'vertical' => 0,
    'start' => '1',
    'scroll' => '3',
    'visible' => 0,
    'animation' => '0',
    'easing' => '',
    'auto' => '0',
    'wrap' => '0',
  ));
  $handler->override_option('block_description', 'Random Videos');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Popular Videos', 'block_5');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_cm_show_capture_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'front_page_video_thumbnails_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'function' => array(
      'order' => 'DESC',
      'id' => 'function',
      'table' => 'votingapi_cache',
      'field' => 'function',
      'relationship' => 'votingapi_cache',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'status_extra' => array(
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('title', 'Popular Videos');
  $handler->override_option('header', '');
  $handler->override_option('style_plugin', 'viewscarousel');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'skin' => 'ie7',
    'vertical' => 0,
    'start' => '1',
    'scroll' => '3',
    'visible' => 0,
    'animation' => '0',
    'easing' => '',
    'auto' => '0',
    'wrap' => '0',
  ));
  $handler->override_option('block_description', 'Popular Videos');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  /*
   * View 'show_details'
   */
  $view = new view;
  $view->name = 'show_details';
  $view->description = 'Details about a Show';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_cm_creator_value' => array(
      'label' => 'Creator',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_creator_value',
      'table' => 'node_data_field_cm_creator',
      'field' => 'field_cm_creator_value',
      'relationship' => 'none',
    ),
    'group_nid' => array(
      'label' => 'Project',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'type' => 'separator',
      'separator' => ', ',
      'empty' => '',
      'exclude' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_theme_nid' => array(
      'label' => 'Theme Block',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_theme_nid',
      'table' => 'node_data_field_cm_show_theme',
      'field' => 'field_cm_show_theme_nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'Genre',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'type' => 'separator',
      'separator' => ', ',
      'empty' => '',
      'link_to_taxonomy' => 1,
      'limit' => 0,
      'vids' => array(
        '7' => 0,
        '23' => 0,
        '14' => 0,
        '6' => 0,
        '9' => 0,
        '27' => 0,
        '20' => 0,
        '2' => 0,
        '3' => 0,
        '25' => 0,
        '28' => 0,
        '5' => 0,
        '24' => 0,
        '21' => 0,
        '8' => 0,
        '10' => 0,
        '17' => 0,
        '18' => 0,
        '16' => 0,
        '22' => 0,
        '4' => 0,
        '26' => 0,
        '19' => 0,
        '30' => 0,
        '12' => 0,
      ),
      'exclude' => 0,
      'id' => 'tid',
      'table' => 'taxonomy_term_node',
      'field' => 'tid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_duration_value' => array(
      'label' => 'Duration',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_duration_value',
      'table' => 'node_data_field_cm_show_duration',
      'field' => 'field_cm_show_duration_value',
      'relationship' => 'none',
    ),
    'field_cm_show_episode_number_value' => array(
      'label' => 'Episode Number',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_episode_number_value',
      'table' => 'node_data_field_cm_show_episode_number',
      'field' => 'field_cm_show_episode_number_value',
      'relationship' => 'none',
    ),
    'field_cm_language_value' => array(
      'label' => 'Language',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_language_value',
      'table' => 'node_data_field_cm_language',
      'field' => 'field_cm_language_value',
      'relationship' => 'none',
    ),
    'field_cm_locally_produced_value' => array(
      'label' => 'Locally Produced',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_locally_produced_value',
      'table' => 'node_data_field_cm_locally_produced',
      'field' => 'field_cm_locally_produced_value',
      'relationship' => 'none',
    ),
    'field_cm_safe_for_all_ages_value' => array(
      'id' => 'field_cm_safe_for_all_ages_value',
      'table' => 'node_data_field_cm_safe_for_all_ages',
      'field' => 'field_cm_safe_for_all_ages_value',
    ),
    'field_cm_audience_value' => array(
      'id' => 'field_cm_audience_value',
      'table' => 'node_data_field_cm_audience',
      'field' => 'field_cm_audience_value',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'merci_reservation' => 0,
        'merci_reservation_template' => 0,
        'account_change_request' => 0,
        'book' => 0,
        'bocm_pole' => 0,
        'canon_video_light' => 0,
        'canon_xl1_dv_camera' => 0,
        'class' => 0,
        'class_description' => 0,
        'class_feed' => 0,
        'dv_palmcorder' => 0,
        'editing_computer_equipment' => 0,
        'event' => 0,
        'external_hard_drives' => 0,
        'facilities' => 0,
        'field_monitor' => 0,
        'handheld_microphone' => 0,
        'hdv_deck_portable' => 0,
        'hdv_palmcorder' => 0,
        'headphone' => 0,
        'large_tripod' => 0,
        'lavalier_microphone' => 0,
        'light_kit' => 0,
        'livestream' => 0,
        'media_test' => 0,
        'member_level' => 0,
        'merci_projectors' => 0,
        'minidv_vtr_decks' => 0,
        'monopod' => 0,
        'news_item' => 0,
        'cm_airing' => 0,
        'cm_crew_request' => 0,
        'cm_feed' => 0,
        'cm_handbook' => 0,
        'cm_handbook_updates' => 0,
        'cm_handbook_update_feed' => 0,
        'cm_migration_feed' => 0,
        'cm_project' => 0,
        'cm_project_feed' => 0,
        'cm_project_type' => 0,
        'cm_show' => 0,
        'cm_timeslot_event' => 0,
        'cm_timeslot_theme' => 0,
        'outdoor_reflector' => 0,
        'page' => 0,
        'panasonic_dvx100a_dv_camera' => 0,
        'panasonic_gs300' => 0,
        'profile' => 0,
        'project_blog' => 0,
        'project_event' => 0,
        'project_wiki' => 0,
        'shotgun_microphone' => 0,
        'small_amp_and_speakers' => 0,
        'small_tripod' => 0,
        'sms_message' => 0,
        'sony_lseries_video_light' => 0,
        'sony_pd170_dvcam' => 0,
        'sony_z1u_hdv_camera' => 0,
        'studios' => 0,
        'technical_problem' => 0,
        'test_type' => 0,
        'wide_angle_adapter_sony_z1u' => 0,
        'wireless_lavalier' => 0,
        'xlr_adapter' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '7' => 0,
        '23' => 0,
        '14' => 0,
        '6' => 0,
        '9' => 0,
        '27' => 0,
        '20' => 0,
        '2' => 0,
        '3' => 0,
        '25' => 0,
        '28' => 0,
        '5' => 0,
        '24' => 0,
        '21' => 0,
        '8' => 0,
        '10' => 0,
        '17' => 0,
        '18' => 0,
        '16' => 0,
        '22' => 0,
        '4' => 0,
        '26' => 0,
        '19' => 0,
        '30' => 0,
        '12' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'About This Show');
  $handler->override_option('empty', '<?php
    $fieldisempty = 1;
    ?>');
  $handler->override_option('empty_format', '3');
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  /*
   * View 'show_details'
   */

  $view = new view;
  $view->name = 'cm_show_status';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'group_nid_1' => array(
      'id' => 'group_nid_1',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
    ),
    'created' => array(
      'label' => 'Post date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custcm_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_cm_show_mpeg2_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'path_plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_cm_show_mpeg2_fid',
      'table' => 'node_data_field_cm_show_mpeg2',
      'field' => 'field_cm_show_mpeg2_fid',
      'relationship' => 'none',
    ),
    'field_cm_show_capture_fid' => array(
      'label' => 'Screen Capture',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'path_plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_cm_show_capture_fid',
      'table' => 'node_data_field_cm_show_capture',
      'field' => 'field_cm_show_capture_fid',
      'relationship' => 'none',
    ),
    'field_cm_show_flash_fid' => array(
      'label' => 'Flash',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'path_plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_cm_show_flash_fid',
      'table' => 'node_data_field_cm_show_flash',
      'field' => 'field_cm_show_flash_fid',
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'MPEG',
      'alter' => array(
        'alter_text' => 0,
        'text' => '<img src="[phpcode]" />',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
	if($data->node_data_field_cm_show_mpeg2_field_cm_show_mpeg2_fid){
	  $filesize = cm_show_filesize($data->node_data_field_cm_show_mpeg2_field_cm_show_mpeg2_fid);
	  if($filesize < 10000){
	    return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/check-orange.png\';
	  } else {
	    return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/check-orange.png\';
	  }
	} else {
	  return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/x.png \';
	}
	?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'phpcode_1' => array(
      'label' => 'Flash',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<img src="[phpcode_1]" />
	',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
	if($data->node_data_field_cm_show_mpeg2_field_cm_show_flash_data){
	return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/check.png\';
	} else {
	return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/x.png \';
	}
	 ?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Thumbnail',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<img src="[phpcode_2]" />',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
	if($data->node_data_field_cm_show_mpeg2_field_cm_show_capture_data){
	  return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/check.png\';
	} else {
	  return base_path(). drupal_get_path(\'module\', \'cm_show\') . \'/img/x.png \';
	}
	 ?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'field_cm_show_duration_value' => array(
      'label' => 'Duration',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_cm_show_duration_value',
      'table' => 'node_data_field_cm_show_duration',
      'field' => 'field_cm_show_duration_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header', '<img src="<?php print base_path(). drupal_get_path(\'module\', \'cm_show\') ."/img/x.png"; ?>" /> - Indicates the the system wasn\'t able or hasn\'t yet created an MPEG from the original submission.<br />
	<img src="<?php print base_path(). drupal_get_path(\'module\', \'cm_show\') ."/img/check-orange.png"; ?>" /> - Indicates the system attempted to create an MPEG, but it is likely corrupt.<br />
	<img src="<?php print base_path(). drupal_get_path(\'module\', \'cm_show\') ."/img/check.png"; ?>" /> - Indicates everything processed correctly and the file can be scheduled.<br />');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'group_nid_1' => 'group_nid_1',
      'field_cm_show_mpeg2_fid' => 'field_cm_show_mpeg2_fid',
      'phpcode' => 'phpcode',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'group_nid_1' => array(
        'separator' => '',
      ),
      'field_cm_show_mpeg2_fid' => array(
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Show Status', 'page_2');
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'cm_show' => 'cm_show',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'group_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'group_nid_op',
        'identifier' => 'group_nid',
        'label' => 'Projects',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Shows Status');
  $handler->override_option('items_per_page', 25);
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'field_cm_creator_value' => 'field_cm_creator_value',
      'field_cm_show_capture_fid' => 'field_cm_show_capture_fid',
      'name' => 'name',
      'created' => 'created',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_cm_creator_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_cm_show_capture_fid' => array(
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'created' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'admin/om-timeslot-scheduler/manage/shows/status');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Show Status',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;

  return $views;
}


