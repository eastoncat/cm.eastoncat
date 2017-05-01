<?php

function _cb_taxonomy_term_blog() {
  $query = new CmbCustomBlocksArticleEntityFieldQuery();
  $query->fieldCondition('field_blog_category', 'tid', arg(2), '=')
    ->propertyOrderBy('created', 'DESC')
    ->pager(10);
  $result = $query->execute();      
  
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    
    foreach ($nodes as $node) {       
      // Image
      $img_src = '';
      
      if (isset($node->field_image['und'])) {         
        $img_src = image_style_url('500x281', $node->field_image['und'][0]['uri']);
      }
      else {
        if (module_exists('cm_bootstrap_cp_default_images')) {
          $file = cm_bootstrap_cp_default_images_load_image($node->type);
          $image_uri = $file->uri;
          $img_src = image_style_url('500x281', $image_uri);
        }
      }
      
      // Description/Body
      if (isset($node->body['und'][0]['summary']) && !empty($node->body['und'][0]['summary'])) {
        $allowable_tags = '<p><strong><em><ol><ul><li><u><a>';
        $description = strip_tags($node->body['und'][0]['summary'], $allowable_tags);
      }
      else if (isset($node->body['und'][0]['value'])) {
        $allowable_tags = '<p><strong><em><ol><ul><li><u><a>';
        $description = strip_tags($node->body['und'][0]['value'], $allowable_tags);
      }
      else {
        $description = '';
      }
      
      // Build data array
      $items[$node->nid] = array(
        'nid' => $node->nid,
        'title' => $node->title, 
        'img_src' => $img_src,
        'datetime' => date('F j, Y | h:i', $node->created),
        'description' => cmb_helper_truncate($description, $length = 450, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
      );      
    } 
    
    // Pager    
    $build['pager'] = array(
    	'#markup' => theme('pager'),
    	'#weight' => 10,
    	'pager_total' => $GLOBALS['pager_total'],
    );  
       
    //dpm($items);
    
    // Send data to TPL.  
    return theme('cb_taxonomy_term_blog', 
      array (
        'content' => $items,
        //'pager' => array('#theme' => 'pager'),
        'pager' => $build['pager'],
      )
    );
  }
}