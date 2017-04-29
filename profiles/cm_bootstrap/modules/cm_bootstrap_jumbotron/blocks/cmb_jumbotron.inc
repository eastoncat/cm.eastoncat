<?php

/**
 * Query to get data and send to TPL
 */
function _cmb_jumbotron() {
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'slider')
    ->propertyCondition('status', 1)
    ->propertyCondition('promote', 1)
    ->range(0, 8);
    // Checks if field is attached to content type, skips if not attached.
    // A fatal exception will be thrown, breaking home pg, if this field is
    // missing from content type.
    if (field_info_instance('node', 'field_slideshow_weight', 'slider')) {
      $query->fieldOrderBy('field_slideshow_weight', 'value', 'ASC');
    }
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach ($nodes as $node) {
      //dpm($node);
      if (isset($node->field_slider_reference['und']) && !isset($node->field_slider_link['und'])) {
        $url = url('node/' . $node->field_slider_reference['und'][0]['target_id']);
      }
      elseif (isset($node->field_slider_link['und'])) {
        $url = $node->field_slider_link['und'][0]['url'];
      }
      else {
        $url = url('node/' . $node->nid);
      }
      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'img' => image_style_url('cmb_jumbotron', $node->field_slideshow_image['und'][0]['uri']),
        'url' => $url,
      );
    }
    // Get color data
    if (module_exists('cm_bootstrap_cp_colors')) {
      $colors = cm_bootstrap_cp_colors_get();
      $jumbotron_overlay_color = cm_bootstrap_cp_colors_hex_to_rgb($colors['jumbotron_overlay_color']);
      $jumbotron_text_color = $colors['jumbotron_text_color'];
      //dpm($jumbotron_overlay_color);
    }
    else {
      $jumbotron_overlay_color = '0,0,0';
    }
    // Send to TPL
    return theme('cmb_jumbotron',
      array (
        'content' => $items,
        'jumbotron_text_color' => $jumbotron_text_color,
        'jumbotron_overlay_color' => $jumbotron_overlay_color,
      )
    );
  }
}
