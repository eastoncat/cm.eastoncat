<?php
/**
 * @file
 * cc_text_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cc_text_features_filter_default_formats() {
  $formats = array();

  // Exported format: cc_text_paragraph.
  $formats['cc_text_paragraph'] = array(
    'format' => 'cc_text_paragraph',
    'name' => 'cc_text_paragraph',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
