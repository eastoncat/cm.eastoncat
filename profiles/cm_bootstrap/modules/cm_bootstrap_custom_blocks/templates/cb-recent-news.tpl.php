<?php //dpm($content); ?>

<style>
/*.recent-news-wrapper {
  height: 440px;
  min-height: 440px;
  max-height: 440px;
  overflow-y: scroll;
  overflow-x: hidden;
}*/
ul.cb-recent-news {
  padding:0;
  margin:0;
  list-style-type:none;
  font-size:.75em;
}
ul.cb-recent-news li {
  display:block;
  clear: both;
  margin-bottom:1px;
}
ul.cb-recent-news li a .left {
}
ul.cb-recent-news li a .right {
  padding:10px !important;
  background:#000;
  color:#FFF;
  height:96px;
  max-height: 96px;
  min-height: 96px !important;
  display: block;
}
ul.cb-recent-news li a:hover .right {
  background:red;
  -webkit-transition: 250ms ease-out;
  -moz-transition: 250ms ease-out;
  -o-transition: 250ms ease-out;
  transition: 250ms ease-out;
}
ul.cb-recent-news li a img {
  width: 100%;
  display: block;
}
ul.cb-recent-news li .series-title {
  position:inherit;
  display:block;
}
ul.cb-recent-news li .watch-now-link {
  display: block;
  text-transform: uppercase;
  position: absolute;
  bottom: 10px;
}
</style>

<div class="recent-news-wrapper">
  <?php if (!empty($term_name)): ?>
    <a href="<?php print url('taxonomy/term/' . $blog_category_term_data['tid']); ?>">
      <h3><?php print $term_name; ?></h3>
    </a>
  <?php endif; ?>
  <ul class="cb-recent-news">
    <?php foreach($content as $node): ?>
      <li class="row">
        <a href="<?php print url('node/' . $node['nid']); ?>">
          <span class="left col-md-6 col-sm-12 no-padding">
            <img src="<?php print $node['img']; ?>" />   
          </span>         
          <span class="right col-md-6 col-sm-12 no-padding">
            <p class="title">
              <?php print $node['title']; ?>
            </p>
            <!--<p class="series">
              Series: <?php print $node['series']; ?>
            </p>-->
            <!--<span class="play-button">
              <i class="icon glyphicon glyphicon-play-circle" aria-hidden="true"></i>
            </span>-->
            <span class="series-title" style="font-style:italic;"><?php print $node['series_title']; ?></span>
            <span class="watch-now-link">Read More &raquo;</span>
          </span>
        </a>
      </li>
    <?php endforeach; ?>
  </ul>
  
  <a href="<?php print url('taxonomy/term/' . $blog_category_term_data['tid']); ?>">
    <h4>See all <?php print $blog_category_term_data['term_name']; ?> Blogs</h4>
  </a>
  
</div>