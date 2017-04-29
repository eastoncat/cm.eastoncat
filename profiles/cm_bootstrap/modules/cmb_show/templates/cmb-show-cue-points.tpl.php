<ol class="video-chapters-cue-points">
  <?php foreach($content as $cue_point): ?>
    <li>
      <div class="cue-field-popcornjs">
        <a href="#" data-cfpopcorn-id="<?php print $cue_point['fid']; ?>" data-cfpopcorn-start="<?php print $cue_point['start']; ?>" data-cfpopcorn-title="4. Planning Day" data-cfpopcorn-type="cue_field_popcornjs">
          <span class="title"><?php print $cue_point['title']; ?></span> —
          <span class="hms hms-format-m-ss"><?php print gmdate('H:i:s', $cue_point['start']); ?></span>
          <span class="description"><?php print $cue_point['description']; ?></span>
        </a>
      </div>
    </li>
  <?php endforeach; ?>
</ul>
