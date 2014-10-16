<?php
/**
 * @file
 * content_type_bid.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_bid_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_bid_node_info() {
  $items = array(
    'bid' => array(
      'name' => t('Bid'),
      'base' => 'node_content',
      'description' => t('Publicar Bids en Cargas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
