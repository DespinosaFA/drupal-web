<?php
$url_enlace=false;
if(isset ($field_enlace['und'][0]['url'])){
	$url_enlace=file_create_url($field_enlace['und'][0]['url']);
}
$url_imagen='/sites/default/files/default_images/banner_drupal_portales_aplicaciones_web.png';
if(isset ($field_imagen['und'][0]['uri'])){
	$url_imagen=file_create_url($field_imagen['und'][0]['uri']);
}

?>
<?php if($url_enlace) print '<a href="'.$url_enlace.'">'; ?>
<div class="banners" style="background-image: url(<?php print $url_imagen; ?>)"><?php print $ds_content; ?></div>
<?php if($url_enlace) print '</a>'; ?>
