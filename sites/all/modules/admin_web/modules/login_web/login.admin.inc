<?php

/**
 * Implements mymodule_thumb_upload theme callback.
 */
function theme_login_thumb_upload($variables) {

	$element = $variables['element'];

	if (isset($element['#file']->uri)) {
		$output = '<div id="edit-logo-ajax-wrapper"><div class="form-item form-type-managed-file form-item-logo"><span class="file">';
		$output .= '<img height="70px" src="' . image_style_url('thumbnail', $element['#file']->uri) . '" />';
		$output .= '</span><input  type="submit" value="Eliminar" id="edit-' . $element['#name'] . '-remove-button" name="' . $element['#name'] . '_remove_button" value="Remove" class="form-submit ajax-processed btnDelete" >';
		$output .= '<input  type="hidden" name="' . $element['#name'] . '[fid]" value="' . $element['#file']->fid . '"></div></div>';
		return $output;
	}
}

function login_configuracion($form, &$form_state){

	drupal_add_library('color_field', 'bgrins-spectrum');
	
	drupal_add_css(drupal_get_path('module', 'login_web') .'/css/login_web_edit.css');
	
	if(isset ($_POST['borrarFile'])){
		$file=file_load($_POST['borrarFile']);
		file_delete($file);
	}
	
	
	$login=variable_get('login_web');
	
	$fondo='';
	$logo='';
	if($login['fondo']>0)
		$fondo= $login['fondo'];
	
	if($login['logo']>0){
		$logo=$login['logo'];
	}	
		
	$color_titulo=$login['color_titulo'];
	$color_textos=$login['color_textos'];
	$color_caja=$login['color_fondo_caja'];

	$form['login_logo'] = array(
		'#type' => 'managed_file',
		'#title' => 'Logo',
		'#description' => t('Extensiones permitidas: gif png jpg jpeg'),
		'#upload_location' => 'public://login/',
		'#default_value' =>isset ($login['logo']) ? $login['logo'] : '' ,
		'#theme' => 'login_thumb_upload',
		'#upload_validators' => array(
			'file_validate_extensions' => array('gif png jpg jpeg'),
		),
	);


	$form['login_fondo'] = array(
		'#type' => 'managed_file',
		'#title' => 'Imagen de fondo',
		'#description' => t('Extensiones permitidas: gif png jpg jpeg'),
		'#upload_location' => 'public://login/',
		'#default_value' => isset ($login['fondo']) ? $login['fondo'] : '' ,
		'#theme' => 'login_thumb_upload',
		'#upload_validators' => array(
			'file_validate_extensions' => array('gif png jpg jpeg'),
		),
	);

	$form['colores']=array(
		'#type' => 'fieldset',
		'#title' => 'Colores',
	);
	
	$field_color_titulo=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Color titulo',
			'#type' => 'textfield',
			'#default_value' => isset($login['color_titulo']['rgb']) ? $login['color_titulo']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($login['color_titulo']['opacity']) ? $login['color_titulo']['opacity'] : '',
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
	
	$form['colores']['color_titulo']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_titulo
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),	
		
	);
	
	
	$field_color_textos=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Color textos caja',
			'#type' => 'textfield',
			'#default_value' => isset($login['color_textos']['rgb']) ? $login['color_textos']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($login['color_textos']['opacity']) ? $login['color_textos']['opacity'] : '',
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
	
	$form['colores']['color_textos']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_textos
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),
		
	);
	
	
	$field_color_fondo=array(
		'#type' => 'color_field_spectrum_widget',
		'#field_settings' => array(
			'opacity' => 1
		),
		'rgb' => array(
			'#title' => 'Color fondo caja',
			'#type' => 'textfield',
			'#default_value' => isset($login['color_fondo']['rgb']) ? $login['color_fondo']['rgb'] : '',
		),
		'opacity' => array(
			'#type' => 'textfield',
			'#default_value' => isset($login['color_fondo']['opacity']) ? $login['color_fondo']['opacity'] : '',
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
	
	$form['colores']['color_fondo_caja']=array(		
		'#type' => 'container',
		'#tree' => true,
		'und' => array(
			0 => $field_color_fondo
		),
		'#attributes' => array(
			'class' => array('field-color'),
		),
		
	);

	

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Guardar',
		'#submit' => array('login_configuracion_submit'),
	);

	return $form;

}

function login_configuracion_submit($form, &$form_state){
	
	
	
	$login=variable_get('login_web');

	
	if(isset($form_state['values']['login_logo']) && $form_state['values']['login_logo']!==""){
		updateFiles($login['logo'],$form_state['values']['login_logo'],'logo','login_web');
		$login['logo']=$form_state['values']['login_logo'];
	}
	
	if(isset($form_state['values']['login_fondo']) && $form_state['values']['login_fondo']!==""){
		
		
		updateFiles($login['fondo'],$form_state['values']['login_fondo'],'fondo','login_web');
		
		$login['fondo']=$form_state['values']['login_fondo'];
	}
	
	if(isset($form_state['values']['color_titulo'])){
		$login['color_titulo']['rgb']=$form_state['values']['color_titulo']['und'][0]['rgb'];
		$login['color_titulo']['opacity']=$form_state['values']['color_titulo']['und'][0]['opacity'];
		if($form_state['values']['color_titulo']['und'][0]['rgb']=='')
			$login['color_titulo']['opacity']='';
	}
	
	if(isset($form_state['values']['color_textos'])){
		
		$login['color_textos']['rgb']=$form_state['values']['color_textos']['und'][0]['rgb'];
		$login['color_textos']['opacity']=$form_state['values']['color_textos']['und'][0]['opacity'];
		if($form_state['values']['color_textos']['und'][0]['rgb']=='')
			$login['color_textos']['opacity']='';
	}
	
	if(isset($form_state['values']['color_fondo_caja'])){
		
		$login['color_fondo']['rgb']=$form_state['values']['color_fondo_caja']['und'][0]['rgb'];
		$login['color_fondo']['opacity']=$form_state['values']['color_fondo_caja']['und'][0]['opacity'];
		if($form_state['values']['color_fondo_caja']['und'][0]['rgb']=='')
			$login['color_fondo']['opacity']='';
	}
	
	
	
	variable_set('login_web',$login);
	
	
	drupal_set_message('Se ha guardado la configuración del login');
}