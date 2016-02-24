<?php

/**
 * @file
 * inc file for miscellaneous helper and callbak functions
 */

/**
 * Menu callback function
 * @param  string $api_key API key passed through url
 * @param  object $node    node object of nid passed through url
 * @return json          Contditional json output
 */
function site_api_key_page_json($api_key, $node) {
	$stored_api_key = variable_get('siteapikey');
  if ((!empty($stored_api_key)) && ($api_key == $stored_api_key) && $node->type == "page") {
    return drupal_json_output($node);
  }
  else {
    return drupal_json_output(array('access denied'));
  }
}
