<div class="row">
  <ul class="two-col-list">
    <?php $i = 0; ?>  
    <?php foreach($content as $node): ?>
      <li class="item-<?php print $i++%4; ?> <?php print $node['type']; ?>">
        <a href="<?php print url('node/' . $node['nid']); ?>" class="container-link">
          <div class="container">
            <div class="col-md-6 col-sm-12 no-padding left-column">
              <img src="<?php print $node['img']; ?>" />
            </div>
            <div class="col-md-6 col-sm-12 no-padding right-column">
              <div class="inner">
                <?php if (isset($node['datetime'])): ?>
                  <div class="datetime">
                    <?php print $node['datetime']; ?>
                  </div>
                <?php endif; ?>
                <h2><?php print $node['title']; ?></h2>
                <div class="description-container">
                  <?php print $node['description']; ?>
                </div>
                <div class="read-more">
                  <?php print $archive_link_copy; ?> »
                </div>
              </div>
            </div>
          </div>
        </a>
      </li>
    <?php endforeach; ?>
  </ul>
</div>

<?php if ($pager['pager_total'][0] > 1): ?>
  <?php print render($pager); ?>
<?php endif; ?>
