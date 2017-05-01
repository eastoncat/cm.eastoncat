<?php $cmb_show_recent_videos_sidebar_block = module_invoke('cmb_show', 'block_view', 'cmb_show_recent_videos_sidebar'); ?>
<?php $cmb_show_air_dates_block = module_invoke('cmb_show', 'block_view', 'cmb_show_air_dates'); ?>
<?php $cmb_show_chapters_block = module_invoke('cmb_show', 'block_view', 'cmb_show_chapters'); ?>

<div role="tabpanel">
  <ul class="nav nav-tabs" role="tablist">
    <?php if (empty($cmb_show_chapters_block['content'])): ?>
      <li role="presentation" class="recent-videos active">
        <a href="#recent-video" aria-controls="recent-video" role="tab" data-toggle="tab">
          <?php print $cmb_show_recent_videos_sidebar_block['title']; ?>
        </a>
      </li>
    <?php endif; ?>
    <?php if (!empty($cmb_show_chapters_block['content'])): ?>
      <li role="presentation" class="chapters active">
        <a href="#chapters" aria-controls="chapters" role="tab" data-toggle="tab">Chapters</a>
      </li>
      <li role="presentation" class="recent-videos">
        <a href="#recent-video" aria-controls="recent-video" role="tab" data-toggle="tab">
          <?php print $cmb_show_recent_videos_sidebar_block['title']; ?>
        </a>
      </li>
    <?php endif; ?>
    <?php //if (!empty($cmb_show_air_dates_block['content'])): ?>
      <li role="presentation" class="airdate">
        <a href="#airdate" aria-controls="airdate" role="tab" data-toggle="tab">Air Date</a>
      </li>
    <?php //endif; ?>
  </ul>
  <div class="tab-content">
    <?php if (!empty($cmb_show_recent_videos_sidebar_block['content'])): ?>
      <?php
        if (empty($cmb_show_chapters_block['content'])) {
          $class = "active";
        }
        else {
          $class = "not-active";
        }
      ?>
      <div role="tabpanel" class="tab-pane <?php print $class; ?>" id="recent-video">
        <?php print render($cmb_show_recent_videos_sidebar_block['content']); ?>
      </div>
    <?php endif; ?>
    <?php if(!empty($cmb_show_chapters_block['content'])): ?>
      <?php
        if (!empty($cmb_show_chapters_block['content'])) {
          $class = "active";
        }
        else {
          $class = "not-active";
        }
      ?>
      <div role="tabpanel" class="tab-pane <?php print $class; ?>" id="chapters">
        <?php print render($cmb_show_chapters_block['content']); ?>
      </div>
    <?php endif; ?>
      <div role="tabpanel" class="tab-pane" id="airdate">
        <?php if (!empty($cmb_show_air_dates_block['content'])): ?>
          <?php print render($cmb_show_air_dates_block['content']); ?>
        <?php else: ?>
          <p style="padding:10px;">Currently, there are no air dates scheduled for this show.</p>
        <?php endif; ?>
      </div>
  </div>
</div>

<?php if (module_exists('cm_bootstrap_cp')): ?>
  <?php $show_buttons = cm_bootstrap_cp_show_buttons_get(); ?>
  <?php if(isset($show_buttons)): ?>
    <ul class="bottom-buttons">
    <?php foreach($show_buttons as $show_button): ?>
      <li>
        <?php
          //dpm($show_button);
          $node = menu_get_object();
          if ($node) {
            $url = str_replace('[nid]', $node->nid, $show_button->url);
          }
          else {
            $url = $show_button->url;
          }
        ?>
        <a href="<?php print $url; ?>">
          <span class="glyphicon <?php print $show_button->icon_class; ?>" aria-hidden="true"></span>
          <?php print $show_button->title; ?>
        </a>
      </li>
    <?php endforeach; ?>
    </ul>
  <?php endif; ?>
<?php endif; ?>
