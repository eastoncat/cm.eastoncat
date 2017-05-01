<section class="content-component content-component--slider">
  <div class="row">
    <div class="col-md-12">
      <?php if ($slider['title']): ?>
        <h2>
          <?php print $slider['title']; ?>
        </h2>
      <?php endif; ?>

      <div id="flexslider-slider" class="flexslider">
        <ul class="clean-ul-list slides">
          <?php foreach($slider['s_items'] as $item): ?>
            <li class="row">

              <div class="<?php print $item['grid_classes_2']; ?> no-padding media-column">
                <?php if ($item['video']): ?>
                  <div class="cmb--responsive-video-wrapper">
                    <iframe src="<?php print $item['video']['url'];?>" frameborder="0" allowfullscreen></iframe>
                  </div>
                <?php endif; ?>

                <?php if ($item['data_original'] && $item['video'] == FALSE): ?>
                  <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['data_original']; ?>"/>
                <?php endif; ?>
              </div>

              <?php if ($item['display_mode'] == 'text_and_media'): ?>
                <div class="<?php print $item['grid_classes_1']; ?> text-column">
                  <div class="text-wrapper">
                    <?php print $item['text']; ?>
                  </div>
                </div>
              <?php endif; ?>

            </li>
          <?php endforeach; ?>
        </ul>
      </div>

      <?php if ($slider['thumbnails']): ?>
        <div id="flexslider-thumbnails" class="flexslider">
          <ul class="clean-ul-list slides">
            <?php foreach($slider['s_items'] as $thumbnail_item): ?>
              <li>
                <img src="<?php print $thumbnail_item['thumbnail']; ?>"/>
              </li>
            <?php endforeach; ?>
          </ul>
        </div>
      <?php endif; ?>

    </div>
  </div>
</section>
