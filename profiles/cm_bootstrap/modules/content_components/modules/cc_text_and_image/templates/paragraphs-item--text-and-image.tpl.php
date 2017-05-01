<style>
  @media only screen {
    .img-align-right,
    .img-align-left {
      float:none;
      width:100%;
      height:auto;
      margin: 0 0 20px 0;
    }
  }
  @media only screen and (min-width : 768px) {
    .img-align-right {
      float:right;
      width:450px;
      height:auto;
      margin: 0 0 20px 20px;
    }
    .img-align-left {
      float:left;
      width:450px;
      height:auto;
      margin: 0 20px 20px 0;
    }
  }
</style>
<section class="paragraphs--text-and-image">
  <div class="row">    
    <div class="col-md-12">
      <img class="<?php print $text_and_image['image_alignment_class']; ?>" src="<?php print $text_and_image['img_src']; ?>"/>
      <?php print $text_and_image['field_cc_tai_text']; ?>
    </div>
  </div>
</section>