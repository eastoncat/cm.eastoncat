<?php

function _cmb_archive_two_col() {
  if ($node = menu_get_object()) {
    // Content Type: 'archive_content_type'
    if ($node->type == 'archive_content_type') {
      $content_type = $node->field_archive_content_type['und'][0]['value'];
      switch ($content_type) {
        case 'article':
          $nids = _cb_archive_two_col_query($content_type);
          if (!empty($nids)) {
            $nodes = node_load_multiple(array_keys($nids));
            //dpm($nodes);
            foreach($nodes as $node) {

              // Image
              $img_src = "data:image/svg+xml;charset=utf-8,<svg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20width%3D'500'%20height%3D'281'><rect%20width%3D'100%25'%20height%3D'100%25'%20fill%3D'whitesmoke'%2F><%2Fsvg>";

              if (isset($node->field_image['und'])) {
                $img_src = $img_src = image_style_url('500x281', $node->field_image['und'][0]['uri']);
              }
              else {
                if (module_exists('cm_bootstrap_cp_default_images')) {
                  $file = cm_bootstrap_cp_default_images_load_image($node->type);
                  if ($file) {
                    $image_uri = $file->uri;
                    $img_src = image_style_url('500x281', $image_uri);
                  }
                }
              }

              // Description/Body
              if (isset($node->body['und'][0]['summary']) && !empty($node->body['und'][0]['summary'])) {
                $allowable_tags = '<img><p><strong><em><ol><ul><li><u>';
                $description = strip_tags($node->body['und'][0]['summary'], $allowable_tags);
              }
              else if (isset($node->body['und'][0]['value'])) {
                $allowable_tags = '<img><p><strong><em><ol><ul><li><u>';
                $description = strip_tags($node->body['und'][0]['value'], $allowable_tags);
              }
              else {
                $description = '';
              }

              // Build $items array.
              $items[$node->nid] = array(
                'nid' => $node->nid,
                'type' => $node->type,
                'datetime' => date('F j, Y | h:i', $node->created),
                'title' => $node->title,
                'description' => cmb_helper_truncate($description, $length = 450, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
                'img' => $img_src,
              );
            }
          }
          break;

        case 'blog':
          $nids = _cb_archive_two_col_query($content_type);
          if (!empty($nids)) {
            $nodes = node_load_multiple(array_keys($nids));
            foreach($nodes as $node) {
              // Image
              if (isset($node->field_blog_image['und'])) {
                $img_src = $img_src = image_style_url('500x281', $node->field_blog_image['und'][0]['uri']);
              }
              else {
                if (module_exists('cm_bootstrap_cp_default_images')) {
                  $file = cm_bootstrap_cp_default_images_load_image($node->type);
                  $image_uri = $file->uri;
                  $img_src = image_style_url('500x281', $image_uri);
                }
                else {
                  $img_src = "data:image/svg+xml;charset=utf-8,<svg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20width%3D'500'%20height%3D'281'><rect%20width%3D'100%25'%20height%3D'100%25'%20fill%3D'whitesmoke'%2F><%2Fsvg>";
                }
              }
              // Description/Body
              if (isset($node->body['und'][0]['summary'])) {
                $allowable_tags = '<img><p><strong><em><ol><ul><li><u>';
                $description = strip_tags($node->body['und'][0]['summary'], $allowable_tags);
              }
              else {
                $description = '';
              }
              // Build $items array.
              $items[$node->nid] = array(
                'nid' => $node->nid,
                'type' => $node->type,
                'datetime' => date('F j, Y | h:i', $node->created),
                'title' => $node->title,
                'description' => $description,
                'img' => $img_src,
              );
            }
          }
          break;
        case 'cm_show':
          $nids = _cb_archive_two_col_query($content_type);
          if (!empty($nids)) {
            $nodes = node_load_multiple(array_keys($nids));
            foreach($nodes as $node) {
              // Image
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
                $img_src = image_style_url('500x281', file_build_uri($image_uri));
              }
              else {
                if (module_exists('cm_bootstrap_cp_default_images')) {
                  $file = cm_bootstrap_cp_default_images_load_image($node->type);
                  $image_uri = $file->uri;
                  $img_src = image_style_url('500x281', $image_uri);
                }
                else {
                  $img_src = "data:image/svg+xml;charset=utf-8,<svg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20width%3D'500'%20height%3D'281'><rect%20width%3D'100%25'%20height%3D'100%25'%20fill%3D'whitesmoke'%2F><%2Fsvg>";
                }
              }
              // Description/Body
              if (isset($node->field_description['und'][0]['value'])) {
                $description = $node->field_description['und'][0]['value'];
              }
              else {
                $description = '';
              }
              // Build $items array.
              $items[$node->nid] = array(
                'nid' => $node->nid,
                'type' => $node->type,
                'title' => $node->title,
                'description' => cmb_helper_truncate($description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
                'img' => $img_src,
              );
            }
          }
          break;
      }
    }

    // Content Type: 'archive_node_ref'
    if ($node->type == 'archive_node_ref') {
      // Get all entity ref'd nids
      foreach($node->field_archive_node_ref['und'] as $nid) {
        $nids[$nid['target_id']] = $nid['target_id'];
      }
      // Query for data
      $query = new EntityFieldQuery;
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'page')
        ->propertyCondition('nid', $nids, 'IN')
        ->fieldCondition('field_main_image', 'fid', 'NULL', '!=')
        ->pager(10, 0);
      $result = $query->execute();
      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = node_load_multiple($nids);
        foreach($nodes as $node) {
          // Image
          if (isset($node->field_main_image['und'])) {
            $img_src = $img_src = image_style_url('500x281', $node->field_main_image['und'][0]['uri']);
          }
          else {
            $img_src = "data:image/svg+xml;charset=utf-8,<svg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20width%3D'500'%20height%3D'281'><rect%20width%3D'100%25'%20height%3D'100%25'%20fill%3D'whitesmoke'%2F><%2Fsvg>";
          }
          // Description/Body
          if (isset($node->field_teaser['und'][0]['value'])) {
            $allowable_tags = '<img><p><strong><em><ol><ul><li><u><a>';
            $description = strip_tags($node->field_teaser['und'][0]['value'], $allowable_tags);
          }
          else {
            $description = '';
          }
          // Build $items array.
          $items[$node->nid] = array(
            'nid' => $node->nid,
            'type' => $node->type,
            'title' => $node->title,
            'description' => $description,
            'img' => $img_src,
          );
        }
      }
    }

    // Get 'read more' copy for link
    if ($node = menu_get_object()) {
      $archive_node = $node;
      if (isset($archive_node->field_archive_more_copy['und'][0]['value'])) {
        $archive_link_copy = $archive_node->field_archive_more_copy['und'][0]['value'];
      }
      else {
        $archive_link_copy = 'More';
      }
    }

    // Pager
    $build['pager'] = array(
    	'#markup' => theme('pager'),
    	'#weight' => 10,
    	'pager_total' => $GLOBALS['pager_total'],
    );

    // Send data to TPL
    return theme('cmb_archive_two_col',
      array(
        'archive_link_copy' => $archive_link_copy,
        'content' => $items,
        'pager' => $build['pager'],
      )
    );
  }
}

/**
 * Query helper function.
 */
function _cb_archive_two_col_query($content_type) {
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', $content_type);
    $query->propertyCondition('status', 1);
    $query->propertyOrderBy('created', 'DESC');
    // Add Pager
    $query->pager(10, 0);
    $result = $query->execute();

    $nids = $result['node'];

    return $nids;
}
