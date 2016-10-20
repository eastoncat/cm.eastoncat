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



<div class="panel-zenbasethreeregions clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-zenbasethreeregions-top panel-panel">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['middle']): ?>
    <div class="panel-zenbasethreeregions-middle panel-panel">
      <div class="inside"><?php print $content['middle']; ?></div>
    </div>
  <?php endif; ?>
    <?php if ($content['bottom']): ?>
    <div class="panel-zenbasethreeregions-bottom panel-panel">
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>
  <?php endif; ?>
</div>

