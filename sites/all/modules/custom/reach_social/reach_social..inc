<?php
/**
 * @file
 * reach_social..inc
 */

/**
 * Implements hook_default_oauthconnector_provider().
 */
function reach_social_default_oauthconnector_provider() {
  $export = array();

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'facebook';
  $provider->title = 'Facebook';
  $provider->url = 'https://graph.facebook.com';
  $provider->consumer_advanced = array(
    'oauth2' => 1,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/oauth/request_token',
    'authorization scope' => 'email,read_stream,user_photos,publish_stream',
    'authorization endpoint' => 'https://www.facebook.com/dialog/oauth',
    'access token endpoint' => '/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'https://graph.facebook.com/me',
        'method post' => 0,
        'field' => 'id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'name' => array(
        'resource' => 'https://graph.facebook.com/me',
        'method post' => 0,
        'field' => 'name',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'avatar' => array(
        'resource' => '',
        'method post' => 0,
        'field' => '',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
    ),
    'format' => 'json',
  );
  $export['facebook'] = $provider;

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'flickr';
  $provider->title = 'Flickr';
  $provider->url = 'http://www.flickr.com';
  $provider->consumer_advanced = array(
    'oauth2' => 0,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/services/oauth/request_token',
    'authorization scope' => '',
    'authorization endpoint' => '/services/oauth/authorize?perms=read',
    'access token endpoint' => '/services/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'http://api.flickr.com/services/rest/?method=flickr.test.login&format=json&nojsoncallback=1',
        'method post' => 0,
        'field' => 'user.id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'name' => array(
        'resource' => 'http://api.flickr.com/services/rest/?method=flickr.test.login&format=json&nojsoncallback=1',
        'method post' => 0,
        'field' => 'user.username._content',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'avatar' => array(
        'resource' => '',
        'method post' => 0,
        'field' => '',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
    ),
    'format' => 'json',
  );
  $export['flickr'] = $provider;

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'google';
  $provider->title = 'Google';
  $provider->url = 'https://accounts.google.com';
  $provider->consumer_advanced = array(
    'oauth2' => 1,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => 'authorization_code',
    'request token endpoint' => 'none',
    'authorization scope' => 'https://www.googleapis.com/auth/userinfo.profile',
    'authorization endpoint' => '/o/oauth2/auth',
    'access token endpoint' => '/o/oauth2/token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'https://www.googleapis.com/oauth2/v1/userinfo',
        'method post' => 0,
        'field' => 'email',
        'querypath' => FALSE,
        'sync_with_field' => 'mail',
      ),
      'name' => array(
        'resource' => 'https://www.googleapis.com/oauth2/v1/userinfo',
        'method post' => 0,
        'field' => 'name',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'avatar' => array(
        'resource' => '',
        'method post' => 0,
        'field' => 'picture',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
    ),
    'format' => 'json',
  );
  $export['google'] = $provider;

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'twitter';
  $provider->title = 'Twitter';
  $provider->url = 'https://api.twitter.com';
  $provider->consumer_advanced = array(
    'oauth2' => 0,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/oauth/request_token',
    'authorization scope' => '',
    'authorization endpoint' => '/oauth/authorize',
    'access token endpoint' => '/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'name' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'name',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'avatar' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'profile_image_url',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
    ),
    'format' => 'json',
  );
  $export['twitter'] = $provider;

  return $export;
}
