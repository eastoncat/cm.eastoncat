<?php
/**
 * @file
 * cm_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cm_profile_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cm_profile_certifications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'Profile: Certifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Certifications';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No certifications';
  $handler->display->display_options['empty']['area']['format'] = '2';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: CiviCRM Contacts: Drupal ID */
  $handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
  $handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['required'] = 1;
  /* Field: CiviCRM Groups: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'civicrm_group';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['empty'] = 'No certifications yet';
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 1;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  /* Sort criterion: CiviCRM Groups: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'civicrm_group';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'drupal_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: CiviCRM Groups: Group ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'civicrm_group';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['operator'] = '!=';
  $handler->display->display_options['filters']['id']['value']['value'] = '1';
  /* Filter criterion: CiviCRM Groups: Group ID */
  $handler->display->display_options['filters']['id_1']['id'] = 'id_1';
  $handler->display->display_options['filters']['id_1']['table'] = 'civicrm_group';
  $handler->display->display_options['filters']['id_1']['field'] = 'id';
  $handler->display->display_options['filters']['id_1']['operator'] = '!=';
  $handler->display->display_options['filters']['id_1']['value']['value'] = '2';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['cm_profile_certifications'] = $view;

  $view = new view;
  $view->name = 'cm_profile_member_since';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_membership';
  $view->human_name = 'Profile: Member Since';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Member Since';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: CiviCRM Contacts: Drupal ID */
  $handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
  $handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
  $handler->display->display_options['relationships']['drupal_id']['required'] = 0;
  /* Field: CiviCRM Member: Membership ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_membership';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['id']['format_plural'] = 0;
  /* Field: CiviCRM Member: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'civicrm_membership';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['label'] = '';
  $handler->display->display_options['fields']['start_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['start_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['start_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['start_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['start_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['start_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['start_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['start_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['start_date']['custom_date_format'] = 'F Y';
  /* Field: CiviCRM Member: Membership Type */
  $handler->display->display_options['fields']['membership_type']['id'] = 'membership_type';
  $handler->display->display_options['fields']['membership_type']['table'] = 'civicrm_membership';
  $handler->display->display_options['fields']['membership_type']['field'] = 'membership_type';
  $handler->display->display_options['fields']['membership_type']['label'] = '';
  $handler->display->display_options['fields']['membership_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['membership_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['membership_type']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['membership_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['membership_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['membership_type']['hide_alter_empty'] = 0;
  /* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
  $handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
  $handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
  $handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
  $handler->display->display_options['arguments']['uf_id']['relationship'] = 'drupal_id';
  $handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uf_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uf_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uf_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uf_id']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['cm_profile_member_since'] = $view;

  $view = new view;
  $view->name = 'cm_profile_projects';
  $view->description = 'Show groups of a user.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'Profile: Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No active projects';
  $handler->display->display_options['empty']['area']['format'] = '2';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: OG group: OG group from Node */
  $handler->display->display_options['relationships']['og_rel']['id'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_rel']['field'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['required'] = 0;
  /* Relationship: OG group: OG membership from OG group */
  $handler->display->display_options['relationships']['og_membership']['id'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership']['table'] = 'og';
  $handler->display->display_options['relationships']['og_membership']['field'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership']['relationship'] = 'og_rel';
  $handler->display->display_options['relationships']['og_membership']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: We pass to the &quot;Entity ID&quot; the User ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass to the "Entity ID" the User ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['etid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['etid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['etid']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['etid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['etid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['etid']['not'] = 0;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['cm_profile_projects'] = $view;

  return $export;
}
