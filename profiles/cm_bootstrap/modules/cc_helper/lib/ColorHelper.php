<?php

namespace ContentComponents\Helper;

class ColorHelper {
  public static function jqueryColorPicker($entity, $field_name, $rgb = NULL) {
    $color = FALSE;
    $color_value = FALSE;

    if (isset($entity->{$field_name}[LANGUAGE_NONE])) {
      $color_value = $entity->{$field_name}[LANGUAGE_NONE][0]['jquery_colorpicker'];
    }

    // Convert hex to rgb
    if (isset($rgb) && $rgb && $color_value) {
      $color = self::hexToRgb($color_value);
    }
    else {
      $color = '#' . $color_value;
    }

    return $color;
  }

  /**
   * Helper function to convert hex to rgb
   */
  private static function hexToRgb($hex) {
     $hex = str_replace("#", "", $hex);

     if (strlen($hex) == 3) {
       $r = hexdec(substr($hex,0,1).substr($hex,0,1));
       $g = hexdec(substr($hex,1,1).substr($hex,1,1));
       $b = hexdec(substr($hex,2,1).substr($hex,2,1));
     }
     else {
       $r = hexdec(substr($hex,0,2));
       $g = hexdec(substr($hex,2,2));
       $b = hexdec(substr($hex,4,2));
     }

     $rgb = array($r, $g, $b);

     // returns the rgb values separated by commas
     return implode(",", $rgb);
  }
}
