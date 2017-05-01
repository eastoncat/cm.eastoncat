<a href="<?php print url('node/' . $search_result['nid']); ?>" class="search-results search-results--cm-show">
  <div class="row">
    <h3><?php print $search_result['title']; ?></h3>
    
    <div class="col-md-3 col-lg-3 col-sm-12 left-column">
      <?php if(!empty($search_result['show_image'])): ?>
        <img src="<?php print $search_result['show_image']; ?>"/>
      <?php endif; ?>
    </div>
    
    <div class="col-md-9 col-lg-9 col-sm-12 right-column">
      
      <p class="sr-description"><?php print $search_result['description']; ?></p>
      
      <p class="node-type">
        <label>Type:</label>
        <?php print $search_result['type']; ?>
      </p>
      
      <?php if (!empty($search_result['series_title'])): ?>
        <p class="sr-series-title">
          <label>Series Title:</label>
          <?php print $search_result['series_title']; ?>
        </p>
      <?php endif; ?>
      
      <?php if (!empty($search_result['producer'])): ?>
        <p class="producer">
          <label>Producer:</label>
          <?php print $search_result['producer']; ?>
        </p>
      <?php endif; ?>
      
      <?php if (!empty($search_result['production_date'])): ?>
        <p class="production-date">
          <label>Production Date:</label>
          <?php print $search_result['production_date']; ?>
        </p>
      <?php endif; ?>
      
    </div>
    
  </div>
</a>