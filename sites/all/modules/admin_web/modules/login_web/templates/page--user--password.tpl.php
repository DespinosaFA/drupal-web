<div class="contenedor">
	<div class="logo">
		<a href="/"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
	</div>
    <p class="title"><?php print $title; ?></p>

    <?php print $messages; ?>

    <div class="box">
	    <?php print render($page['content']); ?>
	     <div class="enlaces">
		 <?php print l(t('Login'), 'user/login'); ?>
                 <?php
                    $regis=variable_get('user_register');
                    if($regis==1){
                       print l(t('Register a new account'), 'user/register');
                     }
                     ?>
			<a href="<?php print url('<front>'); ?>"  class="volver_web">&larr; Volver a <?php print $site_name; ?></a>
    	</div>
	</div>
</div>

