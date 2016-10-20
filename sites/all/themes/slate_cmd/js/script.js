/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth

(function ($) {
$('#block-system-main-menu').bind('click','.menu-link', function() {
  $('#menu').slideToggle('fast', function() {
    if($('#menu').is(':visible')) {
      $('.menu-link span').html('&#9650;');
    } else {
      $('.menu-link span').html('&#9660;');
    }
  });
});

$('#menu').bind('click', '.expanded a', function() {
  if ($(window).width() < 772 || $('html').hasClass('touch')) {
    if ($(this).next('ul').is(':visible')) {
      $(this).next('ul').slideUp('fast');
      $(this).removeClass('active');
    } else {
      $(this).closest('ul').find('.active').next('ul').slideUp('fast');
      $(this).closest('ul').find('.active').removeClass('active');
      $(this).next().slideToggle('fast');
      $(this).addClass('active');
    }
  }
});
})(jQuery);
