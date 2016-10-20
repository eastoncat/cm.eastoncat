<?php
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 
?>

<ul id="MySkills">

<?php //handling the No Results Here so we can use PHP ?>
<?php if(empty($fields)): ?>
  <?php if(is_numeric(arg(2)) && $user->uid != arg(2)): ?>
This user has not rated their skills.
  <?php endif; ?>
  <?php if(is_null(arg(2)) ||$user->uid == arg(2)): ?>
    <?php print l('Rate my skills.', 'user/' . $user->uid . '/edit/skills') ?>
  <?php endif; ?>
<?php endif; ?>
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <li class="MySkill clear-block">
  	<span class="MySkill-name"><?php print $field->label; ?></span>
    <span class="MySkill-level skill-level-<?php print $field->content; ?>"> 
	  <span class="l-graph"></span>
	  <span class="l-name"></span>
	</span>
  </li>
<?php endforeach; ?>
</ul>
<?php if(!empty($fields)): ?>
  <?php if(is_null(arg(2)) ||$user->uid == arg(2)): ?>
    <?php print l('Update my skills.', 'user/' . $user->uid . '/edit/skills') ?>
  <?php endif; ?>
<?php endif; ?>
