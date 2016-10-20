/**
 * @file
 * Changed Edit image style link based on user selection
 */

(function($) {

  Drupal.behaviors.mediacloudImageStyleEdit = {
    attach: function(context) {
      $('#edit-displays-media-cloudcast-image-settings-image-style', context).change(function(context) {
        // selected field.
        var selected = this.value;

        // change the edit link
        $('#edit-displays-media-cloudcast-image-settings-image-style-edit-link').attr('href', Drupal.settings.basePath + '?q=/admin/config/media/image-styles/edit/' + selected);
      });
    }
  };

})(jQuery);
