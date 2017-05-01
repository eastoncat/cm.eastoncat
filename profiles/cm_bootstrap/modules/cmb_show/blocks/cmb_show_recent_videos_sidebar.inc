<?php

/**
 * Helper function to get block title
 */
function _cmb_show_recent_videos_sidebar_get_title() {
  if ($current_node = menu_get_object()) {
    if (isset($current_node->field_genres[LANGUAGE_NONE])) {
      $title = 'Related Videos';
    }
    else {
      $title = 'Recent Videos';
    }
  }

  return $title;
}

/**
 * Helper function to query and theme recent/related videos
 */
function _cmb_show_recent_videos_sidebar() {
  if ($current_node = menu_get_object()) {
    if (isset($current_node->field_genres[LANGUAGE_NONE])) {
      $genre_nid = $current_node->field_genres[LANGUAGE_NONE][0]['target_id'];
      $nodes = _cmb_show_recent_videos_sidebar_get_related_videos($genre_nid);
    }
    else {
      $nodes = _cmb_show_recent_videos_sidebar_get_recent_videos();
    }
  }

  if ($nodes) {
    foreach ($nodes as $node) {
      if (isset($node->field_show_vod[LANGUAGE_NONE])) {
        // Get media thumbnail image
        // @todo confirm that this actually works for all video providers.
        // Seems to work for Cloudcast and Youtube
        // Once this is confirmed to work, backport to replace all instances of
        // the crappy "switch" hack you did.
        $wrapper = file_stream_wrapper_get_instance_by_uri($node->field_show_vod[LANGUAGE_NONE][0]['uri']);
        $image_uri = $wrapper->getLocalThumbnailPath();
      }
      // No image, so use default cp image.
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $file = cm_bootstrap_cp_default_images_load_image($node->type);
          $image_uri = $file->uri;
        }
      }

      // Description
      if (isset($node->field_description['und'][0]['value'])) {
        $allowable_tags = '<i><a>';
        $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
      }
      else {
        $allowable_tags = '';
        $field_description = '';
      }

      // Topic
      if (isset($node->field_topic['und'][0]['tid'])) {
        $field_topic_term = taxonomy_term_load($node->field_topic['und'][0]['tid']);
        $field_topic_term_name = $field_topic_term->name;
      }
      else {
        $field_topic_term_name = '';
      }

      // Series title
      if (isset($node->og_group_ref['und'][0]['target_id'])) {
        $nid = $node->og_group_ref['und'][0]['target_id'];
        $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
      }
      else {
        $series_title = '';
      }

      // Build data array
      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
        'series' => $field_topic_term_name,
        'series_title' => $series_title,
        'img' => image_style_url('500x281', $image_uri),
      );
    }
  }
  // Send data to TPL.
  return theme('cmb_show_recent_videos_sidebar',
    array (
      'content' => $items,
    )
  );
}

/**
 * Helper function to get related videos
 */
function _cmb_show_recent_videos_sidebar_get_related_videos($genre_nid) {
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'cm_show');
    $query->propertyCondition('status', 1);
    $query->range(0, 25);
    $query->propertyOrderBy('created', 'DESC');
    // Make sure node has an image to display.
    $query->fieldCondition('field_show_vod', 'fid', 'NULL', '!=');
    $query->fieldCondition('field_genres', 'target_id', $genre_nid, '=');
  $result = $query->execute();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  return $nodes;
}

/**
 * Helper function to get recent videos
 */
function _cmb_show_recent_videos_sidebar_get_recent_videos() {
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'cm_show');
    $query->propertyCondition('status', 1);
    $query->range(0, 25);
    $query->propertyOrderBy('created', 'DESC');
    // Make sure node has an image to display.
    $query->fieldCondition('field_show_vod', 'fid', 'NULL', '!=');
  $result = $query->execute();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  return $nodes;
}
