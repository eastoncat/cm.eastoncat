<section class="content-component cc-cmb-producers-carousel">

  <?php if ($cmb_producers_carousel['title']): ?>
    <h2 class="title">
      <?php print $cmb_producers_carousel['title']; ?>
    </h2>
  <?php endif; ?>

  <div class="flexslider carousel">
    <ul class="slides">
      <?php foreach($cmb_producers_carousel['items'] as $item): ?>
        <li>
          <a href="<?php print $item['link']; ?>">
            <img src="<?php print $item['image']['placeholder_img']; ?>" data-original="<?php print $item['image']['img_src']; ?>"/>

            <span class="overlay">

              <h4 class="title">
                <?php print $item['name']; ?>
              </h4>

              <?php if ($cmb_producers_carousel['more_text']): ?>
                <span class="watch-now">
                  <?php print $cmb_producers_carousel['more_text']; ?> &raquo;
                </span>
              <?php endif; ?>
            </span>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
