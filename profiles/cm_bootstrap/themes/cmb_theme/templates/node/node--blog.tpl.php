<?php if ($node__blog['legacy']): ?>
  <?php hide($content['links']); ?>

  <div class="blog-date">
    <?php print date('F j, Y', $node->created); ?>
  </div>

  <?php print render($content); ?>

<?php else: ?>

  <div class="blog-date">
    <?php print date('F j, Y', $node->created); ?>
  </div>

  <div class="paragraphs-items-field-content-components">
    <?php foreach($node__blog['field_content_components'] as $content_component): ?>
      <?php print $content_component; ?>
    <?php endforeach; ?>
  </div>

<?php endif; ?>
