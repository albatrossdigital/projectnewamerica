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
function pna_users_rules_event_info() {
  return array(
    'pna_users_user_login_ip' => array(
      'label' => t('User logs in (with ip)'),
      'group' => t('PNA'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('user')),
        'contact' => array('type' => 'redhen_contact', 'label' => t('contact')),
        'isnew' => array('type' => 'text', 'label' => t('isnew')),
        'ip_address' => array('type' => 'text', 'label' => t('ip_address')),
        'points' => array('type' => 'integer', 'label' => t('points')),
      ),
    ),
  );
}


