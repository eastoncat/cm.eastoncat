(function ($) {
  Drupal.behaviors.cmb_archive__pg_adjust_height = {
    attach: function (context, settings) {
      $(window).on('load resize',function() {
        var browserWidth = $(window).width();
        //console.log(browserWidth);

        if (browserWidth > 990) {
          var leftHeight = $('.two-col-list li .container .left-column').height();
          //console.log(leftHeight);

          $('.two-col-list li .container .right-column').height(leftHeight);
        }
        else {
          $('.two-col-list li .container .right-column').height('auto');
        }

      });
    }
  };
})(jQuery);
