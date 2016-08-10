/* New D7 Wrapper --> */(function ($) {
Drupal.behaviors.pnaomega = {
  attach: function(context, settings) { //new attach function
    var $searchBlock = $('#zone-branding-wrapper #views-exposed-form-full-site-search-panel-pane-1').closest('.block-views');
      //$('#region-menu > .region-menu-inner').append($searchBlock);
      
    //$('#zone-branding-wrapper #views-exposed-form-search-api-node-search-list-panel-pane-1').closest('.block-views').addClass('pooper');
  
    // Define the queries you want to test for.. and what to do if they're TRUE 
    var queries = [ 
      { 
        context: 'full', 
        callback: function() { 
          $('#region-branding > .region-branding-inner').not(':has(.block-views)').append($searchBlock);
        } 
      },
      {
        context: 'mobile', 
        callback: function() { 
          $('#region-menu > .region-menu-inner').not(':has(.block-views)').append($searchBlock);
        } 
      }
    ]; 
    // Go! 
    MQ.init(queries);
    
    /**
     *  Mobile Menu
     */
    $('#block-superfish-1 h2.block-title').unbind();
    $('#block-superfish-1 h2.block-title').not('.clicked').bind('click', function() {
      var $container = $(this).parent();
      var height;
      if($container.hasClass('menu-open')) {
        height = 45;
      }
      else {
        height = 350;
      }
      $container.toggleClass('menu-open').addClass('opening');
      openMenu($container, $(this), height);
    });
    
    
    function openMenu($container, $button, height) {
      $button.toggleClass('clicked');
      $container.animate({
          height: height
        }, 500, function() {
          $button.toggleClass('clicked');
          $container.removeClass('opening');
      });
    }

    
     /**
     *  Mobile Search Menu
     */
    $searchBlock.find('h2.block-title').unbind();
    $searchBlock.find('h2.block-title').bind('click', function() {
      $('body').toggleClass('mobile-search-open');
    });
    
    
     /**
     *  Mobile Filter Menu
     */
    $('#block-views-exp-research-panel-pane-1 h2.block-title, #block-views-exp-bookmarks-panel-pane-1 h2.block-title').unbind();
    $('#block-views-exp-research-panel-pane-1 h2.block-title, #block-views-exp-bookmarks-panel-pane-1 h2.block-title').not('.clicked').bind('click', function() {
      $('body').toggleClass('mobile-research-filter-open');
    });
    
    
   /**
     *  Front page actions
     */
    
    if($('body.front').length || $('body.internal-front-page').length) {

      
      var height = 322;
      /**
       *  Equal height columns on front page
       */ 
      $('#mini-panel-external_home_page_latest .views-row .node, #mini-panel-internal_home_page_latest .views-row .node').each(function() {
        var bodyHeight = height - $(this).children('.field-name-title').outerHeight(true) - $(this).children('.field-name-date-with-author-or-source, .field-name-post-date').outerHeight(true);
        
        $body = $(this).children('.field-name-body');
        var lineHeight = parseInt($body.css('line-height'));
        $body.css({'height': (lineHeight * Math.floor(bodyHeight / lineHeight))});
      });
    }
    

    
    
    /*function openMenu($container, $button, height) {
      $button.toggleClass('clicked');
      $container.animate({
          height: height
        }, 500, function() {
          $button.toggleClass('clicked');
          $container.removeClass('opening');
      });
    }*/
    
  }//attach
};//behaviors

/* New D7 Wrapper --> */ })(jQuery);
