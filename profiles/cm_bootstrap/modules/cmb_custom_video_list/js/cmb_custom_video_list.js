(function ($) {

  Drupal.behaviors.cmb_custom_video_list__flexslider = {
    attach: function (context, settings) {

      //console.log('cmb_custom_video_list__flexslider');

      // Breakpoint vars defaults
      var bp1 = bp1 || 1;
      var bp2 = bp2 || 2;
      var bp3 = bp3 || 3;
      var bp4 = bp4 || 4;

      var currentBreakpoint;
      var didResize  = true;

      // on window resize, set the didResize to true
      $(window).resize(function() {
        didResize = true;
      });

      // every 1/4 second, check if the browser was resized
      // we throttled this because some browsers fire the resize even continuously during resize
      // that causes excessive processing, this helps limit that
      setInterval(function() {
        if(didResize) {
          didResize = false;

          // inspect the CSS to see what breakpoint the new window width has fallen into
          var newBreakpoint = window.getComputedStyle(document.body, ':after').getPropertyValue('content');

          /* tidy up after inconsistent browsers (some include quotation marks, they shouldn't) */
          newBreakpoint = newBreakpoint.replace(/"/g, "");
          newBreakpoint = newBreakpoint.replace(/'/g, "");

          // if the new breakpoint is different to the old one, do some stuff
          if (currentBreakpoint != newBreakpoint) {

            $('.cc--custom-video-list').each(function( index ) {
              var raw_slider = $(this).find('.flexslider').html();

              // remove the old flexslider (which has attached event handlers and adjusted DOM nodes)
              $(this).find('.flexslider').remove();

              // now re-insert clean mark-up so flexslider can run on it properly
              $(this).append("<div class='flexslider'></div>");
              $(this).find('.flexslider').html(raw_slider);

              // execute JS specific to each breakpoint
              if (newBreakpoint === 'breakpoint_1') {
                currentBreakpoint = 'breakpoint_1';
                // 1 slide
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $(window).width(),
                  minItems: bp1,
                  maxItems: bp1,
                  controlNav: false,
                  animationSpeed: 400,
                  start: function(slider) {
                    $.flexloader(slider);
                  },
                  after: function(slider) {
                    $.flexloader(slider);
                  }
                });
              }

              if (newBreakpoint === 'breakpoint_2') {
                currentBreakpoint = 'breakpoint_2';
                //console.log('2 slides');

                // 2 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $(window).width() / 2,
                  minItems: bp2,
                  maxItems: bp2,
                  controlNav: false,
                  animationSpeed: 400,
                  start: function(slider) {
                    $.flexloader(slider);
                  },
                  after: function(slider) {
                    $.flexloader(slider);
                  }
                });
              }

              // START: breakpoint_3
              if (newBreakpoint === 'breakpoint_3') {
                currentBreakpoint = 'breakpoint_3';
                //console.log('3 slides');

                // 3 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $(window).width() / 3,
                  minItems: bp3,
                  maxItems: bp3,
                  controlNav: false,
                  animationSpeed: 400,
                  start: function(slider) {
                    $.flexloader(slider);
                  },
                  after: function(slider) {
                    $.flexloader(slider);
                  }
                });
              }
              // END: breakpoint_3

              // START: breakpoint_4
              if (newBreakpoint === 'breakpoint_4') {
                currentBreakpoint = 'breakpoint_4';
                //console.log('4 slides');

                // 4 slides
                $(this).find('.flexslider').flexslider({
                  animation: "slide",
                  slideshow: false,
                  animationLoop: false,
                  itemWidth: $(window).width() / 4,
                  minItems: bp4,
                  maxItems: bp4,
                  controlNav: false,
                  animationSpeed: 400,
                  start: function(slider) {
                    $.flexloader(slider);
                  },
                  after: function(slider) {
                    $.flexloader(slider);
                  }
                });
              }
              // END: breakpoint_4
            });
          }
        }
      }, 250);

    }
  };

})(jQuery);
