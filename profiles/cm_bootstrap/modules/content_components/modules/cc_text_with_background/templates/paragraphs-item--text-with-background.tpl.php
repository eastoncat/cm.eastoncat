<?php if ($cc_twb['display_mode'] == 'overlay'): ?>

  <section class="content-component cc--twb cc--twb--overlay<?php if ($cc_twb['fw_class']) { print ' ' . $cc_twb['fw_class']; } ?>">
    <div class="row">
      <div class="background-wrapper" style="background-image:url(<?php print $cc_twb['background_image'];?>);">
        <div class="overlay-wrapper" style="background:rgba(<?php print $cc_twb['bg_color']; ?>, 0.9);">
          <div class="col-md-12">
            <div class="twb-text-wrapper" style="color:<?php print $cc_twb['text_color']; ?>">
              <?php print $cc_twb['field_cc_twb_text']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>

<?php elseif($cc_twb['display_mode'] == 'bg_image'): ?>

  <section class="content-component cc--twb cc--twb--bg-image<?php if ($cc_twb['fw_class']) { print ' ' . $cc_twb['fw_class']; } ?>">
    <div class="row">
      <div class="background-wrapper" style="background-image:url(<?php print $cc_twb['background_image'];?>);">
        <div class="col-md-12">
          <div class="twb-text-wrapper" style="color:<?php print $cc_twb['text_color']; ?>">
            <?php print $cc_twb['field_cc_twb_text']; ?>
          </div>
        </div>
      </div>
    </div>
  </section>

<?php elseif($cc_twb['display_mode'] == 'bg_color'): ?>

  <section class="content-component cc--twb cc--twb--bg-color<?php if ($cc_twb['fw_class']) { print ' ' . $cc_twb['fw_class']; } ?>">
    <div class="row">
      <div class="background-wrapper" style="color:<?php print $cc_twb['text_color']; ?>; background:rgba(<?php print $cc_twb['bg_color']; ?>, 1);">
        <div class="col-md-12">
          <div class="twb-text-wrapper">
            <?php print $cc_twb['field_cc_twb_text']; ?>
          </div>
        </div>
      </div>
    </div>
  </section>

<?php elseif($cc_twb['display_mode'] == 'parallax'): ?>

  <section class="content-component cc--twb cc--twb--parallax<?php if ($cc_twb['fw_class']) { print ' ' . $cc_twb['fw_class']; } ?>">
    <div class="row">
      <div class="col-md-12">
        <div class="parallax-window" data-parallax="scroll" data-image-src="<?php print $cc_twb['parallax_image'];?>">
          <div class="row">
            <div class="col-md-6">
              <div class="twb-text-wrapper" style="color:<?php print $cc_twb['text_color']; ?>">
                <?php print $cc_twb['field_cc_twb_text']; ?>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>

<?php endif; ?>
