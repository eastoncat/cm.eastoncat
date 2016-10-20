INTRODUCTION
------------

The Media Cloudcast Chapters module provides a chapter field type for cloudcast video files and provides an 
automated import process.  Minimal CSS has been included to get you started with display.  An example view has
been provided for advanced display options.   

REQUIREMENTS
------------
This module requires the following modules:
 * Media Cloudcast (https://www.drupal.org/project/media_cloudcast)
 * Views (https://drupal.org/project/views)

RECOMMENDED MODULES AND THEMES
-------------------
 * Bootstrap 3 (https://www.drupal.org/project/bootstrap)
   The included example view uses Bootstrap markup to display the chapters in tabs.  If you do not want to 
   use the full Bootstrap 3 theme, you can simply use the Bootstrap framework within your own theme.(http://getbootstrap.com/)

INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.  Be sure to install both the Media Cloudcast Chapters and Media Cloudcast Chapters Fields modules.

 * If you would like to use the included example view, enable it from http://example.com/admin/structure/views

 * UNINTSTALL - You will need to uninstall the Media Cloudcast Chapters Module first in order to delete the fields from the
   database. Only once those fields are deleted will you be able to uninstall the Media Cloudcast Chapters Field module.
 
CONFIGURATION
-------------
 * Configure module settings at Configuration -> Media -> Chapters
 * You can run the import automatically or manually from the configuration page.
 * You can set the permissions for editing the configuration under People -> Permissions

