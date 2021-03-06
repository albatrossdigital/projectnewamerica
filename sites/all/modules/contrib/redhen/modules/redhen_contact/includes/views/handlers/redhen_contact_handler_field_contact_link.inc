<?php

/**
 * Field handler to present a link to the contact.
 */
class redhen_contact_handler_field_contact_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['contact_id'] = 'contact_id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    return $this->render_link(check_plain($values->{$this->aliases['contact_id']}), $values);
  }

  function render_link($data, $values) {
    $contact_id = $values->{$this->aliases['contact_id']};
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "redhen/contact/$contact_id";
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    return $text;
  }
}
