<?php

function _cf_user_statistics() {
  //$variables['recent_videos'] = _cm_bootstrap_community_get_recent_videos($account->uid);
  //$variables['following'] = _cm_bootstrap_community_get_following($account->uid);
  //$variables['follows'] = _cm_bootstrap_community_get_follows($account->uid);
  //$variables['likes'] = _cm_bootstrap_community_get_likes($account->uid);
  //$variables['video_count'] = _cm_bootstrap_community_get_user_video_count($account->uid);
  
  $uid = arg(1);
  $user = user_load($uid);
  //dpm($user);
  
  $build = array(
    'uid' => $uid,
    'user_name' => _cf_user_statistics_clean_user_name($user->name),
    'video_count' => _cm_bootstrap_community_get_user_video_count($uid),
    'following_count' => _cm_bootstrap_community_get_following($uid),
    'followers_count' => _cm_bootstrap_community_get_follows($uid),
    'likes_count' => _cm_bootstrap_community_get_likes($uid),
  );
  
  // Send data to TPL.  
  return theme('cf_user_statistics', 
    array (
      'content' => $build,
    )
  ); 
}

function _cf_user_statistics_clean_user_name($string) {
   // Replaces all spaces with hyphens.
   $string = str_replace(' ', '-', $string);
   // Lowercase
   $string = strtolower($string);
   // Removes special chars.
   return preg_replace('/[^A-Za-z0-9\-]/', '', $string);
}