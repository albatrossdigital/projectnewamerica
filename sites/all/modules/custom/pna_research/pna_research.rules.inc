<?php

/**
 * @file
 *  Rules integration for reach_crm module.
 *
 */

/************************** Rules Events **************************************/

/**
 * Implements hook_rules_event_info().
 */
function pna_research_rules_event_info() {
  return array(
    'pna_research_file_downloaded' => array(
      'label' => t('File Downloaded'),
      'group' => t('system'),
      'variables' => array(
        'node' => array('type' => 'node', 'label' => t('node')),
        //'contact' => array('type' => 'redhen_contact', 'label' => t('contact')),
        //'filename' => array('type' => 'text', 'label' => t('filename')),
      ),
    ),
    'pna_research_file_downloaded_contact' => array(
      'label' => t('File Downloaded with contact info'),
      'group' => t('system'),
      'variables' => array(
        'node' => array('type' => 'node', 'label' => t('node')),
        'contact' => array('type' => 'redhen_contact', 'label' => t('contact')),
        'filename' => array('type' => 'text', 'label' => t('filename')),
      ),
    ),
  );
}


