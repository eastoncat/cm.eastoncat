<?php
/**
 * @file
 * cm_vod_feed.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cm_vod_feed_views_default_views() {
  $export = array();

  $view = new view();
	$view->name = 'cm_vod_feed_items';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'file_managed';
	$view->human_name = 'VOD Feed: Feed Items';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'VOD Feed: Feed Items';
	$handler->display->display_options['css_class'] = 'cm-vods';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '16';
	$handler->display->display_options['style_plugin'] = 'grid';
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: File: Rendered */
	$handler->display->display_options['fields']['rendered']['id'] = 'rendered';
	$handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
	$handler->display->display_options['fields']['rendered']['field'] = 'rendered';
	$handler->display->display_options['fields']['rendered']['label'] = '';
	$handler->display->display_options['fields']['rendered']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['rendered']['file_view_mode'] = 'preview';
	/* Field: File: Name */
	$handler->display->display_options['fields']['filename']['id'] = 'filename';
	$handler->display->display_options['fields']['filename']['table'] = 'file_managed';
	$handler->display->display_options['fields']['filename']['field'] = 'filename';
	$handler->display->display_options['fields']['filename']['label'] = '';
	$handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
	/* Sort criterion: File: Upload date */
	$handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
	$handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
	$handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
	$handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
	/* Contextual filter: Feeds item: Owner feed nid */
	$handler->display->display_options['arguments']['feed_nid']['id'] = 'feed_nid';
	$handler->display->display_options['arguments']['feed_nid']['table'] = 'feeds_item';
	$handler->display->display_options['arguments']['feed_nid']['field'] = 'feed_nid';
	$handler->display->display_options['arguments']['feed_nid']['default_action'] = 'default';
	$handler->display->display_options['arguments']['feed_nid']['default_argument_type'] = 'node';
	$handler->display->display_options['arguments']['feed_nid']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['feed_nid']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['feed_nid']['summary_options']['items_per_page'] = '25';
	/* Filter criterion: File: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'file_managed';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'video' => 'video',
	);
	/* Filter criterion: File: Name */
	$handler->display->display_options['filters']['filename']['id'] = 'filename';
	$handler->display->display_options['filters']['filename']['table'] = 'file_managed';
	$handler->display->display_options['filters']['filename']['field'] = 'filename';
	$handler->display->display_options['filters']['filename']['operator'] = 'contains';
	$handler->display->display_options['filters']['filename']['exposed'] = TRUE;
	$handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
	$handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
	$handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
	$handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
	$handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
	);

  $export['cm_vod_feed_items'] = $view;

  return $export;
}
