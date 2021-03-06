<?php
/**
 * @file
 * reach_donation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function reach_donation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function reach_donation_node_info() {
  $items = array(
    'donation' => array(
      'name' => t('Donation'),
      'base' => 'node_content',
      'description' => t('Donations are a type of form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
