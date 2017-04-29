<?php

function _cmb_show_chapters() {
  if ($node = menu_get_object()) {
    // Need to check if this field exists / is attached to cm_show nodes,
    // RETN does not use this field.
    if (db_table_exists('field_data_video_chapters')) {
      if (isset($node->field_show_vod['und'])) {
        $field_show_vod_fid = $node->field_show_vod['und'][0]['fid'];
        // Get chapters data
        $result = db_query("SELECT * FROM {field_data_video_chapters} WHERE entity_id = :entity_id", array(':entity_id' => $field_show_vod_fid))->fetchAll();
        if ($result) {
          //dpm('field_data_video_chapters');
          $chapter_type = 'chapter';
          foreach($result as $item) {
            $items[] = $item;
          }
        }
      }
    }

    // For RETN type site that uses cue_points
    if (db_table_exists('field_data_cue_points')) {
      $field_show_vod_fid = $node->field_show_vod['und'][0]['fid'];
      $result = db_query("SELECT * FROM {field_data_cue_points} WHERE entity_id = :entity_id", array(':entity_id' => $field_show_vod_fid))->fetchAll();
      if ($result) {
        $chapter_type = 'cue_point';
        foreach($result as $item) {
          $fc_items = entity_load('field_collection_item', array($item->cue_points_value));
          foreach($fc_items as $fc_item) {
            $items[] = array(
              'nid' => $node->nid,
              'fid' => $field_show_vod_fid,
              'start' => $fc_item->cue_field_start['und'][0]['value'],
              'title' => $fc_item->cue_field_title['und'][0]['value'],
              'description' => $fc_item->field_cue_field_description['und'][0]['value']
            );
          }
        }
      }
    }

    if (isset($items)) {
      switch($chapter_type) {
        case 'chapter':
          return theme('cmb_show_chapters',
            array (
              'content' => $items,
            )
          );
          break;
        case 'cue_point':
          return theme('cmb_show_cue_points',
            array (
              'content' => $items,
            )
          );
          break;
      }
    }
  }
}
