<?php
/**
 * @file
 * cmb_cc_block_reference_features.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function cmb_cc_block_reference_features_paragraphs_info() {
  $items = array(
    'cmb_block_reference' => array(
      'name' => 'CMB Block Reference',
      'bundle' => 'cmb_block_reference',
      'locked' => '1',
    ),
  );
  return $items;
}
