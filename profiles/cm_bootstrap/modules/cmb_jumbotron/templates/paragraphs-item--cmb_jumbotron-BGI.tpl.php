<style>
  .flexloader-background-image-loaded {
    background-image: url('http://retn-p139-hp-par.kbox.site/sites/default/files/styles/cmb_jumbotron/public/cmb-jumbotron/2017prodparty.jpg?itok=LrAc1IZ-');
  }
</style>

<section class="content-component2 cc-cmb-jumbotron">
  <div class="flexslider">
    <ul class="clean-ul-list slides">
      <?php foreach($cmb_jumbotron['items'] as $item): ?>
        <li class="slide" data-src="<?php print $item['image']['placeholder']; ?>" data-original="<?php print $item['image']['src']; ?>">

          <div class="overlay-wrapper">
            <div class="overlay-content">
              <h2>
                <?php print $item['title']; ?>
              </h2>

              <div class="short-description">
                <?php print $item['short_description']; ?>
              </div>

            </div>
          </div>

          <!--<img src="<?php //print $item['image']['placeholder']; ?>" data-original="<?php //print $item['image']['src']; ?>"/>-->
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
