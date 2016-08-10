<?php
/**
 * @file
 * pna_research.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pna_research_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'research';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Research';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Research';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_research_category']['id'] = 'field_research_category';
  $handler->display->display_options['fields']['field_research_category']['table'] = 'field_data_field_research_category';
  $handler->display->display_options['fields']['field_research_category']['field'] = 'field_research_category';
  $handler->display->display_options['fields']['field_research_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_research_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_research_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_research_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_research_category']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_research_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_research_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_research_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_research_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_research_category']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['created_year_month']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['base_path'] = 'research';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
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
    'research' => 'research',
  );
  /* Filter criterion: Content: Demographic (field_research_demographic) */
  $handler->display->display_options['filters']['field_research_demographic_tid']['id'] = 'field_research_demographic_tid';
  $handler->display->display_options['filters']['field_research_demographic_tid']['table'] = 'field_data_field_research_demographic';
  $handler->display->display_options['filters']['field_research_demographic_tid']['field'] = 'field_research_demographic_tid';
  $handler->display->display_options['filters']['field_research_demographic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['operator_id'] = 'field_research_demographic_tid_op';
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['label'] = 'Demographic';
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['operator'] = 'field_research_demographic_tid_op';
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['identifier'] = 'demographic';
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_research_demographic_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_research_demographic_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_research_demographic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_research_demographic_tid']['vocabulary'] = 'demographic';
  $handler->display->display_options['filters']['field_research_demographic_tid']['error_message'] = 1;
  /* Filter criterion: Content: Issue (field_research_issue) */
  $handler->display->display_options['filters']['field_research_issue_tid']['id'] = 'field_research_issue_tid';
  $handler->display->display_options['filters']['field_research_issue_tid']['table'] = 'field_data_field_research_issue';
  $handler->display->display_options['filters']['field_research_issue_tid']['field'] = 'field_research_issue_tid';
  $handler->display->display_options['filters']['field_research_issue_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['operator_id'] = 'field_research_issue_tid_op';
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['label'] = 'Issue';
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['operator'] = 'field_research_issue_tid_op';
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['identifier'] = 'issue';
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_research_issue_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_research_issue_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_research_issue_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_research_issue_tid']['vocabulary'] = 'issue';
  $handler->display->display_options['filters']['field_research_issue_tid']['error_message'] = 1;
  /* Filter criterion: Content: State (field_research_state) */
  $handler->display->display_options['filters']['field_research_state_tid']['id'] = 'field_research_state_tid';
  $handler->display->display_options['filters']['field_research_state_tid']['table'] = 'field_data_field_research_state';
  $handler->display->display_options['filters']['field_research_state_tid']['field'] = 'field_research_state_tid';
  $handler->display->display_options['filters']['field_research_state_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['operator_id'] = 'field_research_state_tid_op';
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['operator'] = 'field_research_state_tid_op';
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_research_state_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_research_state_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_research_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_research_state_tid']['vocabulary'] = 'state';
  $handler->display->display_options['filters']['field_research_state_tid']['error_message'] = 1;
  /* Filter criterion: Content: Type (field_research_type) */
  $handler->display->display_options['filters']['field_research_type_tid']['id'] = 'field_research_type_tid';
  $handler->display->display_options['filters']['field_research_type_tid']['table'] = 'field_data_field_research_type';
  $handler->display->display_options['filters']['field_research_type_tid']['field'] = 'field_research_type_tid';
  $handler->display->display_options['filters']['field_research_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['operator_id'] = 'field_research_type_tid_op';
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['operator'] = 'field_research_type_tid_op';
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_research_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_research_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_research_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_research_type_tid']['vocabulary'] = 'type';
  $handler->display->display_options['filters']['field_research_type_tid']['error_message'] = 1;

  /* Display: Block: Monthly filter  */
  $handler = $view->new_display('block', 'Block: Monthly filter ', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Month';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['created_year_month']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['base_path'] = 'research';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Research monthly filter';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $export['research'] = $view;

  return $export;
}
