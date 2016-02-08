<?php
/**
 * @file
 * Callbacks de administración del módulo saludar.
 */
 


/**
 * Define el formulario de opciones de configuración.
 */
function alias_hierarchy_taxonomy_configuracion() { 
	
	
	$vocabularios=array();
	$vocabularios['_none']='--Seleccione--';
	$sql= db_select('taxonomy_vocabulary','t');
	$sql->fields('t',array('vid','name'));
	$resul = $sql->execute();
	while( $fil= $resul->fetchAssoc() ) {
	  $vid=$fil['vid'];
	  $vocabularios[$vid]=$fil['name'];

	}
  
	$form['taxonomias'] = array(
		'#type' => 'fieldset',
		'#title' => 'Vocabularios'
	);

  
 	$form['taxonomias']['vocabularios'] = array(
		'#type' => 'select',
		'#default_value' => variable_get('alias_hierarchy_taxonomy', '_none'),
		'#options' => $vocabularios,
		'#multiple' => TRUE, 
	);
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Guardar configuración',
  );
  
  
  $form['#submit'][] = 'alias_hierarchy_taxonomy_configuracion_submit';  
  return $form;
}


/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function alias_hierarchy_taxonomy_configuracion_submit($form, $form_state) {
  variable_set('alias_hierarchy_taxonomy', $form_state['values']['vocabularios']);	
  
  drupal_set_message("Se han guardado las opciones de configuración.");
}