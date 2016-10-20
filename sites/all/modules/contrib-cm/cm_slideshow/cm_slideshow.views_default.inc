<?php
/**
 * @file
 * cm_slideshow.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cm_slideshow_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cm_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Slideshow';
  $handler->display->display_options['use_more_text'] = 'mer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortera efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigande';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Fallande';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['flexslider_views_slideshow']['caption_field'] = 'none';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Förvald',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'uri' => 0,
    'field_cm_sub_head' => 0,
    'field_cm_slideshow_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'uri' => 0,
    'field_cm_sub_head' => 0,
    'field_cm_slideshow_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Sub Head */
  $handler->display->display_options['fields']['field_cm_sub_head']['id'] = 'field_cm_sub_head';
  $handler->display->display_options['fields']['field_cm_sub_head']['table'] = 'field_data_field_cm_sub_head';
  $handler->display->display_options['fields']['field_cm_sub_head']['field'] = 'field_cm_sub_head';
  $handler->display->display_options['fields']['field_cm_sub_head']['label'] = '';
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['text'] = '<div class="pinch"><div class="primary-headline">[title]</div><div class="secondary-headline">[field_cm_sub_head]</div></div>';
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_sub_head']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_cm_sub_head']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cm_sub_head']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cm_sub_head']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cm_slideshow_image']['id'] = 'field_cm_slideshow_image';
  $handler->display->display_options['fields']['field_cm_slideshow_image']['table'] = 'field_data_field_cm_slideshow_image';
  $handler->display->display_options['fields']['field_cm_slideshow_image']['field'] = 'field_cm_slideshow_image';
  $handler->display->display_options['fields']['field_cm_slideshow_image']['label'] = '';
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_cm_slideshow_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_slideshow_image']['settings'] = array(
    'image_style' => 'cm_slideshow_mobile',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cm_slideshow_image']['field_api_classes'] = 0;
  /* Sort criterion: Content: Weight (field_cm_weight) */
  $handler->display->display_options['sorts']['field_cm_weight_value']['id'] = 'field_cm_weight_value';
  $handler->display->display_options['sorts']['field_cm_weight_value']['table'] = 'field_data_field_cm_weight';
  $handler->display->display_options['sorts']['field_cm_weight_value']['field'] = 'field_cm_weight_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_slideshow_slide' => 'cm_slideshow_slide',
  );

  /* Display: Home */
  $handler = $view->new_display('block', 'Home', 'block');
  $export['cm_slideshow'] = $view;

  return $export;
}
