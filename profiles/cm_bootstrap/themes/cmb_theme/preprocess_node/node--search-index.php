<?php

function _node__search_index(&$variables) {
  $node = $variables['node'];

  switch ($node->type) {
    case 'cm_show':
      $show_image = '';

      // Get show image
      if (isset($node->field_show_vod['und'])) {
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
        }
        $show_image = image_style_url('medium', $image_uri);
      }
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $file = cm_bootstrap_cp_default_images_load_image($node->type);
          $image_uri = $file->uri;
          $show_image = image_style_url('medium', $image_uri);
        }
      }

      // Series title
      if (isset($node->og_group_ref['und'][0]['target_id'])) {
        $s_nid = $node->og_group_ref['und'][0]['target_id'];
        $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $s_nid))->fetchField();
      }
      else {
        $series_title = '';
      }

      // Producer
      if(isset($node->field_show_producer['und'][0]['target_id'])) {
        $uid = $node->field_show_producer['und'][0]['target_id'];
        $user = user_load($uid);
        $producer = $user->name;
      }

      // Production Date
      $production_date = '';

      if (isset($node->field_show_production_date['und'][0]['value'])) {
        $production_date = $node->field_show_production_date['und'][0]['value'];
        $production_date = date('F d, Y', strtotime($production_date));
      }

      // Description
      $description = '';

      if (isset($node->field_description['und'][0]['value'])) {
        $description = $node->field_description['und'][0]['value'];
        $description = strip_tags($description);
        $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
      }

      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'type' => 'Show',
        'series_title' => $series_title,
        'show_image' => $show_image,
        'producer' => $producer,
        'production_date' => $production_date,
        'description' => $description,
      );

      break;

    case 'cm_project':
      // Get image from field_series_image
      if (isset($node->field_series_image['und'])) {
        $image_uri = $node->field_series_image['und'][0]['uri'];
      }
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $file = cm_bootstrap_cp_default_images_load_image($node->type);
          $image_uri = $file->uri;
        }
      }

      // Producer
      $producer = '';
      if(isset($node->field_show_producer['und'][0]['target_id'])) {
        $uid = $node->field_show_producer['und'][0]['target_id'];
        $user = user_load($uid);
        $producer = $user->name;
      }

      // Description
      $description = '';

      if (isset($node->field_description['und'][0]['value'])) {
        $description = $node->field_description['und'][0]['value'];
        $description = strip_tags($description);
        $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
      }

      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'type' => 'Series',
        'series_image' => image_style_url('medium', $image_uri),
        'description' => $description,
        'producer' => $producer,
      );

      break;

    case 'blog':
      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'type' => 'Blog',
        'description' => $node->body['und'][0]['summary'],
        'post_date' => date('F d, Y', $node->created),
      );

      break;

    case 'page':
      $description = '';

      // Legacy mode: OFF
      if (!$node->field_legacy_toggle[LANGUAGE_NONE][0]['value']) {
        if (isset($node->field_teaser[LANGUAGE_NONE])) {
          $description = $node->field_teaser[LANGUAGE_NONE][0]['value'];
          $description = strip_tags($description);
          $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
        }
        // Try to get text from first paragraph that has a 'text' field
        else {
          if (isset($node->field_content_components[LANGUAGE_NONE])) {
            foreach($node->field_content_components as $items) {
              foreach($items as $item) {
                $item_id = $item['value'];
                $paragraphs[] = entity_load('paragraphs_item', array($item_id));
              }
            }

            $paragraph_types = array(
              'text',
              'text_and_image',
              'text_with_background',
            );

            foreach($paragraphs as $paragraph) {
              $paragraph = reset($paragraph);

              if (in_array($paragraph->bundle, $paragraph_types)) {
                switch($paragraph->bundle) {
                  case 'text':
                    $description = $paragraph->field_cc_text_paragraph[LANGUAGE_NONE][0]['value'];
                    break;

                  case 'text_and_image':
                    $description = $paragraph->field_cc_tai_text[LANGUAGE_NONE][0]['value'];
                    break;

                  case 'text_with_background':
                    $description = $paragraph->field_cc_twb_text[LANGUAGE_NONE][0]['value'];
                    break;
                }

                $description = strip_tags($description);
                $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
              }
              else {
                continue;
              }
            }

          }
        }
      }

      // Legacy mode: ON
      else {
        if (isset($node->body['und'][0]['value'])) {
          $description = $node->body['und'][0]['value'];
          $description = strip_tags($description);
          $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
        }
      }

      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'description' => $description,
        'type' => 'Page',
      );

      break;

    case 'genre':
      $description = '';

      if (isset($node->body['und'][0]['value'])) {
        $description = $node->body['und'][0]['value'];
        $description = strip_tags($description);
        $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
      }

      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'description' => $description,
        'type' => 'Genre',
      );

      break;

    case 'cmbs_producer':
      $uid = $node->field_cmbs_producer_uid[LANGUAGE_NONE][0]['target_id'];

      $user = user_load($uid);
      //dpm($user);

      // Get user image
      if (isset($user->picture)) {
        $image_uri = $user->picture->uri;
      }
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          // Change this to user when you add that
          $file = cm_bootstrap_cp_default_images_load_image('cm_project');
          $image_uri = $file->uri;
        }
      }

      // Bio
      $bio = FALSE;
      if (isset($node->field_cmbs_producer_bio[LANGUAGE_NONE][0]['value'])) {
        $bio = $node->field_cmbs_producer_bio[LANGUAGE_NONE][0]['value'];
      }

      $search_result = array(
        'nid' => $node->nid,
        'title' => $node->title,
        'uid' => $node->field_cmbs_producer_uid[LANGUAGE_NONE][0]['target_id'],
        'email' => $node->field_cmbs_producer_email[LANGUAGE_NONE][0]['value'],
        'bio' => $bio,
        'image' => image_style_url('medium', $image_uri),
        'type' => 'Producer',
      );

      break;

      case 'cmbs_event':
        $description = '';
        if (isset($node->field_cmbs_event_descr[LANGUAGE_NONE][0]['value'])) {
          $description = $node->field_cmbs_event_descr[LANGUAGE_NONE][0]['value'];
          $description = strip_tags($description);
          $description = cmb_helper_truncate($description, $length = 250, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE));
        }
        // Start Date
        $start_date = FALSE;
        if (isset($node->field_cmbs_event_datetime[LANGUAGE_NONE])) {
          $start_date = date('D, F j, Y g:ia', strtotime($node->field_cmbs_event_datetime[LANGUAGE_NONE][0]['value']));
        }
        // End Date
        $end_date = FALSE;
        if (isset($node->field_cmbs_event_datetime[LANGUAGE_NONE])) {
          $end_date = date('D, F j, Y g:ia', strtotime($node->field_cmbs_event_datetime[LANGUAGE_NONE][0]['value2']));
        }
        // Civi link
        $civi_id = $node->field_cmbs_event_civi_id[LANGUAGE_NONE][0]['value'];
        $civi_link = '/civicrm/event/info?id=' . $civi_id . '&reset=1';
        $search_result = array(
          'nid' => $node->nid,
          'title' => $node->title,
          'description' => $description,
          'start_date' => $start_date,
          'end_date' => $end_date,
          'civi_link' => $civi_link,
          'type' => 'Event',
        );
        break;
    }

    $variables['search_result'] = $search_result;
}
