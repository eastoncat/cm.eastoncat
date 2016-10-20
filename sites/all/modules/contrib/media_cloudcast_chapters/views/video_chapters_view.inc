<?php

/**
 * The view implemented here is an example view dependent on Twitter Bootstrap 3.  The view assumes the 
 * video file with chapters has been added to a content type named cm_show.  In this example, the chapters
 * are displayed in one tab while the field field_show_production_date, the reference to an organic group
 * containing the video, and the content type's tags are displayed in another tab.
 */

/**
 * Implements hook_views_default_views()
 */
function media_cc_chapters_views_default_views() {

  $views = array();
  $view = new view();
  $view->name = 'video_with_chapters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video With Chapters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Media (field_show_vod:fid) */
  $handler->display->display_options['relationships']['field_show_vod_fid']['id'] = 'field_show_vod_fid';
  $handler->display->display_options['relationships']['field_show_vod_fid']['table'] = 'field_data_field_show_vod';
  $handler->display->display_options['relationships']['field_show_vod_fid']['field'] = 'field_show_vod_fid';
  $handler->display->display_options['relationships']['field_show_vod_fid']['required'] = TRUE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_show_vod']['id'] = 'field_show_vod';
  $handler->display->display_options['fields']['field_show_vod']['table'] = 'field_data_field_show_vod';
  $handler->display->display_options['fields']['field_show_vod']['field'] = 'field_show_vod';
  $handler->display->display_options['fields']['field_show_vod']['label'] = '';
  $handler->display->display_options['fields']['field_show_vod']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_show_vod']['element_class'] = 'col-md-8 col-lg-8 col-sm-12';
  $handler->display->display_options['fields']['field_show_vod']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_vod']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_show_vod']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_show_vod']['settings'] = array(
      'file_view_mode' => 'default',
  );
  /* Field: File: Video Chapters */
  $handler->display->display_options['fields']['video_chapters']['id'] = 'video_chapters';
  $handler->display->display_options['fields']['video_chapters']['table'] = 'field_data_video_chapters';
  $handler->display->display_options['fields']['video_chapters']['field'] = 'video_chapters';
  $handler->display->display_options['fields']['video_chapters']['relationship'] = 'field_show_vod_fid';
  $handler->display->display_options['fields']['video_chapters']['label'] = '';
  $handler->display->display_options['fields']['video_chapters']['exclude'] = TRUE;
  $handler->display->display_options['fields']['video_chapters']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['video_chapters']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['video_chapters']['click_sort_column'] = 'cid';
  $handler->display->display_options['fields']['video_chapters']['delta_offset'] = '0';
  $handler->display->display_options['fields']['video_chapters']['separator'] = '';
  $handler->display->display_options['fields']['video_chapters']['field_api_classes'] = TRUE;
  /* Field: Content: Series */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
      'link' => 1,
  );
  /* Field: Content: Production Date */
  $handler->display->display_options['fields']['field_show_production_date']['id'] = 'field_show_production_date';
  $handler->display->display_options['fields']['field_show_production_date']['table'] = 'field_data_field_show_production_date';
  $handler->display->display_options['fields']['field_show_production_date']['field'] = 'field_show_production_date';
  $handler->display->display_options['fields']['field_show_production_date']['label'] = '';
  $handler->display->display_options['fields']['field_show_production_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_show_production_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_production_date']['settings'] = array(
      'format_type' => 'short',
      'fromto' => 'both',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-4 col-lg-4 col-sm-12">
<div role="tabpanel">
  <ul class="nav nav-tabs" role="tablist">
    <li role="presentation" class="active"><a href="#details" aria-controls="details" role="tab" data-toggle="tab">Details</a></li>   
    <li role="presentation"><a href="#chapters" aria-controls="chapters" role="tab" data-toggle="tab">Chapters</a></li>     
  </ul>
  <div class="tab-content">
    <div role="tabpanel" class="tab-pane active" id="details"><strong>Series: </strong>[og_group_ref]<br><strong>Production Date: </strong>[field_show_production_date]<br><strong>Tags: </strong>[field_tags]</div>
    <div role="tabpanel" class="tab-pane" id="chapters">[video_chapters]</div>
  </div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
      'cm_show' => 'cm_show',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  
  $views[$view->name] = $view;
  return $views;
}
