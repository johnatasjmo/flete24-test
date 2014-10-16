<?php

/**
 * @file template.php
 */

 /**
 * Overrides theme_menu_link().
 */
function bootstrapf24_preprocess_menu_link(&$variables) {
	global $user;
	$variables['element']['#attributes']['class'][] = 'menu-' . $variables['element']['#original_link']['mlid'];
	$menu_title_class = preg_replace("/[^a-zA-Z0-9]/", "-", strtolower(strip_tags($variables['element']['#title'])));
	// Another option $menu_title_class = preg_replace("/[^a-zA-Z0-9]/", "-", strtolower(strip_tags($variables['element']['#original_link']['link_title'])));
	$variables['element']['#attributes']['class'][] = 'menu-' . $menu_title_class;
	
	if ($variables['element']['#original_link']['menu_name'] == 'user-menu') {
		$variables['element']['#localized_options']['html']= true;
		$variables['element']['#title'] = '<span>'.$variables['element']['#title'].'</span>';
		
		if ($variables['element']['#href'] == 'user' && $user->uid) {
			$account = clone $user;
			// remove uid for remove link
			$account->uid = 0;
			$user_picture = theme('user_picture', array('account' => $account)); 
			/*if(!$user_picture){ 
				$user_picture = theme('image', array('attributes' => array('src' => path_to_theme())));
			} */
			$variables['element']['#title'] = $user_picture .' <span class="username">'.$user->name.'</span>'; 
		}
	}	
	
	$icon = '';
	switch ($variables['element']['#href']) {
		case 'mis-cargas':
			$icon = _bootstrap_icon('th-large');
			break;
		case 'mis-camiones':
			$icon = _bootstrapf24_icon('truck');
			break;
		case 'messages':
			$icon = _bootstrapf24_icon('envelope');
			break;
		case 'user/logout':
			$icon = _bootstrapf24_icon('off');
			break;
			 
	}
	
	if ($icon) {
		$variables['element']['#title'] = $icon.' <span class="hide">'.$variables['element']['#title'].'</span>';
		$variables['element']['#localized_options']['html']= true;
	}
	
}

function _bootstrapf24_icon($name) {
  $output = '';
	if ($name) {
	  $attributes = array(
	    'class' => array('icon-' . $name),
	  );
	  $output = '<i' . drupal_attributes($attributes) . '></i>';
	}
  return $output;
}