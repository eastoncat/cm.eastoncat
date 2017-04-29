<?php

function _node__page(&$variables) {
  $node = $variables['node'];

  // Legacy mode
  $field_legacy_toggle = TRUE;
  if (isset($node->field_legacy_toggle[LANGUAGE_NONE])) {
    $field_legacy_toggle = $node->field_legacy_toggle[LANGUAGE_NONE][0]['value'];
  }

  if ($field_legacy_toggle) {
    $data = array(
      'legacy' => $field_legacy_toggle,
    );
  }

  // New mode
  else {
    $field_content_components = FALSE;
    if (isset($node->field_content_components[LANGUAGE_NONE])) {
      // Content Components
      foreach($node->field_content_components as $items) {
        foreach($items as $item) {
          $item_id = $item['value'];
          $paragraph = entity_load('paragraphs_item', array($item_id));
          $paragraph_view = entity_view('paragraphs_item', $paragraph, 'full');
          $paragraph_render = drupal_render($paragraph_view);

          // Build array of all content components/paragraphs
          $field_content_components[] = $paragraph_render;
        }
      }
    }

    $data = array(
      'legacy' => FALSE,
      'nid' => $node->nid,
      'title' => $node->title,
      'field_content_components' => $field_content_components,
    );
  }

  $variables['node__page'] = $data;
}
