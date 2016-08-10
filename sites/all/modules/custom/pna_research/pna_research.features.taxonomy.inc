<?php
/**
 * @file
 * pna_research.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pna_research_taxonomy_default_vocabularies() {
  return array(
    'demographic' => array(
      'name' => 'Demographic',
      'machine_name' => 'demographic',
      'description' => 'Used for research.',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'issue' => array(
      'name' => 'Issue',
      'machine_name' => 'issue',
      'description' => 'Used for research.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'news_source' => array(
      'name' => 'News Source',
      'machine_name' => 'news_source',
      'description' => 'For News Items',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'state' => array(
      'name' => 'State',
      'machine_name' => 'state',
      'description' => 'The US state.  Used for research.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'type' => array(
      'name' => 'Type',
      'machine_name' => 'type',
      'description' => 'Used for research.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
