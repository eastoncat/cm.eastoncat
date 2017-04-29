<?php

function _cf_user_recent_videos() {  
  $user = menu_get_object($type = 'user');
  if ($user) {
    $query = new EntityFieldQuery;
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'cm_show')
        ->propertyCondition('uid', $user->uid)
        // This creates descrpency b/w video count and "recent videos".
        //->propertyCondition('created', strtotime('-6 months'), ">")
        ->propertyOrderBy('created', 'DESC')
        ->fieldCondition('field_show_vod', 'fid', 'NULL', '!=')
        ->pager(10, 0);
      $result = $query->execute();
      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = node_load_multiple($nids);
        foreach ($nodes as $node) {
          $videos[] = $node;
        }
      }
      // Pager    
      $build['pager'] = array(
      	'#markup' => theme('pager'),
      	'#weight' => 10,
      	'pager_total' => $GLOBALS['pager_total'],
      );
     	// Block Content  
      $build['content'] = theme('cf_user_recent_videos', 
        array(
          'content' => $videos,
          'pager' => $build['pager'],
        )
      );
      return $build;  
  }  
}