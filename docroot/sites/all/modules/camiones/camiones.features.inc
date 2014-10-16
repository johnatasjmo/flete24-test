<?php
/**
 * @file
 * camiones.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function camiones_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function camiones_node_info() {
  $items = array(
    'camiones' => array(
      'name' => t('Camiones'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tu referencia:'),
      'help' => '',
    ),
  );
  return $items;
}
