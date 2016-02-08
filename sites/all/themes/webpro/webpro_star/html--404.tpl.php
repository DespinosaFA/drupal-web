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
	<link rel="shortcut icon" href="<?php print theme_get_setting('favicon');  ?>" type="image/png" />
  <title>404</title>
  <link href='/sites/all/themes/webpro/webpro_star/css/404.css' rel='stylesheet' type='text/css'>
</head>

<body>
<div class="pag404">
  <div class="izq"><img src="/sites/all/modules/admin_web/images/imagen-404.jpg" alt="Imagen de página no encontrada" /></div>
  <div class="der"> <br>
    <img src="<?php print theme_get_setting('logo');  ?>" alt="Logo Empresa" /> <br>
    <img src="/sites/all/modules/admin_web/images/error-404.jpg" alt="Logo Empresa" />
    <p><span>PÁGINA NO ENCONTRADA</span></p>
    <p>Ups, no hemos podido encontrar la página.<br>
      Pero tranquilo, seguro que lo solucionamos pronto...</p>
    <br>
    <a href="/" target="_parent" title="Volver a web" >Haz click aquí para volver a inicio</a> </div>
</div>

<?php
    $blockObject = block_load('webform', 'client-block-6');
    $block = _block_get_renderable_array(_block_render_blocks(array($blockObject)));
    $output = drupal_render($block);
    print $output;
 ?>

</body>
</html>
