<?php
/**
 * @file
 * om_crew_connect.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function om_crew_connect_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'om_crew_connect_find';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Crew Connect: Find';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Connect: Find';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Find a Crew with These Skills';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="messages warning">We were unable to find anyone with the skills you are looking for willing to volunteer at this time.</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = 0;
  /* Field: Global: Send E-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_send']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_send']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_send']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_send']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_send']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_send']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_send']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_send']['hide_alter_empty'] = 1;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'user';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[picture]
[name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Profile: Types of Projects You'd Volunteer For */
  $handler->display->display_options['fields']['field_volunteer_for']['id'] = 'field_volunteer_for';
  $handler->display->display_options['fields']['field_volunteer_for']['table'] = 'field_data_field_volunteer_for';
  $handler->display->display_options['fields']['field_volunteer_for']['field'] = 'field_volunteer_for';
  $handler->display->display_options['fields']['field_volunteer_for']['label'] = 'Types of Projects I\'d Volunteer For';
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_volunteer_for']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_volunteer_for']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_volunteer_for']['field_api_classes'] = 0;
  /* Filter criterion: Profile: Camera (field_skill_camera) */
  $handler->display->display_options['filters']['field_skill_camera_value']['id'] = 'field_skill_camera_value';
  $handler->display->display_options['filters']['field_skill_camera_value']['table'] = 'field_data_field_skill_camera';
  $handler->display->display_options['filters']['field_skill_camera_value']['field'] = 'field_skill_camera_value';
  $handler->display->display_options['filters']['field_skill_camera_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['operator_id'] = 'field_skill_camera_value_op';
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['label'] = 'Camera';
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['operator'] = 'field_skill_camera_value_op';
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['identifier'] = 'field_skill_camera_value';
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_skill_camera_value']['expose']['reduce'] = 0;
  /* Filter criterion: Profile: I am willing to volunteer (field_volunteer) */
  $handler->display->display_options['filters']['field_volunteer_value']['id'] = 'field_volunteer_value';
  $handler->display->display_options['filters']['field_volunteer_value']['table'] = 'field_data_field_volunteer';
  $handler->display->display_options['filters']['field_volunteer_value']['field'] = 'field_volunteer_value';
  $handler->display->display_options['filters']['field_volunteer_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'om_crew_connect_find');
  $handler->display->display_options['path'] = 'crew-connect/find';
  $export['om_crew_connect_find'] = $view;

  $view = new view;
  $view->name = 'om_crew_connect_my_skills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Crew Connect: My Skills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Connect: My Skills';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Profile: Camera */
  $handler->display->display_options['fields']['field_skill_camera']['id'] = 'field_skill_camera';
  $handler->display->display_options['fields']['field_skill_camera']['table'] = 'field_data_field_skill_camera';
  $handler->display->display_options['fields']['field_skill_camera']['field'] = 'field_skill_camera';
  $handler->display->display_options['fields']['field_skill_camera']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_skill_camera']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_skill_camera']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_skill_camera']['field_api_classes'] = 0;
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['user']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['user']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['user']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['om_crew_connect_my_skills'] = $view;

  return $export;
}
