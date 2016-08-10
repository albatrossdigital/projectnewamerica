<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function pnaomega_form_alter(&$form, &$form_state, $form_id) {
  switch($form['#id']) {
    case 'views-exposed-form-full-site-search-panel-pane-1':
      $form['#action'] = '/search';
      break;

    case 'views-exposed-form-research-panel-pane-1':
      $form['#action'] = '/research/database';
      break;

    case 'views-exposed-form-bookmarks-panel-pane-1':
      $form['#action'] = '/research/bookmarks';
  }
}


function pnaomega_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );
  if (arg(0) == 'node') {
    $options['query'] = array('nid' => arg(1));
  }

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}




/*function pnaomega_preprocess_views_exposed_form(&$vars) {
  $vars['form']['field_blog_category_tid']['#options']['All'] = 'All';
  dpm($vars);
  $terms = array();
  foreach($entity->field_tags['und'] as $key => $value) {
    $name = $value['taxonomy_term']->name;
    $options = array(
      'query' = array(
        'f[0]' => $value['tid'],
        'blog_search' => '',
      ),
    );
    if($category = $_get['field_blog_category_tid']) {
      $options['']['field_blog_category_tid'] = $category;
    }
    $terms[] = l($name, 'latest', $options);
  }
  foreach($terms as $key => $value) {
    print $value;
  }*/
