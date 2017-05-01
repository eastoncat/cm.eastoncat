(function($) {
  Drupal.behaviors.cc_slider__flexslider = {
    attach: function (context, settings) {

      $(window).load(function() {

        $('#flexslider-thumbnails').flexslider({
          animation: "slide",
          controlNav: false,
          animationLoop: false,
          slideshow: false,
          itemWidth: $(window).width() / 4 - 24,
          minItems: 4,
          maxItems: 4,
          asNavFor: '#flexslider-slider',
        });

        $('#flexslider-slider').flexslider({
          animation: "slide",
          controlNav: false,
          slideshow: false,
          smoothHeight: true,
          sync: '#flexslider-thumbnails',
          start: function(slider) {
            $.flexloader(slider);
          },
          after: function(slider) {
            $.flexloader(slider);
          }
        });

      });

    }
  };
})(jQuery);
