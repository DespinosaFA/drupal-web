<div class="contenedor">
	<div class="logo">
		<a href="/"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
	</div>
    <p class="title"><?php print $title; ?></p>

    <?php print $messages; ?>
    
    <div class="box"><?php print render($page['content']); ?></div>
</div>



