<table width="100%" border="0" align="center" cellpadding="50">
    <tr>
        <td bgcolor="#E9E9E9">
            <table  border="0" align="center" cellpadding="15" cellspacing="0" style="font-family: 'Lucida Grande', 'Lucida Sans Unicode', 'Lucida Sans', 'DejaVu Sans', Verdana, sans-serif; color:gray;width: 500px;">
				<tr>
					<td align="center" valign="middle" bgcolor="#FFFFFF"><img src="<?php print theme_get_setting('logo', 'webpro_star'); ?>" style="text-align:center;"></td>
    			</tr>
    			<tr>
	    			<td valign="middle" bgcolor="#FFFFFF"><?php echo $body; ?></td>
    			</tr>
    			<tr>
    			    <td align="center" valign="middle" bgcolor="#FFFFFF">
				        <?php
					        $redes=variable_get('admin_web_redes');
							
							if(!empty($redes)){
								foreach($redes as $red){
									if($red['estado']==1){
										$icono=file_load($red['logo']);
										$url_icono=file_create_url($icono->uri);
										print '<a href="'.$red['url'].'"><img width="40" src="'.$url_icono.'" /></a>';
									}
								}
							}
							?>
				    </td>
    			</tr>
			</table>
        </td>
	</tr>
</table>
