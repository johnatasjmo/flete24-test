<?php
/**
 * @file
 * cargas.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cargas_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cargas_node_info() {
  $items = array(
    'cargas' => array(
      'name' => t('Cargas'),
      'base' => 'node_content',
      'description' => t('Publicar fletes'),
      'has_title' => '1',
      'title_label' => t('Tu referencia:'),
      'help' => '',
    ),
  );
  return $items;
}
