<?php

namespace ContentComponents\Helper;

class ParagraphHelper {
  public static function getChildren($entity, $field_name) {
    $items = FALSE;

    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      foreach ($entity->{$field_name}[LANGUAGE_NONE] as $item) {
        $item_id = $item['value'];
        $p_item = entity_load('paragraphs_item', array($item_id));
        $p_item = reset($p_item);
        $items[] = $p_item;
      }
    }

    return $items;
  }
}
