<?php
/**
 * @file
 * cm_bootstrap_search_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function cm_bootstrap_search_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function cm_bootstrap_search_features_default_search_api_index() {
  $items = array();
  $items['site_search_index'] = entity_import('search_api_index', '{
    "name" : "Site Search Index",
    "machine_name" : "site_search_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "article",
          "blog",
          "page",
          "genre",
          "partner",
          "cm_project",
          "cm_show",
          "cmbs_producer",
          "cmbs_event"
        ]
      },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "field_cmbs_producer_bio" : { "type" : "text" },
        "field_cmbs_producer_email" : { "type" : "text" },
        "field_cmbs_producer_phone" : { "type" : "text" },
        "field_content_components:field_cc_cl_description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_cl_item_abstract" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_cl_item_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_s_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_tai_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_text_paragraph:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_content_components:field_cc_twb_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_description:summary" : { "type" : "text" },
        "field_description:value" : { "type" : "text" },
        "field_show_participants" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_show_participants:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_teaser" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function cm_bootstrap_search_features_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
