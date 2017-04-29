<?php

namespace ContentComponents\Helper;

// @todo add ability to handle fields w/ multiple images.

class ImageHelper {
  public static function getAttributes($entity, $field_name, $image_style, $image_style_placeholder) {
    $image = FALSE;

    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      $alt = '';
      if (isset($entity->{$field_name}[LANGUAGE_NONE][0]['alt'])) {
        $alt = $entity->{$field_name}[LANGUAGE_NONE][0]['alt'];
      }

      $image = array(
        'src' => image_style_url($image_style, $entity->{$field_name}[LANGUAGE_NONE][0]['uri']),
        'placeholder' => image_style_url($image_style_placeholder, $entity->{$field_name}[LANGUAGE_NONE][0]['uri']),
        'alt' => $alt,
      );
    }

    return $image;
  }
}
