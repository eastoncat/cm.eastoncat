<a href="<?php print $search_result['civi_link']; ?>">
  <div class="row">
    <div class="col-md-12 col-lg-12 col-sm-12 no-padding">
      <h3><?php print $search_result['title']; ?></h3>
      <p class="sr-description">
        <?php print $search_result['description']; ?>
      </p>

      <?php if ($search_result['start_date']): ?>
        <p class="sr-start-date">
          <label>Start Date:</label>
          <?php print $search_result['start_date']; ?>
        </p>
      <?php endif; ?>

      <?php if ($search_result['end_date']): ?>
        <p class="sr-end-date">
          <label>End Date:</label>
          <?php print $search_result['end_date']; ?>
        </p>
      <?php endif; ?>

      <p class="node-type">
        <label>Type:</label>
        <?php print $search_result['type']; ?>
      </p>
    </div>
  </div>
</a>
