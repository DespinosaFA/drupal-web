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
  <title>403</title>
  
  <link href='/sites/all/themes/webpro/webpro_star/css/403.css' rel='stylesheet' type='text/css'>
</head>

<body>

<div class="pag403">
      <img src="<?php print theme_get_setting('logo');  ?>" alt="Logo Empresa" class="logo" /> <br>
  <img src="/sites/all/modules/admin_web/images/imagen-403.jpg" alt="Imagen de página privada" class="grafico" />
    <p><span>PÁGINA PRIVADA</span></p>
    <p class="mensaje">Lo sentimos, no tiene permiso para acceder a esta página.  <br><br>

Si lo desea, puede ponerse en contacto con el administrador del sitio web
 para obtener más información sobre este suceso y sus posibles soluciones...</p>
    <br>
    <a href="/" target="_parent" title="Volver a web" >Haz click aquí para volver a inicio</a>
</div>

</body>
</html>
