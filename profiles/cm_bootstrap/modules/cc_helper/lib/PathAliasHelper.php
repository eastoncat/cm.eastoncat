<?php

namespace ContentComponents\Helper;

class PathAliasHelper {
  public static function getPath($entity_id, $entity_type) {
    switch($entity_type) {
      case 'node':
        $path_prefix = '/node/';
        break;

      case 'taxonomy_term':
        $path_prefix = '/taxonomy/term/';
        break;
    }


  }
}
