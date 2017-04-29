<ul class="user-shows-likes">
<?php foreach($content as $node): ?>
  <?php 
    // Get show images, accounting for variations.
    if (isset($node->field_show_vod['und'])) {        
      switch($node->field_show_vod['und'][0]['filemime']) {
        // Cloudcast
        case 'video/cloudcast':
          $image_uri = 'media-cloudcast/' . $node->field_show_vod['und'][0]['filename']  . '.jpg';								
          break;
        // Vimeo
        case 'video/vimeo':
          $image_uri = str_replace('vimeo://v/', 'media-vimeo/', $node->field_show_vod['und'][0]['uri']);
          $image_uri = $image_uri . '.jpg';
          break;
        // Youtube
        case 'video/youtube':  
          $image_uri = str_replace('youtube://v/', 'media-youtube/', $node->field_show_vod['und'][0]['uri']);
          $image_uri = $image_uri . '.jpg';
          break;
      }
      $img_src = image_style_url('250x150', $image_uri);
    }
    else {
      $img_src = '';
    }
    // Description
    if (isset($node->field_description['und'][0]['value'])) {
      $show_description = $node->field_description['und'][0]['value'];
    }
    else {
      $show_description = '';
    }
    // Series title
    if (isset($node->og_group_ref['und'][0]['target_id'])) {
      $nid = $node->og_group_ref['und'][0]['target_id'];
      $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();
    }
    else {
      $series_title = '';
    }
  ?>
  <li>
    <a href="<?php print url('node/' . $node->nid); ?>">
      <img src="<?php print $img_src; ?>" />
      <span class="overlay">
        <p class="title">
          <?php print $node->title; ?>
        </p>
        <p class="description">
          <?php //print $show_description; ?>
        </p>
        <span class="series-title" style="font-style:italic;"><?php print $series_title; ?></span>
        <span class="watch-now-mobile">Watch Now &raquo;</span>
      </span>
    </a>
  </li>
<?php endforeach; ?>
</ul>

<?php if ($pager['pager_total'][0] > 1): ?>
  <?php print render($pager); ?>
<?php endif; ?>