<section class="cc--custom-video-list">

  <?php if ($custom_video_list['title']): ?>
    <h2 class="title" style="background-color:<?php print $custom_video_list['bg_color']; ?>; color:<?php print $custom_video_list['text_color']; ?>;">
      <?php print $custom_video_list['title']; ?>
    </h2>
  <?php endif; ?>

  <div class="flexslider carousel">
    <ul class="slides">
      <?php foreach($custom_video_list['ref_node_data'] as $item): ?>
        <li>
          <a href="<?php print $item['url']; ?>">
            <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['img_src']; ?>"/>

            <span class="overlay">
              <span class="play-button">
                <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
              </span>

              <h4 class="title">
                <?php print $item['title']; ?>
              </h4>

              <?php if ($item['series_title']): ?>
                <p class="series-title">
                  <?php print $item['series_title']; ?>
                </p>
              <?php endif; ?>

              <?php if ($item['description']): ?>
                <p class="description">
                  <?php print $item['description']; ?>
                </p>
              <?php endif; ?>

              <span class="watch-now">Watch Now &raquo;</span>
            </span>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>

</section>
