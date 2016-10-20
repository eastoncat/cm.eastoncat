<?php

/**
 * @file media_cloudcast/includes/MediaCloudcastBrowser.inc
 *
 * Definition of MediaCloudcastBrowser.
 */

/**
 * Media browser plugin for displaying a specific view and display.
 */
class MediaCloudcastBrowser extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPluginInterface::access().
   */
  public function access($account = NULL) {
    // @todo Replace with file_access().
    return media_access('edit', $account);
  }

  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    // Check if the user is able to add remote media.
    if (user_access('add media from remote sources')) {
      $build['form'] = drupal_get_form('media_cloudcast_add', $this->params['types'], $this->params['multiselect']);
      return $build;
    }
  }
}
