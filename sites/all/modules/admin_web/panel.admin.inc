<?php
	
function panel_configuracion($form, &$form_state){
	drupal_add_library('color_field', 'bgrins-spectrum');
	
	$form['colores_panel']=array(
		'#type' => 'fieldset',
		'#title' => 'Colores',
		'#tree' => TRUE,
	);
	
	$panel=variable_get('panel');
	
	
	$field_color_panel=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Cabecera',
			'#type' => 'textfield',
			'#default_value' => isset($panel['branding']['rgb']) ? $panel['branding']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($panel['branding']['opacity']) ? $panel['branding']['opacity'] : '',
		),
		'#instance_settings' => array(
			'show_input' => 1,
			'show_palette' => 1,
			'palette' => 1,
			'show_palette_only' => 0,
			'show_buttons' => 1,
			'allow_empty' => 1,
			'default_colors' => ''
		),
	);
	
	$form['colores_panel']['branding']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_panel
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),		
	);
	
	
	$field_color_cabecera_tabla=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Cabecera tablas',
			'#type' => 'textfield',
			'#default_value' => isset($panel['cabeceras_tablas']['rgb']) ? $panel['cabeceras_tablas']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($panel['cabeceras_tablas']['opacity']) ? $panel['cabeceras_tablas']['opacity'] : '',
		),
		'#instance_settings' => array(
			'show_input' => 1,
			'show_palette' => 1,
			'palette' => 1,
			'show_palette_only' => 0,
			'show_buttons' => 1,
			'allow_empty' => 1,
			'default_colors' => ''
		),
	);
	
	$form['colores_panel']['cabeceras_tablas']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_cabecera_tabla
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),		
	);
	
	
	$field_color_filas_tabla=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Filas tablas',
			'#type' => 'textfield',
			'#default_value' => isset($panel['filas_tablas']['rgb']) ? $panel['filas_tablas']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($panel['filas_tablas']['opacity']) ? $panel['filas_tablas']['opacity'] : '',
		),
		'#instance_settings' => array(
			'show_input' => 1,
			'show_palette' => 1,
			'palette' => 1,
			'show_palette_only' => 0,
			'show_buttons' => 1,
			'allow_empty' => 1,
			'default_colors' => ''
		),
	);
	
	$form['colores_panel']['filas_tablas']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_filas_tabla
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),		
	);
	
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Guardar',
	);
	
	return $form;
}

function panel_configuracion_submit($form, &$form_state){
	
	
	
	$panel=variable_get('panel');
	
	foreach($form_state['values']['colores_panel'] as $key => $valor){
		$panel[$key]['rgb']=$valor['und'][0]['rgb'];
		$panel[$key]['opacity']=$valor['und'][0]['opacity'];
		if($valor['und'][0]['rgb']=='')
			$panel[$key]['opacity']='';
	}
	
	variable_set('panel',$panel);
	
	drupal_set_message('Se ha guardado la configuración');
}