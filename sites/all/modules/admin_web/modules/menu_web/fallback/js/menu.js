(function($) {
	Drupal.behaviors.menuFactoria = {
		attach: function() {

			var elemento="";

			$('#block-menu-factoria-menu #menu-ordenador ul li').click(function(){
				elemento=$(this).find("ul:first-child");
				elemento.css("display","block");
			})

			if(elemento!==""){
                            $('#page').click(function(){
				elemento.css("display","none");
				elemento="";
                            });
                        }



			var ancho = 570;
			var ventana=$( window ).width();
			ancho=parseFloat(ancho);

			if(ventana<ancho){
				$("#menu-ordenador").css("display","none");
				$("#menu-movil").css("display","block");
			}

			$(window).resize(function(){

				ventana=$( window ).width();
				if(ventana<ancho){
					$("#menu-ordenador").css("display","none");
					$("#menu-movil").css("display","block");
				}else{
					$("#menu-ordenador").css("display","block");
					$("#menu-movil").css("display","none");

				}



			});


            $("#menu-movil > p").click(function(){
	            $("#lista").slideToggle();
            });

            $("#menu-movil .sub").click(function(){
	            var id="#"+$(this).attr("data-id");
	            $(id).slideToggle();
            });

            $("#menu-movil .abrir").click(function(){
	            $(this).find(".nivel1").slideDown();
            });

            $(".abre").click(function(){
	            $(this).find("ul").slideToggle();
            });

            //AVISOS

            if($('#aviTicket').text()=="0"){
	           $('#aviTicket').addClass('avisocero');
            }

            if($('#aviHistorial').text()=="0"){
	           $('#aviHistorial').css("display","none");
            }

            if($('#aviMejoras').text()=="0"){
	           $('#aviMejoras').css("display","none");
            }

            if($('#aviConfiguracion').text()=="0"){
	           $('#aviConfiguracion').addClass('avisocero');
            }

            if($('#aviTicketMovil').text()=="0"){
	           $('#aviTicketMovil').addClass('avisoceroM');
            }

            if($('#aviHistorialMovil').text()=="0"){
	           $('#aviHistorialMovil').css("display","none");
            }

            if($('#aviMejorasMovil').text()=="0"){
	           $('#aviMejorasMovil').css("display","none");
            }

            if($('#aviConfiguracionMovil').text()=="0"){
	           $('#aviConfiguracionMovil').addClass('avisoceroM');
            }


		}
	};
})(jQuery);