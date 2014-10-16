<?php
/**
 * @file
 * f24_cargas_bids_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function f24_cargas_bids_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cargas_bids';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Cargas Bids';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'name' => 'name',
    'field_precio' => 'field_precio',
    'field_transito_dias' => 'field_transito_dias',
    'privatemsg_link' => 'privatemsg_link',
    'bid_award' => 'bid_award',
    'php' => 'php',
    'field_bid_awarded' => 'field_bid_awarded',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_precio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_transito_dias' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'privatemsg_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'bid_award' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_bid_awarded' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_carga_target_id']['id'] = 'field_carga_target_id';
  $handler->display->display_options['relationships']['field_carga_target_id']['table'] = 'field_data_field_carga';
  $handler->display->display_options['relationships']['field_carga_target_id']['field'] = 'field_carga_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_bid_awarded_target_id']['id'] = 'field_bid_awarded_target_id';
  $handler->display->display_options['relationships']['field_bid_awarded_target_id']['table'] = 'field_data_field_bid_awarded';
  $handler->display->display_options['relationships']['field_bid_awarded_target_id']['field'] = 'field_bid_awarded_target_id';
  $handler->display->display_options['relationships']['field_bid_awarded_target_id']['relationship'] = 'field_carga_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Transportista';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Nodo: Precio */
  $handler->display->display_options['fields']['field_precio']['id'] = 'field_precio';
  $handler->display->display_options['fields']['field_precio']['table'] = 'field_data_field_precio';
  $handler->display->display_options['fields']['field_precio']['field'] = 'field_precio';
  $handler->display->display_options['fields']['field_precio']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Nodo: Transito */
  $handler->display->display_options['fields']['field_transito_dias']['id'] = 'field_transito_dias';
  $handler->display->display_options['fields']['field_transito_dias']['table'] = 'field_data_field_transito_dias';
  $handler->display->display_options['fields']['field_transito_dias']['field'] = 'field_transito_dias';
  $handler->display->display_options['fields']['field_transito_dias']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Privatemsg: Send Privatemsg link */
  $handler->display->display_options['fields']['privatemsg_link']['id'] = 'privatemsg_link';
  $handler->display->display_options['fields']['privatemsg_link']['table'] = 'users';
  $handler->display->display_options['fields']['privatemsg_link']['field'] = 'privatemsg_link';
  $handler->display->display_options['fields']['privatemsg_link']['relationship'] = 'uid';
  $handler->display->display_options['fields']['privatemsg_link']['label'] = '';
  $handler->display->display_options['fields']['privatemsg_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['privatemsg_link']['subject'] = '%1';
  $handler->display->display_options['fields']['privatemsg_link']['return'] = 1;
  /* Field: Content: Bid Award */
  $handler->display->display_options['fields']['bid_award']['id'] = 'bid_award';
  $handler->display->display_options['fields']['bid_award']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['bid_award']['field'] = 'bid_award';
  $handler->display->display_options['fields']['bid_award']['rules_link'] = array(
    'rules_link_parameters' => '!1',
    'rules_link_rewrite' => 'Aceptar Oferta',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Nominado';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if (isset($data->node_field_data_field_bid_awarded_uid) &&  $data->users_node_uid == $data->node_field_data_field_bid_awarded_uid) {
  print "Seleccionado";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_bid_awarded_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Nodo: Carga (field_carga) */
  $handler->display->display_options['arguments']['field_carga_target_id']['id'] = 'field_carga_target_id';
  $handler->display->display_options['arguments']['field_carga_target_id']['table'] = 'field_data_field_carga';
  $handler->display->display_options['arguments']['field_carga_target_id']['field'] = 'field_carga_target_id';
  $handler->display->display_options['arguments']['field_carga_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_carga_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_carga_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_carga_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_carga_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bid' => 'bid',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Transportista';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bid' => 'bid',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $translatables['cargas_bids'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('author'),
    t('Nodo entity referenced from field_carga'),
    t('Nodo entity referenced from field_bid_awarded'),
    t('Nid'),
    t('Transportista'),
    t('Precio'),
    t('Transito'),
    t('Send message'),
    t('%1'),
    t('Bid Award'),
    t('Nominado'),
    t('All'),
    t('Block'),
  );
  $export['cargas_bids'] = $view;

  return $export;
}
