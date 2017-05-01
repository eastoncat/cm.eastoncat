<section class="slider">
  <div class="flexslider carousel">
    <ul class="front-pg-slider-items slides">
      <?php foreach($content as $node): ?>
        <li>
          <a href="<?php print $node['url']; ?>">
            <span class="title-container">
              <span class="title" style="color:<?php print $jumbotron_text_color; ?>; background-color:rgba(<?php print $jumbotron_overlay_color; ?>, .6);">
                <?php print $node['title']; ?> &raquo;
              </span>
            </span>
            <img src="<?php print $node['img']; ?>" />
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
