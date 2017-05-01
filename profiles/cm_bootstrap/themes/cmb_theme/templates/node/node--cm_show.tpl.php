<?php print render($content); ?>

<?php if (!isset($content['field_show_vod']) && !isset($node->field_show_custom_embed['und'][0]['target_id']) ): ?>
  <?php
    if (module_exists('cm_bootstrap_cp_default_images')) {
      $file = cm_bootstrap_cp_default_images_load_image($node->type);
      //dpm($file);
      $image_uri = $file->uri;
      $default_image = image_style_url('cm_bootstrap_cp_default_images_cm_show_video', $image_uri);
    }
  ?>
  <div class="fluid-width-video-wrapper">
    <img class="default-image" src="<?php print $default_image; ?>"/>
  </div>
<?php elseif(isset($node->field_show_custom_embed['und'][0]['target_id'])): ?>
  <?php //dpm('custom embed!'); ?>

  <?php
    $embedd_node = node_load($node->field_show_custom_embed['und'][0]['target_id']);
    //dpm($embedd_node);
  ?>
  <div class="video-container-embed">
    <?php print $embedd_node->field_iframe['und'][0]['value']; ?>
  </div>

<?php endif; ?>

<?php
  // Series meta data
  if (isset($node->og_group_ref['und'])) {
    $series_nid = $node->og_group_ref['und'][0]['target_id'];
    $series_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $series_nid))->fetchField();
  }
  else {
    $series_nid = '';
    $series_title = '';
  }
  // Genres/Topics data
  if (isset($node->field_genres['und'])) {
    foreach($node->field_genres['und'] as $genre) {
      $genre_title = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $genre['target_id']))->fetchField();
      $genres[] = array(
        'nid' => $genre['target_id'],
        'title' => $genre_title
      );
    }
  }
?>

<div class="show-meta">
  <div class="row">
    <div class="col-md-10 col-xs-10 no-padding">
      <a class="meta-series-title" href="<?php print url('node/' . $series_nid); ?>">
        <?php print $series_title; ?>
      </a>
      <a class="meta-node-title" style="color:#FFF;" href="<?php print url('node/' . $node->nid); ?>">
        <?php print $node->title; ?>
      </a>
      <?php if (isset($genres)): ?>
        <div class="genres-section">
          <span class="genres-label">Topics:</span>
          <?php foreach($genres as $genre_item): ?>
            <a href="<?php print url('node/' . $genre_item['nid']); ?>">
              <?php print $genre_item['title']; ?>
            </a>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-md-2 col-xs-2 no-padding">
      <div class="flag-container pull-right">
        <?php if (module_exists('flag')): ?>
          <?php print flag_create_link('cf_like_show', $node->nid); ?>
          <?php $flag = flag_get_flag('cf_like_show'); ?>
          <?php if ($flag->get_count($nid) > 0 && user_is_logged_in()): ?>
            <?php print $flag->get_count($nid); ?>
          <?php endif; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
