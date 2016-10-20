<?php

/**
 *  @file media_cloudcast/includes/MediaCloudcastStreamWrapper.inc
 *
 *  Create a Cloudcast Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $cloudcast = new MediaCloudcastStreamWrapper('cloudcast://v/[video-code]');
 */
class MediaCloudcastStreamWrapper extends MediaReadOnlyStreamWrapper {

  // Overrides $base_url defined in MediaReadOnlyStreamWrapper.
  protected $base_url = 'http://cvp.telvue.com/player';

  /**
   * Returns a url in the format "http://cloudcast.com/watch?v=qsPQN4MiTeE".
   *
   * Overrides interpolateUrl() defined in MediaReadOnlyStreamWrapper.
   * This is an exact copy of the function in MediaReadOnlyStreamWrapper,
   * here in case that example is redefined or removed.
   */
  function interpolateUrl() {
    if ($parameters = $this->get_parameters()) {
      return $this->base_url . '?' . http_build_query($parameters);
    }
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/cloudcast';
  }

  function getTarget($f) {
    return FALSE;
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    //http://cloudcast.telvue.com/thumbnails/134038.jpg
    return 'http://origin.peg.tv/thumbnails/'. check_plain($parts['video']) .'.jpg';
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    $local_path = 'public://media-cloudcast/' . check_plain($parts['video']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      $response = drupal_http_request($this->getOriginalThumbnailPath());
      if (!isset($response->error)) {
        file_save_data($response->data, $local_path, TRUE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }
    return $local_path;
  }
}
