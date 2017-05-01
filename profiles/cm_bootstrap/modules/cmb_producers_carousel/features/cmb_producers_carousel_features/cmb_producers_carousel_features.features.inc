<?php
/**
 * @file
 * cmb_producers_carousel_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_producers_carousel_features_paragraphs_info() {
  $items = array(
    'cmb_producers_carousel' => array(
      'name' => 'CMB Producers Carousel',
      'bundle' => 'cmb_producers_carousel',
      'locked' => '1',
    ),
  );
  return $items;
}
