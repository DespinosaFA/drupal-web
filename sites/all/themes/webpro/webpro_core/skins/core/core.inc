<?php

/**
 * Implements hook_skinr_group_PLUGIN_info().
 */
function webpro_core_skinr_group_core_info() {
  $groups['menus'] = array(
    'title' => t('Menus'),
    'description' => t('Menu and navigation styles.'),
  );
  $groups['webpro_layout'] = array(
    'title' => t('webpro Grid Settings'),
    'description' => t('Align an element to the grid.'),
    'weight' => -15,
  );  

  return $groups;
}

/**
 * Implements hook_skinr_skin_PLUGIN_info().
 */
function webpro_core_skinr_skin_core_info() {

  $skins = array();
  
  $skins['webpro_skins_block_positioning'] = array(
    'title' => t('Block position'),
    'type' => 'select',
    'description' => t('Change the position of this block (default is to float to the left)'),
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'webpro-right' => array(
        'title' => 'Float block to the right',
        'class' => array('webpro-right'),
      ),
      'webpro-center' => array(
        'title' => 'Position block in the center',
        'class' => array('webpro-center'),
      ),
      'webpro-clear' => array(
        'title' => 'Clear floats (block drops to a new line)',
        'class' => array('webpro-clear'),
      ),      
    ),
  );
  
  $skins['webpro_skins_content_alignment'] = array(
    'title' => t('Content alignment'),
    'description' => t('Default is left aligned content'),
    'type' => 'select',
    'group' => 'layout',
    'default status' => TRUE,
    'options' => array(
      'webpro-right' => array(
        'title' => 'Center align content within its container',
        'class' => array('webpro-center-content'),
      ),
      'webpro-center' => array(
        'title' => 'Right align content within its container',
        'class' => array('webpro-right-content'),
      ),   
    ),
  );  
  
  $skins['webpro_skins_general_styles'] = array(
    'title' => t('General styles'),
    // 'description' => t('These are some generally useful options for blocks'),
    'theme hooks' => array('block'),
    'type' => 'checkboxes',
    'group' => 'general',
    'default status' => TRUE,
    'options' => array(
      'webpro-callout' => array(
        'title' => t('Text: large, bold callout style'),
        'class' => array('webpro-callout'),
      ),
      'webpro-bold-links' => array(
        'title' => t('Links: bold all links'),
        'class' => array('webpro-bold-links'),
      ),
      'webpro-padding' => array(
        'title' => 'Padding: add 30px extra padding inside block',
        'class' => array('webpro-padding'),
      ),
      'webpro-border' => array(
        'title' => 'Border: add 1px border and 10px padding',
        'class' => array('webpro-border'),
      ),
    ),
  );  
  
  $skins['webpro_equal_heights'] = array(
    'title' => t('Equal heights'),
    'description' => t('Make blocks in a region the same height'),
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),
    'type' => 'checkboxes',
    'group' => 'layout',
    'default status' => TRUE,
    'attached' => array(
       'js' => array('js/jquery.equalheights.js'), 
    ),
    'options' => array(
      'equal-heights' => array(
        'title' => 'Equal heights: equalize the heights of blocks with this style in the same region',
        'class' => array('equal-heights'),
      ),
    ),
  );    
  
  $skins['webpro_multicol'] = array(
    'title' => t('List columns'),
    'type' => 'select',
    'description' => t('Put items in lists (menus, list views, etc.) in multiple columns'),    
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel', 'views_view'),    
    'group' => 'general',
    'default status' => TRUE,
    'options' => array(
      'webpro-2-col-list' => array(
        'title' => '2-column list/menu (50%/50%)',
        'class' => array('webpro-2-col-list', 'clearfix'),
      ),
      'webpro-3-col-list' => array(
        'title' => '3-column list/menu (33%/33%/33%)',
        'class' => array('webpro-3-col-list', 'clearfix'),      
      )
    ),
  );   
  
  $skins['webpro_menu'] = array(
    'title' => t('Menu Layout'),
    'type' => 'select',
    'description' => t('Different layouts and alignment options for your menus'),    
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),    
    'group' => 'menus',
    'default status' => TRUE,
    'options' => array(
      'webpro-inline-menu' => array(
        'title' => 'Single line menu with separators',
        'class' => array('webpro-inline-menu'),
      ),
      'webpro-multicol-menu' => array(
        'title' => t('Multi-column menu with bold headers (set menu items to Expanded)'),
        'class' => array('webpro-multicol-menu', 'clearfix')
      )
    ),
  );  
  
  $skins['webpro_list_styles'] = array(
    'title' => t('List/menu styles'),
    'type' => 'checkboxes',
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel', 'views_view'),    
    'group' => 'menus',
    'default status' => TRUE,
    'options' => array(
      'webpro-list-bottom-border' => array(
        'title' => t('Bottom border (no bullets)'),
        'class' => array('webpro-list-bottom-border'),
      ),
      'webpro-multicol-menu' => array(
        'title' => t('Extra vertical spacing (no bullets)'),
        'class' => array('webpro-list-vertical-spacing')
      )
    ),
  );  
    
  $skins['webpro_float_imagefield'] = array(
    'title' => t('Image floating styles'),
    'type' => 'select',
    'description' => t('These options will float ImageField images in content to the left or right and add margins'),
    'theme hooks' => array('block', 'node', 'views_view'),    
    'group' => 'layout',
    'default status' => TRUE,
    'options' => array(
      'webpro_float_imagefield_left' => array(
        'title' => t('Float ImageField left'),
        'class' => array('webpro-float-imagefield-left'),
      ),
      'webpro_float_imagefield_right' => array(
        'title' => t('Float ImageField right'),
        'class' => array('webpro-float-imagefield-right'),
      ),
    ),
  );   
  
  $skins['webpro_login'] = array(
    'title' => t('User login block styles'),
    'theme hooks' => array('block', 'panels_display', 'panels_pane', 'panels_panel'),
    'group' => 'box',
    'default status' => TRUE,
    'attached' => array(
       'js' => array('js/jquery.overlabel.js'), 
    ),
    'options' => array(
      'webpro_horizontal_login' => array(
        'title' => t('Horizontal: puts user login block on a single line with label overlays (good for Header Top region)'),
        'class' => array('webpro-horiz-login'),
      ),
    ),
  );
  
  // @todo: detect current grid, and add column settings accordingly.
  $skins['webpro_skins_grid16_width'] = array(
    'title' => t('Width (16 column grid)'),
    'description' => t("Change the width of this block. Fluid grid % widths are relative to the parent region's width. Default widths: sidebar blocks default to the sidebar width; in other regions width is divided equally among all blocks."),    
    'type' => 'select',
    'group' => 'webpro_layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _webpro_skins_grid_options(16, 960),   
  );  
  
  $skins['webpro_skins_grid12_width'] = array(
    'title' => t('Width (12 column grid)'),
    'description' => t("Change the width of this block. Fluid grid % widths are relative to the parent region's width. Default widths: sidebar blocks default to the sidebar width; in other regions width is divided equally among all blocks."),
    'type' => 'select',
    'group' => 'webpro_layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _webpro_skins_grid_options(12, 960),   
  );     
  
  return $skins;
}

/**
 * Generates skinr options based on webpro grid parameters.
 * Assists in hook_skinr_skin_PLUGIN_info() implementation.
 * @return array
 */
function _webpro_skins_grid_options($units, $width) {
  $options = array();
  $unit_width = floor($width / $units);
  for ($i = 1; $i <= $units; $i++) {
    $plural = ($i == 1) ? '' : 's';
    $this_width = $i * $unit_width;
    $this_percentage = round($i * (100 / $units), 2);
    $options["grid{$units}-{$i}"] = array(
      'title' => "$i unit{$plural} wide ({$this_width}px/{$this_percentage}%)",
      'class' => "grid{$units}-{$i}"
    );
  }
  return $options;
}
