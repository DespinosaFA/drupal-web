<?php

function email_configuracion($form, &$form_state){

	$form['#tree'] = TRUE;
	

	$form['mail']=array(
		'#type' => 'select',
		'#title' => 'Tipo de email',
		'#options' => array(
			'_none' => '--Selecciona--',
			'register_sin' => 'Registro sin aprobación',
			'register_con' => 'Registro con aprobación',
			'activate' => 'Cuenta activada',
			'password' => 'Recuperar clave',
		),
		'#ajax' => array(
			'event' => 'change',
			'callback' => 'ajax_emails_change',
			'wrapper' => 'emails-fieldset-wrapper',
			'method' => 'replace',
		),
	);
	
	$form['emails_fieldset'] = array(
		'#type' => 'fieldset',
		'#prefix' => '<div id="emails-fieldset-wrapper">',
		'#suffix' => '</div>',
	);
	
	if(isset ($form_state['values']['mail']) && $form_state['values']['mail']!='_none'){
		
		$email=getMailConfiguration($form_state['values']['mail']);
		
		$form['emails_fieldset'][$form_state['values']['mail']]['subject'] = array(
			'#type' => 'textfield',
			'#title' => 'Asunto',
			'#default_value' => $email['subject'],
		);
		
		$form['emails_fieldset'][$form_state['values']['mail']]['body'] = array(
			'#type' => 'text_format',
			'#title' => 'Body',
			'#default_value' => $email['body'],
			'#format'=> 'ckeditor',
			'#description' => 'Los valores entre corchetes son patrones de reeemplazo. 
							<br/>	Estan disponibles:
								<ul>
									<li>[site:name] => Nombre de la web</li>
									<li>[site:mail] => Email de la web</li>
									<li>[site:login-url] => Url de la web</li>
									<li>[user:name] => Nombre del usuario</li>
									<li>[user:mail] => Email del usuario</li>
									<li>[user:one-time-login-url] => Enlace de un único inicio de sesión estableciendo la clave</li>
								</ul>
							',
		);
		
		$form['emails_fieldset'][$form_state['values']['mail']]['variable_subject'] = array(
			'#type' => 'hidden',
			'#default_value' => $email['variable_subject'],
		);
		
		$form['emails_fieldset'][$form_state['values']['mail']]['variable_body'] = array(
			'#type' => 'hidden',
			'#default_value' => $email['variable_body'],
		);
		
		$form['emails_fieldset'][$form_state['values']['mail']]['submit'] = array(
			'#type' => 'submit',
			'#value' => 'Guardar',
		);
	}	

	return $form;

}

function ajax_emails_change($form, &$form_state) {	
	return $form['emails_fieldset'];
}

function email_configuracion_submit($form, &$form_state){
	
	$tipo=$form_state['values']['mail'];
	variable_set($form_state['values']['emails_fieldset'][$tipo]['variable_subject'],$form_state['values']['emails_fieldset'][$tipo]['subject']);
	variable_set($form_state['values']['emails_fieldset'][$tipo]['variable_body'],$form_state['values']['emails_fieldset'][$tipo]['body']['value']);	
	drupal_set_message('Se han guardado la configuración del email');
}

function getMailConfiguration($mail){
	$configuracion=array();
	switch ($mail) {
	    case "register_sin":
	        $configuracion['subject']=variable_get('user_mail_register_no_approval_required_subject');
	        $configuracion['body']=variable_get('user_mail_register_no_approval_required_body');
	        $configuracion['variable_subject']='user_mail_register_no_approval_required_subject';
	        $configuracion['variable_body']='user_mail_register_no_approval_required_body';
	        break;
	    case "register_con":
	        $configuracion['subject']=variable_get('user_mail_register_pending_approval_subject');
	        $configuracion['body']=variable_get('user_mail_register_pending_approval_body');
	        $configuracion['variable_subject']='user_mail_register_pending_approval_subject';
	        $configuracion['variable_body']='user_mail_register_pending_approval_body';
	        break;
	    case "activate":
	        $configuracion['subject']=variable_get('user_mail_status_activated_subject');
	        $configuracion['body']=variable_get('user_mail_status_activated_body');
	        $configuracion['variable_subject']='user_mail_status_activated_subject';
	        $configuracion['variable_body']='user_mail_status_activated_body';
	        break;
	    case "password":
	        $configuracion['subject']=variable_get('user_mail_password_reset_subject');
	        $configuracion['body']=variable_get('user_mail_password_reset_body');
	        $configuracion['variable_subject']='user_mail_password_reset_subject';
	        $configuracion['variable_body']='user_mail_password_reset_body';
	        break;
	}
	return $configuracion;
}