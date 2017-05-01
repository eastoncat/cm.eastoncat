<?php

function _cmb_cb_shows_in_series() {
  if ($current_node = menu_get_object()) {
    switch($current_node->type) {
      case 'cm_show':
        if (isset($current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
          $nid = $current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        }
        break;
      case 'cm_project':
        $nid = $current_node->nid;
        break;
    }
    // Data query
    $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'cm_show');
      $query->propertyCondition('status', 1);
      $query->range(0, 100);
      $query->propertyOrderBy('created', 'DESC');
      $query->fieldCondition('og_group_ref', 'target_id', $nid, '=');
    $result = $query->execute();
    //
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = entity_load('node', $nids);
      foreach($nodes as $node) {
        // Switch to account for cloudcast, vimeo, youtube, etc.
        if (isset($node->field_show_vod['und'])) {
          //dpm($node);
          switch($node->field_show_vod['und'][0]['filemime']) {
            case 'video/cloudcast':
              $image_uri = 'media-cloudcast/' . $node->field_show_vod['und'][0]['filename']  . '.jpg';
              break;
            case 'video/vimeo':
              $image_uri = str_replace('vimeo://v/', 'media-vimeo/', $node->field_show_vod['und'][0]['uri']);
              $image_uri = $image_uri . '.jpg';
              break;
            case 'video/youtube':
              $image_uri = str_replace('youtube://v/', 'media-youtube/', $node->field_show_vod['und'][0]['uri']);
              $image_uri = $image_uri . '.jpg';
              break;
            case 'video/bliptv':
              $image_uri = str_replace('bliptv://i/BiCities-AubreyThornvoldReconcilingWorksFilmed201502703.png/v/', 'media-bliptv/', $node->field_show_vod['und'][0]['uri']);
              $image_uri = $image_uri . '.jpg';
              break;
          }
        }
        else {
          if (module_exists('cm_bootstrap_cp_default_images')) {
            $file = cm_bootstrap_cp_default_images_load_image($node->type);
            $image_uri = $file->uri;
          }
        }
        // Strip tags
        $allowable_tags = '';
        if (isset($node->field_description['und'][0]['value'])) {
          $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
        }
        else {
          $field_description = '';
        }
        // Build data array for TPL
        $items[$node->nid] = array(
          'nid' => $node->nid,
          'title' => $node->title,
          'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),  
          'img' => image_style_url('500x281', $image_uri),
        );
      }
      // Send $items array to TPL.
      return theme('cmb_cb_shows_in_series',
        array (
          'content' => $items,
        )
      );
    }
  }
}
