<?php
/**
 * @file
 * Class definition of FeedsentityProcessor.
 */

/**
 * Creates entities from feed items.
 */
class FeedsEntityProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    $importer = feeds_importer($this->id);
    $plugin_key = $importer->config['processor']['plugin_key'];
    $plugin_info = ctools_get_plugins('feeds', 'plugins', $plugin_key);
    return $plugin_info['type'];
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info += array('label plural' => $info['label']);
    return $info;
  }

  /**
   * Creates a new entity in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $entity = entity_property_values_create_entity($this->entityType(), $this->config['values'])->value();
    $entity->language = LANGUAGE_NONE;
    return $entity;
  }

  /**
   * Loads an existing entity.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the entity
   * table will be loaded, foregoing the entity_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $id) {
    $result = entity_load($this->entityType(), array($id));
    return reset($result);
  }

  /**
   * Save a entity.
   */
  public function entitysave($entity) {
    entity_save($this->entityType(), $entity);
  }

  /**
   * Delete a series of entities.
   */
  protected function entityDeleteMultiple($ids) {
    entity_delete_multiple($this->entityType(), $ids);
  }
  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'values' => array(),
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['values']['#tree'] = TRUE;
    $form['input_format']['#description'] = t('Select the input format for the %entity to be created.', array('%entity' => $this->entityType()));

    $wrapper = entity_metadata_wrapper($this->entityType());
    foreach ($wrapper->getPropertyInfo() as $name => $property) {
      if (!empty($property['required'])) {
        $form['values'][$name] = array(
          '#type' => 'textfield',
          '#title' => $property['label'],
          '#description' => isset($property['description']) ? $property['description'] : '',
          '#default_value' => isset($this->config['values'][$name]) ? $this->config['values'][$name] : NULL,
          '#required' => TRUE,
        );
        if (!empty($property['options list'])) {
          $form['values'][$name]['#type'] = 'select';
          $form['values'][$name]['#options'] = $wrapper->$name->optionsList();
        }
        // @todo: Maybe implement per data-type forms like Rules does?
        $form['values'][$name]['#description'] .= ' ' . t('Expected data type: %type.', array('%type' => $wrapper->$name->type()));
        if ($wrapper->$name instanceof EntityDrupalWrapper) {
          $info = $wrapper->$name->entityInfo();
          $id_info = $wrapper->$name->get($info['entity keys']['id'])->info();
          $form['values'][$name]['#description'] .= ' ' . t('Just enter the identifier of the entity, i.e. %id', array('%id' => $id_info['label']));
        }
      }
    }

    // Manually add the bundle (type) field if it hasn't been added
    if (empty($form['values']['type'])) {
      $entity_info = $this->entityInfo();
      if (is_array($entity_info['bundles'])) {
        foreach ($entity_info['bundles'] as $type => $bundle_info) {
          $types[$type] = $bundle_info['label'];
        }
        $form['values'][$entity_info['entity keys']['bundle']] = array(
          '#type' => 'select',
          '#title' => t(ucwords($entity_info['entity keys']['bundle'])),
          '#options' => $types,
          '#required' => TRUE,
          '#default_value' => is_array($this->config['values']) ? $this->config['values'][$entity_info['entity keys']['bundle']] : NULL,
        );
      }
    }

    return $form;
  }

  public function configFormSubmit(&$values) {
    parent::configFormSubmit($values);
  }

  /**
   * Override setTargetElement to operate on a target item that is a entity.
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    $wrapper = entity_metadata_wrapper($this->entityType(), $target_item);
    switch ($target_element) {
      case 'url':
      case 'guid':
        $target_item->feeds_item->$target_element = $value;
        break;
      default:
        $wrapper->$target_element->set($value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    // Get a wrapper with the right bundle info.
    $entity_info = $this->entityInfo();
    $info = array('bundle' => NULL);

    if (isset($entity_info['entity keys']['bundle']) && isset($this->config['values'][$entity_info['entity keys']['bundle']])) {
      $info['bundle'] = $this->config['values'][$entity_info['entity keys']['bundle']];
    }
    else {
      $info['bundle'] = $this->entityType();
    }

    $wrapper = entity_metadata_wrapper($this->entityType(), NULL, $info);
    // @todo: maybe restrict to data types feeds can deal with.
    dpm($wrapper->getPropertyInfo());
    foreach ($wrapper->getPropertyInfo() as $name => $property) {

      if (!empty($property['setter callback'])) {
        $targets[$name] = array(
          'name' => $property['label'],
          'description' => isset($property['description']) ? $property['description'] : NULL,
        );
      }
    }

    $targets[$entity_info['entity keys']['id']]['optional_unique'] = TRUE;

    // Add general GUID target
    $targets['guid'] = array(
      'name' => t('GUID'),
      'description' => t('The globally unique identifier of the item. E. g. the feed item GUID in the case of a syndication feed. May be unique.'),
      'optional_unique' => TRUE,
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    $type = $this->entityType();
    drupal_alter('feeds_processor_targets', $targets, $type, $info['bundle']);

    return $targets;
  }
}
