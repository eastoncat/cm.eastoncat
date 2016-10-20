<?php
// this is example given here:  https://www.drupal.org/node/495654
// Plugin definition
$plugin = array(
  'title' => t('One row two columns'),
  'category' => t('ZenBase'),
  'icon' => 'onerowtwocols.png',
  'theme' => 'onerowtwocols',
  'css' => 'onerowtwocols.css',
  'regions' => array(
    'top' => t('Top'),
    'right' => t('Right side'),
    'left' => t('Left side')
  ),
);

