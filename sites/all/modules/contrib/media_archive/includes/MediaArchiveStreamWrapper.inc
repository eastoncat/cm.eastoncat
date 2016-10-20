<?php

/**
 *  @file
 *  Extends the MediaReadOnlyStreamWrapper class to handle Archive videos.
 */

/**
 *  Create an instance like this:
 *  $archive = new MediaArchiveStreamWrapper('archive://v/[video-code]');
 */
class MediaArchiveStreamWrapper extends MediaReadOnlyStreamWrapper {
  protected $base_url = 'http://www.archive.com/watch';

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/archive';
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    return 'http://img.archive.com/vi/' . check_plain($parts['v']) . '/0.jpg';
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    // There's no need to hide thumbnails, always use the public system rather
    // than file_default_scheme().
    $local_path = 'public://media-archive/' . check_plain($parts['v']) . '.jpg';

    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      $response = drupal_http_request($this->getOriginalThumbnailPath());

      if (!isset($response->error)) {
        file_unmanaged_save_data($response->data, $local_path, TRUE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }

    return $local_path;
  }
}
