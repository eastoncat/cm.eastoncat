<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *
 */
?>



<div class="panel-zenbase clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['zenbase-top']): ?>
    <div class="panel-zenbase-top panel-panel">
      <div class="inside"><?php print $content['zenbase-top']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['zenbase-a']): ?>
    <div class="panel-zenbase-a panel-panel">
      <div class="inside"><?php print $content['zenbase-a']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['zenbase-b']): ?>
    <div class="panel-zenbase-b panel-panel">
      <div class="inside"><?php print $content['zenbase-b']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['zenbase-c']): ?>
    <div class="panel-zenbase-c panel-panel">
      <div class="inside"><?php print $content['zenbase-c']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['zenbase-bottom']): ?>
    <div class="panel-zenbase-bottom panel-panel">
      <div class="inside"><?php print $content['zenbase-bottom']; ?></div>
    </div>
  <?php endif; ?>
</div>

