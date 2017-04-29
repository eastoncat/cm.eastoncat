<section class="c-flexslider-video-carousel">

  <h2 class="block-title">
    <?php print $items['title']; ?>
  </h2>

  <div class="flexslider carousel">
    <ul class="slides">
      <?php foreach($items['shows'] as $item): ?>
        <li>
          <a href="<?php print $item['url']; ?>">
            <img src="<?php print $item['img_src']; ?>"/>

            <span class="overlay">
              <span class="play-button">
                <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
              </span>

              <p class="title">
                <?php print $item['title']; ?>
              </p>

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
