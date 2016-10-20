// Handle the color changes and update the preview window.
(function ($) {
  Drupal.color = {
    logoChanged: false,
    callback: function(context, settings, form, farb, height, width) {
      // Background
      $('#preview', form).css('backgroundColor', $('#palette input[name="palette[bg]"]', form).val());

      // Text
      $('#preview #preview-main h2, #preview .preview-content', form).css('color', $('#palette input[name="palette[text]"]', form).val());

      // Links
      $('#preview #preview-content a', form).css('color', $('#palette input[name="palette[link]"]', form).val());

      $('#preview #preview-content a:hover', form).css('color', $('#palette input[name="palette[link_hover]"]', form).val());

      // Button gradients
      $('#preview .node-links ul li a', form).css('color', $('#palette input[name="palette[button_gradient_top]"]', form).val());
	  
      $('#preview .node-links ul li a', form).css('color', $('#palette input[name="palette[button_gradient_top]"]', form).val());

      // Menu item link color
      $('#preview #preview-main-menu ul li a', form).css('color', $('#palette input[name="palette[main_menu_color]"]', form).val());

      // Menu item active link bg
      $('#preview #preview-main-menu ul li a.active', form).css('backgroundColor', $('#palette input[name="palette[main_menu_a_bg]"]', form).val());

      // Menu item active link color
      $('#preview #preview-main-menu-links li a.active', form).css('color', $('#palette input[name="palette[menu_item_a_color]"]', form).val());

      // CSS3 Gradients.
      var gradient_start1 = $('#palette input[name="palette[button_gradient_top]"]', form).val();
      var gradient_end1 = $('#palette input[name="palette[button_gradient_bottom]"]', form).val();

      $('#preview input[type="submit"]', form).attr('style', "background-color: " + gradient_start1 + "; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(" + gradient_start1 + "), to(" + gradient_end1 + ")); background-image: -moz-linear-gradient(-90deg, " + gradient_start1 + ", " + gradient_end1 + ");");
	  
	  var gradient_start2 = $('#palette input[name="palette[nodelinks_gradient_top]"]', form).val();
      var gradient_end2 = $('#palette input[name="palette[nodelinks_gradient_bottom]"]', form).val();

      $('#preview .node-links ul li a', form).attr('style', "background-color: " + gradient_start2 + "; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(" + gradient_start2 + "), to(" + gradient_end2 + ")); background-image: -moz-linear-gradient(-90deg, " + gradient_start2 + ", " + gradient_end2 + ");");
	  
	    // Menu item active link color
      $('#preview input[type="submit"]', form).css('color', $('#palette input[name="palette[button_color]"]', form).val());
	  
	    // Menu item active link color
      $('#preview .node-links ul li a', form).css('color', $('#palette input[name="palette[nodelinks_color]"]', form).val());
    }
  };
})(jQuery);