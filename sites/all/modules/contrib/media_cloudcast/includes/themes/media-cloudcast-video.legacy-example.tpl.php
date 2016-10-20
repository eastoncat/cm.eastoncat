<?php

/**
 * @file media_cloudcast/includes/themes/media-cloudcast-video-legacy.tpl.php
 *
 * Legacy markup template file for theme('media_cloudcast_video').
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
 * IMPORTANT: This file is provided to ease the upgrade path from Media:
 *  Cloudcast 7.x-1.x and 7.x-2.0-alpha2 versions by maintaining the legacy
 *  7.x-1.x markup. The markup has been simplified and improved in the 2.0
 *  and 2.x-dev versions of media-cloudcast-video.tpl.php. It is recommended
 *  that you revise any css or javascript that requires the old markup and
 *  then delete this file.
 */

?>
<div class="media-cloudcast-outer-wrapper" id="media-cloudcast-<?php print $id; ?>" width="<?php print $width; ?>" height="<?php print $height; ?>">
  <div class="media-cloudcast-preview-wrapper" id="<?php print $video_id . "_" . $id; ?>">
    <iframe class="media-cloudcast-player" <?php print $api_id_attribute; ?>width="<?php print $width; ?>" height="<?php print $height; ?>" src="<?php print $url; ?>" frameborder="0" allowfullscreen></iframe>
  </div>
</div>
