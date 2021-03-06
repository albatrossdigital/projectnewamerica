<?php

/**
 * @file
 * Plugin to provide access control based on solr status
 */

$plugin = array(
  'title' => t('Solr'),
  'description' => t('Is Apache Solr running?'),
  'callback' => 'panopoly_search_solr_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'panopoly_search_solr_ctools_access_settings',
  'summary' => 'panopoly_search_solr_ctools_access_summary',
);

/**
 * Settings form for the 'by parent term' access plugin
 */
function panopoly_search_solr_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check for access.
 */
function panopoly_search_solr_ctools_access_check($conf, $context) {
  $solr_server = search_api_server_load('solr_server');
  return $solr_server->ping();
}

/**
 * Provide a summary description based upon the checked terms.
 */
function panopoly_search_solr_ctools_access_summary($conf, $context) {
  return t('Apache Solr is running');
}
