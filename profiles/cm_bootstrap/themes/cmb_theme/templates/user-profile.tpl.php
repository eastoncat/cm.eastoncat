<?php
/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/124. 124 being the users ID.
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
 *
 * @ingroup themeable
 */
global $user;
$account = $elements['#account'];
?>
<div class="profile"<?php print $attributes; ?>>
  <h1><?php echo $account->name ?></h1>
  <div class="row">
    <div class="col-lg-3 col-md-3 col-xs-12 user-profile-left-col no-padding">
      <?php //dpm($account); ?>
      <?php
        if (isset($account->picture->uri)) {
          $user_img_src = image_style_url('user_avatar_large', $account->picture->uri);
        }
        else {
          $user_img_src = $GLOBALS['base_url'] . '/' . path_to_theme() . '/images/user-avatar-large-placeholder.png';
        }
      ?>
      <img class="user-avatar-large" src="<?php print $user_img_src; ?>"/>
      <div class="user-details">
        <div class="btn btn-default">
          <?php
          if ($account->uid === $user->uid) {
            echo "<a href='/user/{$user->uid}/edit'>Edit Profile</a>";
          }
          ?>
          <?php if (module_exists('flag')): ?>
            <?php print flag_create_link('cf_follow_user', $account->uid); ?>
          <?php endif; ?>
        </div>
        <?php if (!empty($account->field_user_bio)): ?>
          <p style="padding: 10px 2px;">
            <?php print $account->field_user_bio[LANGUAGE_NONE][0]['value']; ?>
          </p>
        <?php endif; ?>
      </div>
    </div>
    <div class="col-lg-9 col-md-9 col-xs-12 user-profile-right-col">
      <?php $cf_user_statistics_blocks = module_invoke('cm_bootstrap_community', 'block_view', 'cf_user_statistics'); ?>
      <?php //dpm($cf_user_statistics_blocks); ?>
      <?php print render($cf_user_statistics_blocks['content']); ?>
      <div class="clearfix"></div>

      <?php if ($featured_video) { ?>
        <h2>Featured Video</h2>
        <?php echo render($featured_video); ?>
      <?php } ?>
    </div>
    <div class="col-lg-9 col-md-9 col-xs-12 user-profile-third-col">
      <h2>Recently Uploaded</h2>
      <div class="recent-videos">
        <?php $cf_user_recent_videos = module_invoke('cm_bootstrap_community', 'block_view', 'cf_user_recent_videos'); ?>
        <?php print render($cf_user_recent_videos['content']); ?>
      </div>
    </div>
  </div>
