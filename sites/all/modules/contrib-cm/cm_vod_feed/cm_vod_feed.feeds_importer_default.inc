<?php
/**
 * @file
 * cm_vod_feed.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function cm_vod_feed_feeds_importer_default() {
  $export = array();

	$feeds_importer = new stdClass();
	$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
	$feeds_importer->api_version = 1;
	$feeds_importer->id = 'cm_vod_importer';
	$feeds_importer->config = array(
		'name' => 'VOD Importer',
		'description' => '',
		'fetcher' => array(
			'plugin_key' => 'FeedsHTTPFetcher',
			'config' => array(
				'auto_detect_feeds' => FALSE,
				'use_pubsubhubbub' => FALSE,
				'designated_hub' => '',
				'request_timeout' => NULL,
			),
		),
		'parser' => array(
			'plugin_key' => 'FeedsMediaRSSParser',
			'config' => array(),
		),
		'processor' => array(
			'plugin_key' => 'FeedsEntityProcessorFile',
			'config' => array(
				'mappings' => array(
					0 => array(
						'source' => 'url',
						'target' => 'url',
						'unique' => 1,
					),
					1 => array(
						'source' => 'guid',
						'target' => 'guid',
						'unique' => FALSE,
					),
					2 => array(
						'source' => 'title',
						'target' => 'field_title',
						'unique' => FALSE,
					),
				),
				'update_existing' => '1',
				'input_format' => 'plain_text',
				'skip_hash_check' => 0,
				'bundle' => 'video',
				'values' => array(
					'type' => 'video',
				),
			),
		),
		'content_type' => 'cm_vod_feed',
		'update' => 0,
		'import_period' => '1800',
		'expire_period' => 3600,
		'import_on_create' => 1,
		'process_in_background' => 0,
	);
  $export['cm_vod_importer'] = $feeds_importer;

  return $export;
}
