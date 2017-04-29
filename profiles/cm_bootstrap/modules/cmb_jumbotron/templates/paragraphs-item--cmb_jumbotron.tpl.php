<section class="content-component cc-cmb-jumbotron">
  <div class="flexslider">
    <ul class="clean-ul-list slides">
      <?php foreach($cmb_jumbotron['items'] as $item): ?>
        <li>
          <a target="<?php print $item['link']['target']; ?>" href="<?php print $item['link']['href']; ?>">
            <div class="overlay-wrapper" style="background:rgba(<?php print $item['overlay_color'];?>, <?php print $item['overlay_opacity'];?>);">
              <div class="overlay-content">
                <h2>
                  <?php print $item['title']; ?>
                </h2>
                <div class="short-description">
                  <?php print $item['short_description']; ?>
                </div>

                <?php if ($item['link']['title']): ?>
                  <div class="button-wrapper">
                    <button style="background-color:<?php print $cmb_jumbotron['cta_bg_color']; ?>; color:<?php print $cmb_jumbotron['cta_color']; ?>;">
                      <?php print $item['link']['title']; ?>
                    </button>
                  </div>
                <?php endif; ?>
              </div>
            </div>
            <img src="<?php print $item['placeholder_img']; ?>" data-original="<?php print $item['image']['src']; ?>"/>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
