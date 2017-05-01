<?php if (!user_is_anonymous()): ?>

  <?php print $user_picture; ?>
  
  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>
  
<?php endif; ?>

<?php print render($content); ?>