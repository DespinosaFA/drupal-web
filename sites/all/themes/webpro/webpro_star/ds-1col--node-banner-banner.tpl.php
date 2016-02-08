<?php
$url_imagen='/sites/default/files/default_images/banner_drupal_portales_aplicaciones_web.png';

if(isset ($field_imagen['und'][0]['uri'])){
	$url_imagen=file_create_url($field_imagen['und'][0]['uri']);
}
?>
<div class="banners" style="background-image: url(<?php print $url_imagen; ?>)"><?php print $ds_content; ?></div>
