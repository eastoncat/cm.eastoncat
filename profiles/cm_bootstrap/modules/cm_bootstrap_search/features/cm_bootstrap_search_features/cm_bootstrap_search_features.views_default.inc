<?php
/**
 * @file
 * cm_bootstrap_search_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cm_bootstrap_search_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solr_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_site_search_index';
  $view->human_name = 'Solr Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solr Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_index';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_term';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '4';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_cmbs_producer_bio' => 'field_cmbs_producer_bio',
    'field_cmbs_producer_email' => 'field_cmbs_producer_email',
    'field_cmbs_producer_phone' => 'field_cmbs_producer_phone',
    'field_content_components:field_cc_cl_description' => 'field_content_components:field_cc_cl_description',
    'field_content_components:field_cc_cl_item_abstract' => 'field_content_components:field_cc_cl_item_abstract',
    'field_content_components:field_cc_cl_item_title' => 'field_content_components:field_cc_cl_item_title',
    'field_content_components:field_cc_s_title' => 'field_content_components:field_cc_s_title',
    'field_content_components:field_cc_tai_text:value' => 'field_content_components:field_cc_tai_text:value',
    'field_content_components:field_cc_text_paragraph:value' => 'field_content_components:field_cc_text_paragraph:value',
    'field_content_components:field_cc_twb_text:value' => 'field_content_components:field_cc_twb_text:value',
    'field_description:summary' => 'field_description:summary',
    'field_description:value' => 'field_description:value',
    'field_show_participants:name' => 'field_show_participants:name',
    'field_tags:description' => 'field_tags:description',
    'field_tags:name' => 'field_tags:name',
    'field_teaser' => 'field_teaser',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'page' => 'page',
    'blog' => 'blog',
    'cmbs_event' => 'cmbs_event',
    'genre' => 'genre',
    'cmbs_producer' => 'cmbs_producer',
    'cm_project' => 'cm_project',
    'cm_show' => 'cm_show',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'One of the Type(s)';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'node_type';
  $handler->display->display_options['filters']['type_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = 1;
  /* Filter criterion: Containing any of the words */
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['id'] = 'search_api_views_fulltext_1';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['ui_name'] = 'Containing any of the words';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['operator_id'] = 'search_api_views_fulltext_1_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['label'] = 'Containing any of the words';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['operator'] = 'search_api_views_fulltext_1_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['identifier'] = 'search_api_views_fulltext_1';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_cmbs_producer_bio' => 'field_cmbs_producer_bio',
    'field_cmbs_producer_email' => 'field_cmbs_producer_email',
    'field_cmbs_producer_phone' => 'field_cmbs_producer_phone',
    'field_content_components:field_cc_cl_description' => 'field_content_components:field_cc_cl_description',
    'field_content_components:field_cc_cl_item_abstract' => 'field_content_components:field_cc_cl_item_abstract',
    'field_content_components:field_cc_cl_item_title' => 'field_content_components:field_cc_cl_item_title',
    'field_content_components:field_cc_s_title' => 'field_content_components:field_cc_s_title',
    'field_content_components:field_cc_tai_text:value' => 'field_content_components:field_cc_tai_text:value',
    'field_content_components:field_cc_text_paragraph:value' => 'field_content_components:field_cc_text_paragraph:value',
    'field_content_components:field_cc_twb_text:value' => 'field_content_components:field_cc_twb_text:value',
    'field_description:summary' => 'field_description:summary',
    'field_description:value' => 'field_description:value',
    'field_show_participants:name' => 'field_show_participants:name',
    'field_tags:description' => 'field_tags:description',
    'field_tags:name' => 'field_tags:name',
    'field_teaser' => 'field_teaser',
    'title' => 'title',
  );
  /* Filter criterion: Containing the phrase */
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['id'] = 'search_api_views_fulltext_2';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['ui_name'] = 'Containing the phrase';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['expose']['operator_id'] = 'search_api_views_fulltext_2_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['expose']['label'] = 'Containing the phrase';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['expose']['operator'] = 'search_api_views_fulltext_2_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['expose']['identifier'] = 'search_api_views_fulltext_2';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['mode'] = 'filter';
  $handler->display->display_options['filters']['search_api_views_fulltext_2']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_cmbs_producer_bio' => 'field_cmbs_producer_bio',
    'field_cmbs_producer_email' => 'field_cmbs_producer_email',
    'field_cmbs_producer_phone' => 'field_cmbs_producer_phone',
    'field_content_components:field_cc_cl_description' => 'field_content_components:field_cc_cl_description',
    'field_content_components:field_cc_cl_item_abstract' => 'field_content_components:field_cc_cl_item_abstract',
    'field_content_components:field_cc_cl_item_title' => 'field_content_components:field_cc_cl_item_title',
    'field_content_components:field_cc_s_title' => 'field_content_components:field_cc_s_title',
    'field_content_components:field_cc_tai_text:value' => 'field_content_components:field_cc_tai_text:value',
    'field_content_components:field_cc_text_paragraph:value' => 'field_content_components:field_cc_text_paragraph:value',
    'field_content_components:field_cc_twb_text:value' => 'field_content_components:field_cc_twb_text:value',
    'field_description:summary' => 'field_description:summary',
    'field_description:value' => 'field_description:value',
    'field_show_participants:name' => 'field_show_participants:name',
    'field_tags:description' => 'field_tags:description',
    'field_tags:name' => 'field_tags:name',
    'field_teaser' => 'field_teaser',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['path'] = 'solr-search';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['views_ef_fieldset']['enabled'] = TRUE;
  $handler->display->display_options['views_ef_fieldset']['options'] = array(
    'sort' => array(
      'root' => array(
        'weight' => '0',
        'type' => 'container',
        'id' => 'root',
        'pid' => '',
        'depth' => 0,
        'container_type' => 'container',
        'title' => 'Filters',
        'description' => '',
        'collapsible' => 0,
        'collapsed' => 0,
      ),
      'search_api_views_fulltext' => array(
        'weight' => '-11',
        'type' => 'filter',
        'id' => 'search_api_views_fulltext',
        'pid' => 'root',
        'depth' => 1,
      ),
      'container-0' => array(
        'weight' => '-10',
        'type' => 'container',
        'id' => 'container-0',
        'pid' => 'root',
        'depth' => 1,
        'container_type' => 'fieldset',
        'title' => 'Advanced Search',
        'description' => '',
        'collapsible' => 1,
        'collapsed' => 1,
      ),
      'type_1' => array(
        'weight' => '-11',
        'type' => 'filter',
        'id' => 'type_1',
        'pid' => 'container-0',
        'depth' => 2,
      ),
      'search_api_views_fulltext_1' => array(
        'weight' => '-10',
        'type' => 'filter',
        'id' => 'search_api_views_fulltext_1',
        'pid' => 'container-0',
        'depth' => 2,
      ),
      'search_api_views_fulltext_2' => array(
        'weight' => '-9',
        'type' => 'filter',
        'id' => 'search_api_views_fulltext_2',
        'pid' => 'container-0',
        'depth' => 2,
      ),
      'submit' => array(
        'weight' => '-6',
        'type' => 'buttons',
        'id' => 'submit',
        'pid' => 'root',
        'depth' => 1,
      ),
      'container-1' => array(
        'weight' => '-5',
        'type' => 'container',
        'id' => 'container-1',
        'pid' => 'root',
        'depth' => 1,
        'container_type' => 'fieldset',
        'title' => 'Container 1',
        'description' => '',
        'collapsible' => 0,
        'collapsed' => 0,
      ),
      'container-2' => array(
        'weight' => '-4',
        'type' => 'container',
        'id' => 'container-2',
        'pid' => 'root',
        'depth' => 1,
        'container_type' => 'fieldset',
        'title' => 'Container 2',
        'description' => '',
        'collapsible' => 0,
        'collapsed' => 0,
      ),
      'container-3' => array(
        'weight' => '-3',
        'type' => 'container',
        'id' => 'container-3',
        'pid' => 'root',
        'depth' => 1,
        'container_type' => 'fieldset',
        'title' => 'Container 3',
        'description' => '',
        'collapsible' => 0,
        'collapsed' => 0,
      ),
      'container-4' => array(
        'weight' => '-2',
        'type' => 'container',
        'id' => 'container-4',
        'pid' => 'root',
        'depth' => 1,
        'container_type' => 'fieldset',
        'title' => 'Container 4',
        'description' => '',
        'collapsible' => 0,
        'collapsed' => 0,
      ),
    ),
  );
  $export['solr_search'] = $view;

  return $export;
}
