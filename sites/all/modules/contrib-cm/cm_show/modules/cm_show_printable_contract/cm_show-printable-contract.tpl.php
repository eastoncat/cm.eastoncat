<?php
/**
 * @file
 * Printable contract template.
 */

global $base_path;
$logourl = theme_get_setting('logo_path', '');
?>
  <html>
    <head>
      <title>Contract</title>
      <link type="text/css" rel="stylesheet" href="<?php print $base_path ?><?php print drupal_get_path('module', 'cm_show_printable_contract'); ?>/contract.css" />
    </head>
    <body>
      <div id="page">
        <div id="header">
        <?php if ($logourl) { ?>
           <img src="<?php print $base_path ?><?php print $logourl ?>">
        <?php } ?>
        <h2><?php print variable_get('site_name', ''); ?> Show Submission Agreement</h2>
        <?php if (module_exists('token')) {
          print token_replace(variable_get('cm_show_contract_header', ''), array('node' => $node));
        }
        else {
          print variable_get('cm_show_contract_header','') . '<br />';
        }
        ?>

        Name: <?php print $username ?><br />
        Email: <?php print $email ?><br />
        <?php print $phone ? "Phone: $phone" . '<br />' : '' ?>
        
        <?php print $node->title ?><br />
        <?php print $node->body ?>
        
        <?php //Creative Commons ?>

          
        <div id="boilerplate"><?php module_exists('token') ? print(token_replace(variable_get('cm_show_contract_boilerplate', ''), array('node' => $node))) : print(variable_get('cm_show_contract_boilerplate','')) ?></div>
        <div id="footer"><?php module_exists('token') ? print(token_replace(variable_get('cm_show_contract_footer', ''), array('node' => $node))) : print(variable_get('cm_show_contract_footer','')) ?></div>
      </div>
    </body>
