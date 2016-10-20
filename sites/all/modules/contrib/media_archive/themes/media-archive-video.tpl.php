<?php

/**
 * @file media_archive/themes/media-archive-video.tpl.php
 *
 * Template file for theme('media_archive_video').
 *
 * Variables available:
 *  $uri - The media uri for the YouTube video (e.g., archive://v/xsy7x8c9).
 *  $video_id - The unique identifier of the YouTube video (e.g., xsy7x8c9).
 *  $id - The file entity ID (fid).
 *  $url - The full url including query options for the Youtube iframe.
 *  $options - An array containing the Media Youtube formatter options.
 *  $api_id_attribute - An id attribute if the Javascript API is enabled;
 *  otherwise NULL.
 *  $width - The width value set in Media: Youtube file display options.
 *  $height - The height value set in Media: Youtube file display options.
 *  $title - The Media: YouTube file's title.
 *  $alternative_content - Text to display for browsers that don't support
 *  iframes.
 *
 */

// Start w/ HTML5
?>
<div class="<?php print $classes; ?> media-archive-<?php print $id; ?>">

  <iframe src="<?php print $url; ?>" width="<?php print $width; ?>" height="<?php print $height; ?>" frameBorder="0" scrolling="no" allowFullScreen><?php print t('Sorry, your browser needs to support iframes to view this.'); ?></iframe>

</div>
