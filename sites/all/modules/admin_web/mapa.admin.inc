<?php
	
function mapa_configuracion(){
	$form['menu_mapa'] = array(
    '#title' => 'Menu mapa web',
	'#description' => 'Especificar el nombre del sistema del menu para el mapa web', 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('menu_mapa', ''),    
  );
  
  $form['vid_mapa'] = array(
    '#title' => 'ID del vocabulario',
	'#description' => 'Especificar el id del vocabulario de blog', 
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('vid_mapa', 0),    
  );
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Guardar configuración',
  );
  
  
  $form['#submit'][] = 'factoria_configuracion_submit';  
  return $form;
} 


/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function mapa_configuracion_submit($form, $form_state) {
  variable_set('menu_mapa', $form_state['values']['menu_mapa']);
  variable_set('vid_mapa',$form_state['values']['vid_mapa']);	
  
  drupal_set_message("Se han guardado las opciones de configuración.");
}