<?php

function _cb_recent_news() {  
  $node = menu_get_object();
  //dpm($node);
  
  $field_blog_category_tid = $node->field_blog_category[LANGUAGE_NONE][0]['tid'];
  
  $blog_category_term = taxonomy_term_load($field_blog_category_tid);
  $blog_category_term_name = '';
  
  if ($blog_category_term) {
    $blog_category_term_name = $blog_category_term->name;
    $blog_category_term_name = $blog_category_term_name . ' Blog';
  }
  
  $blog_category_term_data = array(
    'term_name' => $blog_category_term_name,
    'tid' => $field_blog_category_tid
  );
  
  //dpm($field_blog_category_tid);
  //dpm($field_blog_category_tid);
       
  $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'article');
    $query->propertyCondition('status', 1);
    if (!empty($field_blog_category_tid)) {
      $query->fieldCondition('field_blog_category', 'tid', $field_blog_category_tid);
    }
    $query->range(0, 5);
    $query->propertyOrderBy('created', 'DESC');
  $result = $query->execute();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach ($nodes as $node) {       
      // Img
      if (isset($node->field_image['und'][0]['uri'])) {
        $image_uri = $node->field_image['und'][0]['uri'];
      }
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $file = cm_bootstrap_cp_default_images_load_image($node->type);
          $image_uri = $file->uri;
        }
      }      
      // Build data array
      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title,      
        'img' => image_style_url('500x281', $image_uri),
      );
    }
    
    //dpm($items);
    
    // Send data to TPL.  
    return theme('cb_recent_news', 
      array (
        'term_name' => $blog_category_term_name,
        'content' => $items,
        'blog_category_term_data' => $blog_category_term_data,
      )
    );  
  }
}
