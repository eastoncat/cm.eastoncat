<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 */
?>


<?php 
$key = array_keys($user_profile['profile_main']['view']['profile2']);
$uid = $key[0];
?> 


<div id="user-profile">
    <?php if (isset($user_profile['user_picture']['#markup'])): ?>
      <div id="user-picture">
        <?php print $user_profile['user_picture']['#markup']; ?>
      </div>
    <?php endif; ?>
  
  <div id="user-contact-links">
    <?php if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_job_title'][0]['#markup'])): ?>
	  <div id="user-job-title"><?php print $user_profile['profile_main']['view']['profile2'][$uid]['field_job_title'][0]['#markup']; ?></div>
	<?php endif; ?>
	<!-- <?php print $user_profile['profile_main']['view']['profile2'][$uid]['field_email'][0]['#markup']; ?><br /> -->
	<?php if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_facebook'][0]['#markup'])): ?>
	  <div class="facebook"><?php print $user_profile['profile_main']['view']['profile2'][$uid]['field_facebook'][0]['#markup']; ?></div>
	<?php endif; ?>
	<?php if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_twitter'][0]['#markup'])): ?>
	  <div class="twitter"><?php print $user_profile['profile_main']['view']['profile2'][$uid]['field_twitter'][0]['#markup']; ?></div>
	<?php endif; ?>
	<?php if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_linkedin'][0]['#markup'])): ?>
	  <div class="linkedin"><?php print $user_profile['profile_main']['view']['profile2'][$uid]['field_linkedin'][0]['#markup']; ?></div>
	<?php endif; ?>
	
	<?php 
	$idn = 0; 
	$continue = TRUE;

	while ( $continue == TRUE ) {
		if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_other'][$idn]['#markup'])) { 
			print '<div class="other">' . $user_profile['profile_main']['view']['profile2'][$uid]['field_other'][$idn]['#markup'] . '</div>';
			$idn = $idn + 1;
		} else { 
			$continue = FALSE;
		}
	}
    ?>
	
  </div>
  
  <div id="user-bio">
    <?php 
      if (isset($user_profile['profile_main']['view']['profile2'][$uid]['field_bio'][0]['#markup'])) {
        print $user_profile['profile_main']['view']['profile2'][$uid]['field_bio'][0]['#markup']; 
      }
    ?>
  </div>
</div> 