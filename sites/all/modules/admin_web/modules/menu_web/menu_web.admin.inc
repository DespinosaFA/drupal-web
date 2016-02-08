<?php
/**
 * @file
 * Callbacks de administración del módulo saludar.
 */

/**
 * Define el formulario de opciones de configuración.
 */
function menu_web_configuracion() { 
  
 $menu=variable_get('menu_web');
  
  $form['uid'] = array(
    '#title' => 'Id Usuario Soporte',
	'#description' => 'Especificar el uid del usuario en la pagina de soporte', 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $menu['uid'],    
  );
  
  $form['menu'] = array(
    '#title' => 'Menu',
	'#description' => 'Especificar nombre interno del menu propietario', 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $menu['menu'],    
  );
  
   $form['proyecto'] = array(
    '#title' => 'Id Proyecto',
	'#description' => 'Especificar el id del proyecto', 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $menu['proyecto'],    
  );
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Guardar configuración',
  );
  
  
  $form['#submit'][] = 'menu_web_configuracion_submit';  
  return $form;
}


/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function menu_web_configuracion_submit($form, $form_state) {
	$menu['uid']=$form_state['values']['uid'];
	$menu['menu']=$form_state['values']['menu'];
	$menu['proyecto']=$form_state['values']['proyecto'];
	variable_set('menu_web',$menu);  
	drupal_set_message("Se han guardado las opciones de configuración.");
}