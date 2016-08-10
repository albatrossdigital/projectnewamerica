<?php
// advances created date +1 day
// makes field downloadable if necessary
// updates uid to PNA Staff user

$node->changed = 86400;
$node = $entity;
if (count($node->field_research_files['und']) > 1) {
  $node->field_download['und'][0]['download_fields'] = array('field_research_files' => 'field_research_files');
  $node->field_download['und'][0]['download_label'] = 'Download All';
}

$node->uid = 41;

node_save($node);
