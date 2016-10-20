<?php


/**
 * Settings form for admin/config/media/chapters.
 * 
 * @return type form
 */
function media_cc_chapters_settings() {
  $form = array();

  $form['import'] = array(
      '#type' => 'fieldset',
      '#title' => t('Import Chapters'),
      '#collapsible' => true,
      '#collapsed' => false
  );

  $form['import']['media_cc_chapters_xml_feed_url'] = array(
      '#type' => 'textfield',
      '#title' => t('XML Feed URL'),
      '#default_value' => variable_get('media_cc_chapters_xml_feed_url', 'http://cloudcast.telvue.com/pegtv/chapters.xml'),
      '#description' => 'Set the base url from which to retrieve the chapters xml feed.'
  );

  $form['import']['media_cc_chapters_run_cron'] = array(
      '#type' => 'checkbox',
      '#title' => t('Run Import Automatically'),
      '#default_value' => variable_get('media_cc_chapters_run_cron'),
      '#description' => "Check this box to run import automatically on cron."
  );

  $form['import']['media_cc_chapters_cron_frequency'] = array(
      '#type' => 'select',
      '#title' => 'Import Frequency',
      '#default_value' => variable_get('media_cc_chapters_cron_frequency'),
      '#description' => "Select the frequency to run chapter import.",
      '#options' => array(
          -1 => 'Every Cron Run',
          3 => 'Every 3 Hours',
          6 => 'Every 6 Hours',
          12 => 'Every 12 hours',
          24 => 'Every 24 hours'
      )
  );

  $form['import']['media_cc_chapters_num_chapter_import'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of Shows'),
      '#default_value' => variable_get('media_cc_chapters_num_chapter_import'),
      '#description' => 'Set the number of recent shows for which to import chapters.  Set to -1 to import all.'
  );

  $form['import']['import_recent'] = array(
      '#type' => t('button'),
      '#value' => 'Import Most Recent Chapters',
      '#submit' => array('media_cc_chapters_import_recent_submit'),
      "#executes_submit_callback" => true,
      '#description' => 'Will import the chapters for the number of shows set above.'
  );

  $form['import']['import_all'] = array(
      '#type' => 'button',
      '#value' => t('Import All Chapters'),
      "#executes_submit_callback" => true,
      '#submit' => array('media_cc_chapters_import_all_submit')
  );

  return system_settings_form($form);
}

/**
 * 
 * Submit handler for importing all chapters
 * 
 * @param type $form
 * @param type $form_state
 */
function media_cc_chapters_import_all_submit(&$form, &$form_state) {
  $batch = array(
      'title' => t('Importing'),
      'operations' => array(
          array('_media_cc_chapters_import_shows', array(-1))
      ),
      'finished' => '_media_cc_chapters_import_finished',
      'file' => drupal_get_path("module", "media_cc_chapters") . "/inc/import.php"
  );
  batch_set($batch);
}

/**
 * Submit handler for importing most recent x shows
 * 
 * @param type $form
 * @param type $form_state
 */
function media_cc_chapters_import_recent_submit(&$form, &$form_state) {
  $batch = array(
      'title' => t('Importing'),
      'operations' => array(
          array('_media_cc_chapters_import_shows', array($form_state['values']['media_cc_chapters_num_chapter_import']))
      ),
      'finished' => '_media_cc_chapters_import_finished',
      'file' => drupal_get_path("module", "media_cc_chapters") . "/inc/import.php"
  );
  batch_set($batch);
}

/**
 * Batch processing function to run import and collect data.
 * 
 * @param type $limit
 * @param type $context
 */
function _media_cc_chapters_import_shows($limit, &$context) {
  // set up initial limits
  $process_per = 10;
  if (!isset($context['sandbox']['progress'])) {
    $context['results']['total'] = 0;
    $context['results']['files'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $limit > 0 ? $limit : db_query("SELECT COUNT(*) FROM {file_managed} WHERE filemime = 'video/cloudcast'")->fetchField();
  }

  // do import
  $result = _media_cc_chapters_do_import($context['sandbox']['progress'], min($process_per, $context['sandbox']['max'] - $context['sandbox']['progress']));

  // update progress
  $context['results']['total'] += $result['total'];
  $context['results']['files'] = array_merge($context['results']['files'], $result['files']);
  $context['sandbox']['progress'] += $result['total'];
  $context['message'] = t("Now Processing Videos %start - %finish", array('%start' => $context['sandbox']['progress'] + 1, '%finish' => $context['sandbox']['progress'] + $process_per));

  // inform batch engine that we are not finished and provide an estimation for completion
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];    
  } else {
    $context['message'] = 'Finished!';
  }
}

/**
 * Do the actual import.  Can be called from cron or from batch processing on settings page.
 * 
 * @param type $first
 * @param type $last
 * @return int
 */
function _media_cc_chapters_do_import($start, $length) {
  // set initial totals
  $totals = array(
      'total' => 0,
      'files' => array()
  );
  // get url from settings
  $url = variable_get("media_cc_chapters_xml_feed_url", "http://cloudcast.telvue.com/pegtv/chapters.xml");
  // get files
  $result = db_select('file_managed')
          ->fields('file_managed', array('filename', 'fid'))
          ->condition('filemime', 'video/cloudcast', '=')
          ->orderBy('fid', 'DESC')
          ->range($start, $length)
          ->execute();
  // loop through files
  while ($row = $result->fetch(PDO::FETCH_OBJ)) {
    // add one to the total
    $totals['total'] ++;
    // load chapters from thr url
    $xml = simplexml_load_file("$url?video_id={$row->filename}");
    // skip if there are no chapters
    if (!isset($xml->chapter))
      continue;
    // add to data
    $totals['files'][] = array('fid' => $row->fid, 'filename' => $row->filename);
    // add chapters to database
    $chapters = array();
    foreach ($xml->chapter as $chapter) {
      $chapters[] = array(
          'cid' => (int) $chapter->id,
          'start' => (int) $chapter->start,
          'title' => (string) _media_cc_chapters_clean_string($chapter->title),
          'description' => (string) _media_cc_chapters_clean_string($chapter->description)
      );
    }   

    $file = file_load($row->fid);
    $file->video_chapters[LANGUAGE_NONE] = $chapters;
    file_save($file);
  }
  return $totals;
}

/**
 * Finished batch processing
 * 
 * @param type $success
 * @param type $results
 * @param type $operations
 */
function _media_cc_chapters_import_finished($success, $results, $operations) {
  global $baseurl;
  if ($success) {
    drupal_set_message("Chapter import complete.  " . count($results['files']) . "/{$results['total']} shows had chapters to import.");
    foreach ($results['files'] as $file) {
      drupal_set_message("Retrieved chapters for File " . l($file['filename'], url("file/{$file['fid']}/usage", array('absolute' => true))));
    }
  } else {
    drupal_set_message("Finished with an error", 'error');
  }
}


function _media_cc_chapters_clean_string($string) {
  $string = iconv('UTF-8', 'UTF-8//IGNORE', $string);
  return preg_replace(array('~\r\n?~', '~[^\P{C}\t\n]+~u'), array("\n", ''), $string);
}
