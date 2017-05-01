<?php

function _cmb_cb_genre_carousel() {
  if ($current_node = menu_get_object()) {
    if ($current_node->type == 'genre') {
      // Get all shows tagged with current node 'genre'.
      $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node');
        $query->entityCondition('bundle', 'cm_show');
        $query->propertyCondition('status', 1);
        $query->fieldCondition('field_genres', 'target_id', $current_node->nid, '=');
        $query->range(0, 25);
        $query->propertyOrderBy('created', 'DESC');
      $result = $query->execute();

      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = entity_load('node', $nids);

        // Placeholder image
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $p_file = cm_bootstrap_cp_default_images_load_image('cm_show');
          if ($p_file) {
            $p_image_uri = $p_file->uri;
            $placeholder_img = image_style_url('500x281', $p_image_uri);
          }
        }

        foreach ($nodes as $node) {
          // Image
          $img_src = FALSE;
          if (isset($node->field_show_vod[LANGUAGE_NONE])) {
            switch($node->field_show_vod[LANGUAGE_NONE][0]['filemime']) {
              case 'video/cloudcast':
                $image_uri = 'media-cloudcast/' . $node->field_show_vod[LANGUAGE_NONE][0]['filename']  . '.jpg';
                break;
              case 'video/vimeo':
                $image_uri = str_replace('vimeo://v/', 'media-vimeo/', $node->field_show_vod[LANGUAGE_NONE][0]['uri']);
                $image_uri = $image_uri . '.jpg';
                break;
              case 'video/youtube':
                $image_uri = str_replace('youtube://v/', 'media-youtube/', $node->field_show_vod[LANGUAGE_NONE][0]['uri']);
                $image_uri = $image_uri . '.jpg';
                break;
            }
            $img_src = image_style_url('500x281', $image_uri);
          }
          else {
            if (module_exists('cm_bootstrap_cp_default_images')) {
              $file = cm_bootstrap_cp_default_images_load_image($node->type);
              $image_uri = $file->uri;
              $img_src = image_style_url('500x281', $image_uri);
            }
          }

          // Description
          $description = FALSE;
          $allowable_tags = '<i>';
          if (isset($node->field_description[LANGUAGE_NONE])) {
            $description = strip_tags($node->field_description[LANGUAGE_NONE][0]['value'], $allowable_tags);
            $description = cmb_helper_truncate($description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
          }

          // Series title
          $series_title = FALSE;
          if (isset($node->og_group_ref[LANGUAGE_NONE])) {
            $nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
            $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
          }

          // Build data array of shows
          $shows[] = array(
            'nid' => $node->nid,
            'title' => $node->title,
            'type' => $node->type,
            'description' => $description,
            'series_title' => $series_title,
            'type' => $node->type,
            'img_src' => $img_src,
            'placeholder_img' => $placeholder_img,
            'url' => url('node/' . $node->nid),
          );
        }

        // Build data array to send to TPL.
        $data = array(
          'title' => '"' . $current_node->title . '" Shows',
          'shows' => $shows,
        );

        // Send to TPL
        return theme('cmb_cb_genre_carousel',
          array(
            'items' => $data,
          )
        );
        
      }
    }
  }
}
