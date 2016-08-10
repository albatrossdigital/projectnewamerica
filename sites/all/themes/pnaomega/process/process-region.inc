<?php 

/**
 * Implements hook_process_region().
 */
function pnaomega_alpha_process_region(&$vars) {
  if ($vars['elements']['#region'] == 'content') {
    $theme = alpha_get_theme();
    $vars['columns'] = $vars['elements']['#grid']['columns'];
    $vars['messages'] = $theme->page['messages'];
  }
}
