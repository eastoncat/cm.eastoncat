<a href="<?php print url('user/' . $search_result['uid']); ?>">
  <div class="row">

    <h3><?php print $search_result['title']; ?></h3>

    <div class="col-md-3 col-lg-3 col-sm-12 left-column">
      <?php if(!empty($search_result['image'])): ?>
        <img src="<?php print $search_result['image']; ?>"/>
      <?php endif; ?>
    </div>

    <div class="col-md-9 col-lg-9 col-sm-12 right-column">
      <?php if ($search_result['bio']): ?>
        <p class="sr-description">
          <label>Bio:</label>
          <?php print $search_result['bio']; ?>
        </p>
      <?php endif; ?>

      <!--<p class="sr-description">
        <label>Email:</label>
        <?php //print $search_result['email']; ?>
      </p>-->

      <p class="node-type">
        <label>Type:</label>
        <?php print $search_result['type']; ?>
      </p>
    </div>

  </div>
</a>
