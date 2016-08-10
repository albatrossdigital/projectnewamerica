<?php
/**
 * @file
 * pna_research.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pna_research_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_subscribers';
  $feeds_importer->config = array(
    'name' => 'Import Subscribers',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsEntityProcessorRedhen_contact',
      'config' => array(
        'values' => array(
          'type' => 'subscriber',
        ),
        'mappings' => array(
          0 => array(
            'source' => 'First Name',
            'target' => 'first_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Last Name',
            'target' => 'last_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Organization/Affiliation',
            'target' => 'field_group',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Title',
            'target' => 'field_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'E-mail Address',
            'target' => 'redhen_contact_email:email',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Membership Type',
            'target' => 'field_membership_type',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Notes',
            'target' => 'field_notes',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_subscribers'] = $feeds_importer;

  return $export;
}
