<?php

namespace ContentComponents\Helper;

class FieldHelper {
  public static function getValue($entity, $field_name) {
    $field = FALSE;

    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      $field = $entity->{$field_name}[LANGUAGE_NONE][0]['value'];
    }

    return $field;
  }

  public static function getPathAlias($entity, $field_name, $entity_type) {
    switch($entity_type) {
      case 'node':
        $path_prefix = 'node/';
        break;

      case 'taxonomy_term':
        $path_prefix = 'taxonomy/term/';
        break;
    }

    $link = FALSE;

    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      $link = url(drupal_get_path_alias($path_prefix . $entity->{$field_name}[LANGUAGE_NONE][0]['target_id']));
    }

    return $link;
  }
}
