<?php

function updateFiles($file_id_old,$file_id_new,$type,$module){
	//Actulizar imagenes formularios de configuración
	if($file_id_new!=$file_id_old){
		if(checkFile($file_id_old)){
			$file_old=file_load($file_id_old);
			if(isset ($file_old->uri)){
				file_usage_delete($file_old, $module,$type);
				file_delete($file_old);
			}
		}
		  	
		 if(checkFile($file_id_new)){ 
		 	$file_new=file_load($file_id_new);
			if(isset ($file_new->status)){
				$file_new->status=1;
				file_save($file_new);
				file_usage_add($file_new,$module, $type,0);
			}
		 }
		  		
	  }
}

function checkFile($file_id){
	$sql= db_select('file_managed','f');
	$sql->fields('f',array('filename'));
	$sql->condition('fid',$file_id,'=');
	$resul = $sql->execute();
	if( $fil = $resul->fetchAssoc() ){
		return true;
	}
	
	return false;
}

function checkLink($path){
	
	$sql= db_select('menu_links','l');		
	$sql->fields('l',array('mlid'))
	->condition('link_path',$path,'=')
	->condition('menu_name','menu-administracion','=');					 
	$resul = $sql->execute();	    
	if( $fil= $resul->fetchAssoc() ) {
		return true;
	}
	
	return false;
		
}

function update_links_menu(&$form, &$form_state){
	
	
	foreach($form_state['input'] as $rid => $perms){
		if(is_numeric($rid)){
			if(isset ($perms['administer reds settings'])){
				$item=menu_link_load(917);
				if(!in_array($rid, $item['visibility']['roles'])){
					
				}
			}
		}
	}
}
