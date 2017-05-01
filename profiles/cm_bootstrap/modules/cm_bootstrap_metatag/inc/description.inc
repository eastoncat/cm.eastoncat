<?php

/**
 * Adds paragraph for "description" and "og description" meta tag.
 */
function cm_bootstrap_metatag_description() {
  if ($node = menu_get_object()) {
    if (isset($node->field_content_components[LANGUAGE_NONE])) {
      foreach($node->field_content_components as $items) {
        foreach($items as $item) {
          $item_id = $item['value'];
          $paragraphs[] = entity_load('paragraphs_item', array($item_id));
        }
      }
    }

    $paragraph_types = array(
      'text',
      'text_and_image',
      'text_with_background',
    );

    foreach($paragraphs as $paragraph) {
      // @todo backport this to the search index.
      $paragraph = reset($paragraph);

      //dpm($paragraph);

      if (in_array($paragraph->bundle, $paragraph_types)) {
        switch($paragraph->bundle) {
          case 'text':
            $description = $paragraph->field_cc_text_paragraph[LANGUAGE_NONE][0]['value'];
            break;

          case 'text_and_image':
            $description = $paragraph->field_cc_tai_text[LANGUAGE_NONE][0]['value'];
            break;

          case 'text_with_background':
            $description = $paragraph->field_cc_twb_text[LANGUAGE_NONE][0]['value'];
            break;
        }

        $description = strip_tags($description);
        $description = substr($description,0,155);

        $metatag_description = array(
          '#tag' => 'meta',
          '#attributes' => array(
            'name' => 'description',
            'content' => $description,
          )
        );
        drupal_add_html_head($metatag_description, 'description');

        $og_description = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'property' => 'og:description',
            'content' => $description,
          ),
        );
        drupal_add_html_head($og_description, 'og:description');
      }
      else {
        continue;
      }
    }
  }
}
