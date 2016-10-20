<?php

/**
 * PART 1. Basic Color module settings
 */

$info = array();

// Define the possible replaceable items and their labels.
$info['fields'] = array(
  'base' => t('Base color'),
  'page_bg' => t('Page background'),
  'link' => t('Link color'),
  'link_hover' => t('Link hover color'),
  'button_gradient_top' => t('Submit button gradient background top'),
  'button_gradient_bottom' => t('Submit button gradient background bottom'),
  'button_color' => t('Submit button text color'),
  'nodelinks_gradient_top' => t('Node & comment links gradient background top'),
  'nodelinks_gradient_bottom' => t('Node & comment links  gradient background bottom'),
  'nodelinks_color' => t('Node & comment links text color'),
  'text' => t('Text color'),
  'main_menu_color' => t('Main menu link color'),
  'main_menu_active' => t('Main menu active item link color'),
  'main_menu_active_bg' => t('Main menu active item background color'),
  'main_menu_bg_hover' => t('Main menu hover background'),
  'tabs_bg' => t('Tabs background color'),
  'tabs_border' => t('Tabs border color'),
  'header_bg_gradient_top' => t('Header background gradient top'),
  'header_bg_gradient_bottom' => t('Header background gradient bottom'),
);

// Color schemes for the site.
$info['schemes'] = array(
  // Define the default scheme.
  'default' => array(
    // Scheme title.
    'title' => t('Default colors'),
    // Scheme colors (Keys are coming from $info['fields']).
    'colors' => array(
	  'base' => '#cccccc',
	  'page_bg' => '#2a2a2a',
	  'link' => '#b20000',
	  'link_hover' => '#003b18',
	  'button_gradient_top' => '#373737',
	  'button_gradient_bottom' => '#686868',
	  'button_color' => '#fcfcfc',
	  'nodelinks_gradient_top' => '#aaaaaa',
	  'nodelinks_gradient_bottom' => '#cccccc',
	  'nodelinks_color' => '#353535',
      'text' => '#333333',
      'main_menu_color' => '#ffffff',
      'main_menu_active' => '#fefefe',
      'main_menu_active_bg' => '#c60203',
	  'main_menu_bg_hover' => '#4c4c4c',
      'tabs_bg' => '#f0f0f0',
      'tabs_border' => '#e3e3e3',
	  'header_bg_gradient_top' => '#2c2c2c',
	  'header_bg_gradient_bottom' => '#0c0c0c',
	  ),
  ),
  // Let's create a scheme called OKV.
  'drupal_love' => array(
    // Scheme title.
    'title' => t('OKV'),
    // Scheme colors (Keys are coming from $info['fields']).
    'colors' => array(
	  'base' => '#0c0c0c',
	  'page_bg' => '#0c0c0c',
	  'link' => '#215e8b',
      'link_hover' => '#ee8d26',
	  'button_gradient_top' => '#05527e',
	  'button_gradient_bottom' => '#39799d',
	  'button_color' => '#ffffff',
	  'nodelinks_gradient_top' => '#bbd0e3',
	  'nodelinks_gradient_bottom' => '#d5e3ef',
	  'nodelinks_color' => '#333333',
      'text' => '#372E2E',
      'main_menu_color' => '#ffffff',
      'main_menu_active' => '#ffffff',
      'main_menu_active_bg' => '#05527e',
	  'main_menu_bg_hover' => '#4c4c4c',
	  'tabs_bg' => '#f2f2f2',
      'tabs_border' => '#e3e3e3',
	  'header_bg_gradient_top' => '#020202',
	  'header_bg_gradient_bottom' => '#1d1d1d',
    ),
  ),
);

// Define the CSS file(s) that we want the Color module to use as a base.
$info['css'] = array(
  'css/colors.css',
  '../../modules/cm_slideshow/cm_slideshow.css',
);

/***** Advanced Color settings - Defaults. Will be used in the Part 2. *****/

/**
 * Default settings for the advanced stuff.
 * No need to edit these if you just want to play around with the colors.
 * Color wants these, otherwise it's not going to play.
 *
 * We dive deeper into these in the Part 2. Advanced Color settings
 */

// Files we want to copy along with the CSS files, let's define these later.
$info['copy'] = array(
  'logo.png'
);

// Files used in the scheme preview.
$info['preview_css'] = 'color/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

// Gradients
$info['gradients'] = array();

// Color areas to fill (x, y, width, height).
$info['fill'] = array();

// Coordinates of all the theme slices (x, y, width, height)
// with their filename as used in the stylesheet.
$info['slices'] = array();

// Base file for image generation.
$info['base_image'] = 'color/base.png';

// Reference color used for blending. Matches the base.png's colors.
$info['blend_target'] = '#ffffff';