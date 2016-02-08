<?php


/**
 * Implements _thumb_upload theme callback.
 */
function theme_redes_thumb_upload($variables) {

	$element = $variables['element'];
	
	if (isset($element['#file']->uri)) {
		$nombre=$element['#name'];
		$nombre=str_replace('[logo]', '_logo', $nombre);
		$nombre=str_replace('[', '_', $nombre);
		$nombre=str_replace(']', '', $nombre);
		$output = '<div id="edit-logo-ajax-wrapper"><div class="form-item form-type-managed-file form-item-logo"><span class="file">';
		$output .= '<img height="70px" src="' . image_style_url('thumbnail', $element['#file']->uri) . '" />';
		$output .= '</span><input  type="submit" value="Eliminar" id="edit-' . $nombre . '-remove-button" name="' . $nombre . '_remove_button" value="Remove" class="form-submit ajax-processed btnDelete" >';
		$output .= '<input  type="hidden" name="' . $element['#name'] . '[fid]" value="' . $element['#file']->fid . '"></div></div>';
		return $output;
	}
}

function redes_configuracion($form, &$form_state){

	$form['#tree'] = TRUE;
	$form['redes_fieldset'] = array(
		'#type' => 'fieldset',
		'#title' => 'Redes',
		'#prefix' => '<div id="redes-fieldset-wrapper">',
		'#suffix' => '</div>',
	);
	

	$redes=variable_get('admin_web_redes');
	
	
	if(!empty($redes) && empty($form_state['num_redes'])){		
		$form_state['num_redes']=count($redes);	
	}	
	
	if (empty($form_state['num_redes'])) {
		$form_state['num_redes'] = 1;
	}

	for ($i = 0; $i < $form_state['num_redes']; $i++) {
		
		$url_default='';
		$logo_default='';
		$activate_default=1;
		$red_default='';
		$description_icono=t('Extensiones permitidas: gif png jpg jpeg');
		
		if(!empty($redes)){
			if(isset ($redes[$i]['url']))
				$url_default=$redes[$i]['url'];
			if(isset ($redes[$i]['logo'])){
				$logo_default=$redes[$i]['logo'];
				$description_icono='';
			}				
			if(isset ($redes[$i]['estado']))
				$activate_default=$redes[$i]['estado'];
			if(isset ($redes[$i]['red']))
				$red_default=$redes[$i]['red'];
			
		}
		
		$form['redes_fieldset'][$i] = array(
			'#prefix' => '<div class="two-col">',
			'#suffix' => '</div>'
		);
		
		
		
		$form['redes_fieldset'][$i]['estado'] = array(
			'#type' => 'checkbox',
			'#default_value' => $activate_default,
			'#prefix' => '<div class="estado-red">',
			'#suffix' => '</div>'
		);
		
		
		$form['redes_fieldset'][$i]['red'] = array(
			'#type' => 'textfield',
			'#title' => 'Red',
			'#default_value' => $red_default,
			'#prefix' => '<div class="col">',
			'#suffix' => '</div>',
			'#required' => true,
		);
		
		
		$form['redes_fieldset'][$i]['url'] = array(
			'#type' => 'textfield',
			'#title' => 'Url',
			'#default_value' => $url_default,
			'#prefix' => '<div class="col">',
			'#suffix' => '</div>',
			'#required' => true,
		);

		$form['redes_fieldset'][$i]['logo'] = array(
			'#type' => 'managed_file',
			'#title' => 'Icono',
			'#description' => $description_icono,
			'#upload_location' => 'public://admin_web/redes',
			'#default_value' => $logo_default,
			'#theme' => 'redes_thumb_upload',
			'#upload_validators' => array(
				'file_validate_extensions' => array('gif png jpg jpeg'),
			),
			'#required' => true,
		);

		$form['redes_fieldset'][$i]['delete'] = array(
			'#type' => 'checkbox',
			'#title' => 'Eliminar red',
			'#description' => 'Si se marca se eliminará la red al guardar',
			'#prefix' => '<div class="delete-red">',
			'#suffix' => '</div>'
		);
		
		if($i<($form_state['num_redes']-1)){
			$form['redes_fieldset'][$i]['separator'] = array(
				'#markup' => '<hr/>',
			);
		}		
		

	}


	$form['redes_fieldset']['add'] = array(
		'#type' => 'submit',
		'#value' => 'Añadir otra',
		'#submit' => array('add_red_one'),
		'#ajax' => array(
			'callback' => 'add_red_callback',
			'wrapper' => 'redes-fieldset-wrapper',
		),
	);

	if ($form_state['num_redes'] > 1) {
		$form['redes_fieldset']['remove'] = array(
			'#type' => 'submit',
			'#value' => 'Eliminar',
			'#submit' => array('remove_red_one'),
			'#ajax' => array(
				'callback' => 'add_red_callback',
				'wrapper' => 'redes-fieldset-wrapper',
			),
			'#limit_validation_errors' => array(),
		);
	}
	
	
	
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Guardar',
	);

	return $form;

}

function add_red_callback($form, $form_state) {
	return $form['redes_fieldset'];
}

function add_red_one($form, &$form_state) {
	$form_state['num_redes']++;
	$form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove one" button.
 *
 * Decrements the max counter and causes a form rebuild.
 */
function remove_red_one($form, &$form_state) {
	
	if(isset ($form_state['values']['redes_fieldset'][$form_state['num_redes']-1]['logo']) && is_numeric($form_state['values']['redes_fieldset'][$form_state['num_redes']-1]['logo'])){
		$logo = file_load($form_state['values']['redes_fieldset'][$form_state['num_redes']-1]['logo']);
		file_usage_delete($logo,'admin_web', 'redes');
		file_delete($logo);
	}
	
	if ($form_state['num_redes'] > 1) {
		$form_state['num_redes']--;
	}
	$form_state['rebuild'] = TRUE;
}

/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function redes_configuracion_submit($form, &$form_state) {
	
	
	$redes=array();
	$redes_old=variable_get('admin_web_redes');
	if(isset ($form_state['values']['redes_fieldset'][0])){
		foreach($form_state['values']['redes_fieldset'] as $key => $valor){
			if(is_numeric($key)){
				
				if($valor['delete']!=1){
					$aux=array();
					$aux['url']=$valor['url'];
					$aux['red']=$valor['red'];
					$aux['logo']=$valor['logo'];
					$aux['estado']=$valor['estado'];
					$redes[]=$aux;
					if(isset($redes_old[$key]['logo']))
						$logo_old=$redes_old[$key]['logo'];
					else
						$logo_old=0;
					updateFiles($logo_old,$valor['logo'],'redes','admin_web');
				}else{
					if(is_numeric($valor['logo'])){
						$logo = file_load($valor['logo']);
						file_usage_delete($logo,'admin_web', 'redes');
						file_delete($logo);
					} 
				}
				
			}
			
		}
	}
	
	variable_set('admin_web_redes',$redes);
	drupal_set_message('Se ha guardado la configuración de las redes sociales');
}