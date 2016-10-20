/**
 * @file
 * Display vertical tabs fieldset summaries
 */

(function ($) {

  Drupal.behaviors.mediacloudfrontFieldsetSummaries = {
    attach: function (context) {
      $('fieldset#edit-media-cloudcast', context).drupalSetSummary(function (context) {
        var vals = [];

        // viewable select field.
        var viewable = $('#edit-media-cloudcast-viewable option:selected').text();
        vals.push(Drupal.t('All videos are @value', { '@value': viewable }));

        // display select field.
        if (viewable == 'not viewable') {
          var display = $('#edit-media-cloudcast-display option:selected').text();
          vals.push(Drupal.t('@value', { '@value': display }));
        }

        return vals.join(', ');
      });
    }
  };

})(jQuery);
