<?php
/**
 * @file
 * reach_administration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function reach_administration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function reach_administration_views_api() {
  return array("version" => "3.0");
}
