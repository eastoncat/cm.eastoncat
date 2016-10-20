<?php

/**
 * @file media_cloudcast/includes/themes/media-cloudcast-video.tpl.php
 *
 * Template file for theme('media_cloudcast_video').
 *
 * Variables available:
 *  $uri - The media uri for the Cloudcast video (e.g., cloudcast://v/xsy7x8c9).
 *  $video_id - The unique identifier of the Cloudcast video (e.g., xsy7x8c9).
 *  $id - The file entity ID (fid).
 *  $url - The full url including query options for the Youtube iframe.
 *  $options - An array containing the Media Youtube formatter options.
 *  $api_id_attribute - An id attribute if the Javascript API is enabled;
 *  otherwise NULL.
 *  $width - The width value set in Media: Youtube file display options.
 *  $height - The height value set in Media: Youtube file display options.
 *
 */

?>
<?php if($show_video): ?>
  <div class="<?php print $classes; ?> media-cloudcast-<?php print $id; ?>">
    <iframe class="media-cloudcast-player" width="<?php print $width; ?>" height="<?php print $height; ?>" src="<?php print $url; ?>" frameborder="0" allowfullscreen></iframe>
  </div>
<?php elseif($show_thumbnail): ?>
  <?php print $video_thumbnail; ?>
<?php endif; ?>
