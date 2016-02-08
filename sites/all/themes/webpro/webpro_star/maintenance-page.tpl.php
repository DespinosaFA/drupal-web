<?php
/**
 * @file
 * Fusion theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in page.tpl.php. Some may be left
 * blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link href='/sites/all/themes/webpro/webpro_star/css/mantenimiento.css' rel='stylesheet' type='text/css'>
<?php
$login=variable_get('login_web');
	
$fondo=false;;
if($login['fondo']>0){
	$file_fondo= file_load($login['fondo']);
	$fondo=file_create_url($file_fondo->uri);
}

if($fondo):
	
?>
<script type="text/javascript" src="/misc/jquery.js"></script>
<script type="text/javascript" src="/sites/all/modules/admin_web/modules/login_web/js/jquery.backstretch.min.js"></script>
<script>
$(document).ready(function(){
    $.backstretch('<?php print $fondo; ?>');
}); 
</script>
<?php endif; ?>

</head>

<body>
<div class="imagen">
 <img src="<?php print theme_get_setting('logo');  ?>" alt="<?php print t('Home'); ?>" />
</div>
 <div class="imgMantenimiento"></div>
 <img class="mantenimiento" src="/sites/all/themes/webpro/webpro_star/css/imagenes/enconstruccion.png" alt="Pagina en mantenimiento" />
 
 
</body>
</html>
