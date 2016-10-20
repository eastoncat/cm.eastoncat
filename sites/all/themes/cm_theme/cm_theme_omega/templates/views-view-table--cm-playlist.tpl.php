<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
        <?php print '<th>Start</th>' ?>
		<?php print '<th>Slut</th>' ?>
        
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php $accumulated_duration = 0; ?>
	

    <?php foreach ($rows as $row_count => $row): ?>
      <?php 
      //dsm($row);
      //replace formatting strings with nothing the hh:mm:ss value
          
      $duration = str_replace('<span class="hms hms-format-h-mm-ss">', '', $row['field_okv_duration']);
      $duration = str_replace('</span>', '', $duration);
      $seconds = cinegy_hms2sec($duration);

      $row['field_okv_duration'] = NULL;
      //round up to next 5 minute
      //$rounded = round($duration/360)*360;
      $accumulated_duration = ceil($accumulated_duration/300)*300;
      $formatted_starttime = (cinegy_sec2hms($accumulated_duration));      
	  $accumulated_endtime = $accumulated_duration + $seconds;
	  $formatted_endtime = (cinegy_sec2hms($accumulated_endtime));

      ?>
      <tr class="<?php print implode(' ', $row_classes[$row_count]); ?>">
        <?php foreach ($row as $field => $content): ?>
    
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
          </td>  
        <?php endforeach; ?>
          <?php print '<td class="nowrap">' . $formatted_starttime . '</td>' ?>
		  <?php print '<td class="nowrap">' . $formatted_endtime . '</td>' ?>
      </tr>
	  
	  <?php 
	  $accumulated_duration = ($accumulated_duration + $seconds);
      //round up to next 5 minute
      //$rounded = round($duration/360)*360;
      $accumulated_duration = ceil($accumulated_duration/300)*300;
      $formatted_duration = (cinegy_sec2hms($accumulated_duration));
	  ?>
	  
    <?php endforeach; ?>
  </tbody>
</table>