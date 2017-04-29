(function($) {
  Drupal.behaviors.headerDropDown = {
    attach: function(context, settings) {
      var windowWidth = $(window).width();
      // Touch screens
      if (windowWidth <= 768) {
        $('#parent-trigger-1').click(function(e) {
          e.preventDefault();
          var mlid = $(this).data('mlid');
          $('ul.second-level').filter('[data-mlid="' + mlid + '"]').toggle();
          // Close other menu
          $('.item-2 .second-level').hide();
        });

        $('#parent-trigger-2').click(function(e) {
          e.preventDefault();
          var mlid = $(this).data('mlid');
          $('ul.second-level').filter('[data-mlid="' + mlid + '"]').toggle();
          // Close other menu
          $('.item-1 .second-level').hide();
        });
      }
      // Desktop
      else {
        $('nav#site-wrapper-main-menu ul.first-level li').hover(
          function () {
            $(this).addClass('hover-color');
            $('ul.second-level', this).show();
          },
          function () {
            $(this).removeClass('hover-color');
            $('ul.second-level', this).hide();
          }
        );
        $('ul.third-level').hide();
        $('nav#site-wrapper-main-menu ul.second-level li').hover(
          function () {
            $('ul.third-level', this).show();
          },
          function () {
            $('ul.third-level', this).hide();
          }
        );
      }
    }
  };
})(jQuery);
