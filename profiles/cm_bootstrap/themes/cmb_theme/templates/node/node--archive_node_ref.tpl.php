<?php //dpm($node); ?>
<?php $block = module_invoke('cm_bootstrap_archive', 'block_view', 'cmb_archive_two_col'); ?>
<?php print render($block['content']); ?>
