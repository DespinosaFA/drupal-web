<?php
	
function blog_configuracion(){
	$form=array();
	
	$form['blog_fieldset'] = array(
		'#type' => 'fieldset',
		'#prefix' => '<div id="blog-fieldset-wrapper">',
		'#suffix' => '</div>',
	);			
	
	
	$form['blog_fieldset']['estado']= array(
		'#type' => 'checkbox',
		'#default_value' => getStatusBlog(),
		'#title' => 'Activar/desactivar blog',
	);
	
	$form['blog_fieldset']['pattern']= array(
		'#type' => 'textfield',
		'#default_value' => getPatternBlog(),
		'#title' => 'Raiz',
		'#description' => 'Especificar la raíz de las urls del blog.<br/> Ej.: blog, noticias'
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Guardar',
	);
	
	return $form;
} 


/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function blog_configuracion_submit($form, &$form_state) {
	$patron_old=getPatternBlog();
	$estado=getStatusBlog();
	if($patron_old!=$form_state['values']['pattern']){
		//nodos		
		$patron=$form_state['values']['pattern'].'/[node:field-categoria-blog]/[node:title]';
		variable_set('pathauto_node_blog_pattern',$patron);
		
		//categorias
		$patron=$form_state['values']['pattern'].'/[term:name]';
		variable_set('pathauto_taxonomy_term_categoria_blog_pattern',$patron);
		
		//vista
		$sql= db_select('views_display','v');		
		$sql->fields('v',array('id','display_options'))
		->condition('display_plugin','page','=')
		->condition('vid',1,'=');					 
		$resul = $sql->execute();	    
		while( $fil= $resul->fetchAssoc() ) {
			$configuracion=unserialize($fil['display_options']);			
			if($fil['id']=='blog'){
				$configuracion['path']=$form_state['values']['pattern'];				
			}
			$configuracion['menu']['title']=ucwords ($form_state['values']['pattern']);
			$display_options=serialize ($configuracion);
			$num_updated = db_update('views_display')
			->fields(array(
			'display_options' => $display_options,
			'display_title' => ucwords ($form_state['values']['pattern'])
			))
			->condition('vid', 1, '=')
			->condition('id', $fil['id'], '=')
			->execute();
		}
		
		updateAlias($form_state['values']['pattern']);				
		
	}
	
	if($estado!=$form_state['values']['estado']){
		
		$estado_view=false;
		$estado_type=0;
		if($form_state['values']['estado']==0){
			$estado_view=true;
			$estado_type=1;
		}		
		
		
		$num_updated = db_update('node_type')
		->fields(array(
		'disabled' => $estado_type,
		))
		->condition('type', 'blog', '=')
		->execute();		
		
		
		$status = variable_get('views_defaults', array());
		$status['blog'] = $estado_view;
		variable_set('views_defaults', $status);
		
		$sql= db_select('node','n');		
		$sql->fields('n',array('nid'));
		$sql->condition('type','blog','=');					 
		$resul = $sql->execute();	    
		while( $fil= $resul->fetchAssoc() ) {
			$nodo=node_load($fil['nid']);
			$nodo->status=$form_state['values']['estado'];
			node_save($nodo);
		}
		
		//Enlace crear entrada
		$link=menu_link_load(961);
		$link['hidden']=$estado_type;
		menu_link_save($link);	
		
		$link=menu_link_load(938);
		$link['hidden']=$estado_type;
		menu_link_save($link);			
			
	}
	
	drupal_flush_all_caches();	
	
	drupal_set_message('Se ha guardado la configuración del blog');
}

function getPatternBlog(){
	$patron=variable_get('pathauto_node_blog_pattern');
	$aux=explode("/",$patron);
	
	return $aux[0];
}

function getStatusBlog(){
	$estado=1;
	$sql= db_select('node_type','n');		
	$sql->fields('n',array('disabled'))
	->condition('type','blog','=');					 
	$resul = $sql->execute();	    
	if( $fil= $resul->fetchAssoc() ) {
		if($fil['disabled']==1){
			$estado=0;
		}
	}
	
	return $estado;
}

function updateAlias($pattern){
	
	
	
	$sql= db_select('taxonomy_term_data','t');		
	$sql->fields('t',array('tid'))
	->condition('vid',2,'=');					 
	$resul = $sql->execute();	    
	while( $fil= $resul->fetchAssoc() ) {
		
		db_delete('url_alias')
		->condition('source', 'taxonomy/term/'.$fil['tid'], 'LIKE')
		->execute();
		
		$term=taxonomy_term_load($fil['tid']);
		pathauto_taxonomy_term_update_alias($term, 'bulkupdate');	
		
	}
	
	$sql= db_select('node','n');		
	$sql->fields('n',array('nid','type'));
	$sql->condition('type','blog','=');					 
	$resul = $sql->execute();	    
	while( $fil= $resul->fetchAssoc() ) {
		
		db_delete('url_alias')
		->condition('source', 'node/'.$fil['nid'], 'LIKE')
		->execute();
		
		$nodo=node_load($fil['nid']);
		pathauto_node_update_alias($nodo, 'bulkupdate');			
	}
		
}