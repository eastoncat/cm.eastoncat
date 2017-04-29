<?php
/**
 * @file
 * cmb_show_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cmb_show_features_taxonomy_default_vocabularies() {
  return array(
    'editing_location' => array(
      'name' => 'Editing Location',
      'machine_name' => 'editing_location',
      'description' => 'Where is the Show during post production',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
