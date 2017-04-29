<?php

/**
 * Adds paragraph for "og image" meta tag.
 */
function cm_bootstrap_metatag_page_image() {
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
      'image',
      'text_and_image',
    );

    foreach($paragraphs as $paragraph) {
      // @todo backport this to the search index.
      $paragraph = reset($paragraph);

      if (in_array($paragraph->bundle, $paragraph_types)) {
        switch($paragraph->bundle) {
          case 'image':
            $img_src = FALSE;
            if (isset($paragraph->field_cc_image[LANGUAGE_NONE])) {
              $img_src = image_style_url('cc_slider_image', $paragraph->field_cc_image[LANGUAGE_NONE][0]['uri']);
            }
            break;
        }
      }
    }

    $og_image = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image',
        'content' => $img_src,
      ),
    );
    drupal_add_html_head($og_image, 'og:image');

  }
}
