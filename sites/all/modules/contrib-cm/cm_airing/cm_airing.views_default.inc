<?php

/**
 * Implements hook_views_default_views().
 */
function cm_airing_views_default_views() {
	$view = new view();
	$view->name = 'airings';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'cm_airing';
	$view->human_name = 'Airings';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Airings';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['access']['perm'] = 'administer cm_airing';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['query']['options']['query_comment'] = FALSE;
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
	$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '50';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['pager']['options']['quantity'] = '9';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'views_bulk_operations' => 'views_bulk_operations',
	  'airing_id' => 'airing_id',
	  'field_airing_title' => 'field_airing_title',
	  'field_airing_date' => 'field_airing_date',
	  'nothing' => 'nothing',
	  'nothing_1' => 'nothing_1',
	  'nothing_2' => 'nothing_2',
	);
	$handler->display->display_options['style_options']['default'] = '-1';
	$handler->display->display_options['style_options']['info'] = array(
	  'views_bulk_operations' => array(
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'airing_id' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'field_airing_title' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'field_airing_date' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'nothing' => array(
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'nothing_1' => array(
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'nothing_2' => array(
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	);
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['content'] = '<a href="<?php print url(\'airing/add\'); ?>>Add Airing</a>';
	$handler->display->display_options['header']['area']['format'] = 'full_html';
	/* No results behavior: Global: Text area */
	$handler->display->display_options['empty']['area']['id'] = 'area';
	$handler->display->display_options['empty']['area']['table'] = 'views';
	$handler->display->display_options['empty']['area']['field'] = 'area';
	$handler->display->display_options['empty']['area']['empty'] = TRUE;
	$handler->display->display_options['empty']['area']['content'] = 'No airings found';
	$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
	/* Field: Bulk operations: Airing */
	$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
	$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'cm_airing';
	$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
	$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
	$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
	  'action::views_bulk_operations_delete_item' => array(
	    'selected' => 1,
	    'postpone_processing' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	);
	/* Field: Airing: Airing ID */
	$handler->display->display_options['fields']['airing_id']['id'] = 'airing_id';
	$handler->display->display_options['fields']['airing_id']['table'] = 'cm_airing';
	$handler->display->display_options['fields']['airing_id']['field'] = 'airing_id';
	$handler->display->display_options['fields']['airing_id']['exclude'] = TRUE;
	$handler->display->display_options['fields']['airing_id']['separator'] = '';
	/* Field: Airing: Title */
	$handler->display->display_options['fields']['field_airing_title']['id'] = 'field_airing_title';
	$handler->display->display_options['fields']['field_airing_title']['table'] = 'field_data_field_airing_title';
	$handler->display->display_options['fields']['field_airing_title']['field'] = 'field_airing_title';
	/* Field: Airing: Date */
	$handler->display->display_options['fields']['field_airing_date']['id'] = 'field_airing_date';
	$handler->display->display_options['fields']['field_airing_date']['table'] = 'field_data_field_airing_date';
	$handler->display->display_options['fields']['field_airing_date']['field'] = 'field_airing_date';
	$handler->display->display_options['fields']['field_airing_date']['settings'] = array(
	  'format_type' => 'short',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_repeat_rule' => 'hide',
	);
	$handler->display->display_options['fields']['field_airing_date']['delta_offset'] = '0';
	/* Field: edit */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['ui_name'] = 'edit';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
	$handler->display->display_options['fields']['nothing']['alter']['text'] = 'edit';
	$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['nothing']['alter']['path'] = 'airing/[airing_id]/edit';
	$handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	/* Field: delete */
	$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
	$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
	$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing_1']['ui_name'] = 'delete';
	$handler->display->display_options['fields']['nothing_1']['label'] = '';
	$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
	$handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'delete';
	$handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'airing/[airing_id]/delete';
	$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
	/* Field: Global: Custom text */
	$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
	$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
	$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing_2']['label'] = 'Operations';
	$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] [nothing_1]';
	/* Field: Airing: Airing ID */
	$handler->display->display_options['fields']['airing_id_1']['id'] = 'airing_id_1';
	$handler->display->display_options['fields']['airing_id_1']['table'] = 'cm_airing';
	$handler->display->display_options['fields']['airing_id_1']['field'] = 'airing_id';
	$handler->display->display_options['fields']['airing_id_1']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['airing_id_1']['separator'] = '';
	/* Field: Airing: GUID */
	$handler->display->display_options['fields']['field_airing_guid']['id'] = 'field_airing_guid';
	$handler->display->display_options['fields']['field_airing_guid']['table'] = 'field_data_field_airing_guid';
	$handler->display->display_options['fields']['field_airing_guid']['field'] = 'field_airing_guid';
	/* Sort criterion: Airing: Date -  start date (field_airing_date) */
	$handler->display->display_options['sorts']['field_airing_date_value']['id'] = 'field_airing_date_value';
	$handler->display->display_options['sorts']['field_airing_date_value']['table'] = 'field_data_field_airing_date';
	$handler->display->display_options['sorts']['field_airing_date_value']['field'] = 'field_airing_date_value';
	$handler->display->display_options['sorts']['field_airing_date_value']['order'] = 'DESC';
	/* Filter criterion: Airing: Date -  start date (field_airing_date) */
	$handler->display->display_options['filters']['field_airing_date_value']['id'] = 'field_airing_date_value';
	$handler->display->display_options['filters']['field_airing_date_value']['table'] = 'field_data_field_airing_date';
	$handler->display->display_options['filters']['field_airing_date_value']['field'] = 'field_airing_date_value';
	$handler->display->display_options['filters']['field_airing_date_value']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_airing_date_value']['expose']['operator_id'] = 'field_airing_date_value_op';
	$handler->display->display_options['filters']['field_airing_date_value']['expose']['label'] = 'Date';
	$handler->display->display_options['filters']['field_airing_date_value']['expose']['operator'] = 'field_airing_date_value_op';
	$handler->display->display_options['filters']['field_airing_date_value']['expose']['identifier'] = 'field_airing_date_value';
	$handler->display->display_options['filters']['field_airing_date_value']['expose']['remember_roles'] = array(
	  2 => '2',
	  1 => 0,
	  4 => 0,
	  3 => 0,
	);
	$handler->display->display_options['filters']['field_airing_date_value']['form_type'] = 'date_popup';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'admin/content/airing';
	$handler->display->display_options['menu']['type'] = 'tab';
	$handler->display->display_options['menu']['title'] = 'Airings';
	$handler->display->display_options['menu']['weight'] = '0';
	$handler->display->display_options['menu']['context'] = 0;

  $views['airings'] = $view;

  return $views;
}
