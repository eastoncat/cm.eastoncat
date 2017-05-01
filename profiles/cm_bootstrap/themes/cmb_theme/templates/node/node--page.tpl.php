<?php if ($node__page['legacy']): ?>
 
  <?php print render($content['body']); ?>
  
<?php else: ?>

  <div class="paragraphs-items-field-content-components">
    <?php foreach($node__page['field_content_components'] as $content_component): ?>
      <?php print $content_component; ?>
    <?php endforeach; ?>
  </div>
  
<?php endif; ?>