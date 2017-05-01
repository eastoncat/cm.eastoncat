<a href="<?php print url('node/' . $search_result['nid']); ?>">
  <div class="row">    
    <div class="col-md-12 col-lg-12 col-sm-12 no-padding">
      <h3><?php print $search_result['title']; ?></h3>
      
      <p class="sr-description">
        <?php print $search_result['description']; ?>
      </p>
      
      <p class="node-type">
        <label>Type:</label>
        <?php print $search_result['type']; ?>
      </p>
    
    </div>
  </div>
</a>