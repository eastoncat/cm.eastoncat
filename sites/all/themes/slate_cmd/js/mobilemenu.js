(function ($) {
  Drupal.behaviors.mobile_menu_toggle = {
    attach: function (context, settings) {
		var ww = $(window).width();

		var adjustMenu = function() {
				if (ww < 772) {
    			// if "more" link not in DOM, add it
    			if (!$(".more")[0]) {
    			$('<div class="more">&nbsp;</div>').insertBefore($('.parent')); 
    			}
					$(".mobile-menu-links").show();
					$("#menu").hide();
					$(".search-form").hide();


					if (!$(".toggle-menu").hasClass("active") && !$(".toggle-search").hasClass("active")) {
						$("#menu").hide();
						$(".search-form").hide();
					} else if ($(".toggle-menu").hasClass("active")) {
						$("#menu").show();
						$(".search-form").hide();
					} else {
						$("#menu").hide();
						$(".search-form").show();
					}


					$("ul.menu li").unbind('mouseenter mouseleave');
					$("ul.menu li a.parent").unbind('click');
    				$("ul.menu li .more").unbind('click').bind('click', function() {
						$(this).parent("li").toggleClass("hover");
					});
				} 

				else if (ww >= 772) {
    			// remove .more link in desktop view
    			$('.more').remove(); 
					$(".mobile-menu-links").hide();
					$("#menu").show();
					$(".search-form").show();
					$("ul.menu li").removeClass("hover");
					$("ul.menu li a").unbind('click');
					$("ul.menu li").unbind('mouseenter mouseleave').bind('mouseenter mouseleave', function() {
		 				// must be attached to li so that mouseleave is not triggered when hover over submenu
		 				$(this).toggleClass('hover');
					});
				}
			}

		$(document).ready(function() {
  			$("ul.menu li a").each(function() {
    			if ($(this).next().length > 0) {
    				$(this).addClass("parent");
					};
				})
				
			$(".toggle-menu").click(function(e) {
				e.preventDefault();
				$(this).toggleClass("active");

				if ($(".toggle-search").hasClass("active")) {
					$(".toggle-search").toggleClass("active");
					$(".search-form").toggle();
				} 
				$("#menu").toggle();
			});
			
			$(".toggle-search").click(function(f) {
				f.preventDefault();
				$(this).toggleClass("active");
				if ($(".toggle-menu").hasClass("active")) {
					$(".toggle-menu").toggleClass("active");
					$("#menu").toggle();
				} 
				$(".search-form").toggle();
			});
			
				adjustMenu();
			})

			$(window).bind('resize orientationchange', function() {
				ww = $(window).width();
				adjustMenu();
			});

			
		}
	};
})(jQuery);