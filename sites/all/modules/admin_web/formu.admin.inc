<?php
	
function formularios_configuracion($form, &$form_state) {
	
	
	
	
	$sql= db_select('node','n');		
	$sql->fields('n',array('nid','title'))
	->condition('nid',6,'<>')
	->condition('type','webform','=');					 
	$resul = $sql->execute();	    
	while( $fil= $resul->fetchAssoc() ) {
		$form['form_fieldset_'.$fil['nid']] = array(
			'#type' => 'fieldset',
			'#title' => $fil['title']
		);
		
		$mail=getEmailWebform($fil['nid']);
		
		$form['form_fieldset_'.$fil['nid']]['mail'][$fil['nid']] = array(
			'#type' => 'textfield',
			'#title' => 'Dirección de correo',
			'#description' => 'Especificar la dirección a la que se debe enviar el formulario',
			'#default_value' => $mail
		);		
		
	}
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Guardar',
	);	
	
	return $form;
}

function formularios_configuracion_validate($form, &$form_state) {
	foreach($form_state['values'] as $nid => $mail){
		if(is_numeric($nid)){
			if(!valid_email_address(trim($form_state['values'][$nid]))){
				form_set_error($nid, t('You must enter a valid e-mail address.'));
			}
		}
	}
}

function formularios_configuracion_submit($form, &$form_state) {
	
	foreach($form_state['values'] as $nid => $mail){
		if(is_numeric($nid)){
			
			$num_updated = db_update('webform_emails')
			->fields(array(
			'email' => $form_state['values'][$nid],
			))
			->condition('nid', $nid, '=')
			->execute();
		}
	}
	drupal_set_message('Se ha guardado la configuración de los formularios');
}

function getEmailWebform($nid){
	$email="";
	$sql= db_select('webform_emails','e');		
	$sql->fields('e',array('email'))
	->condition('nid',$nid,'=');				 
	$resul = $sql->execute();	    
	if( $fil= $resul->fetchAssoc() ) {
		$email=$fil['email'];
	}
	
	return $email;	
}