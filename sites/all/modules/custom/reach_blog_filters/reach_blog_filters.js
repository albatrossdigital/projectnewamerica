// $Id: reach_blog_filters

/**
 * Custom JS reach_blog_filters
 */

/* New D7 Wrapper --> */(function ($) {

Drupal.behaviors.reach_blog_filters = {
  attach: function(context, settings) { //new attach function
    
    //alert('hello');
    //$('.view-id-multi_content_blog .view-header ul.view-types li a').each(function() {
      
    //});
    var form = 'form#views-exposed-form-multi-content-blog-page-5';
    var view = '#block-system-main .view-id-multi_content_blog';
    
    if($(form).length && !$(view).hasClass('reach-blog-filter-processed')) {
      jQuery.fn.formClear = function () {
        var $input = this.find('input, select').not('.form-submit, :hidden');
        $input.each(function() {
          $(this).val('');
        });
      }
      jQuery.fn.formFilterFieldFill = function (fieldID, value) {
        if(this.length) {
          var $input = this.find('.form-item ' + fieldID);
          if($input.hasClass('form-text')) {
            $input.val(value);
          }
          else if($input.hasClass('form-select')) {
            $input.children().each(function() {
              if($(this).attr('value') == value) {
                $input.val(value);
              }
            });
          }
          return true;
        }
        else {
          return false;
        }
      }
      $('#block-reach-blog-filters-filter-links ul.view-types li a').not('.hard-link').each(function() {
        $(this).click(function() {
          //alert($(this).attr('content_type'));
          if(!$(form + ' div.ajax-progress').length) {
          
            if($(form).formFilterFieldFill('#edit-type', $(this).attr('content_type'))) {
              //addThrobber();
              $(this).parent().siblings().find('.current').removeClass('current');
              $(this).addClass('current');
              $(form).find('input.form-submit').click();
            }
          }
          
          return false;
        });//click
      });//each
      
      $(form).find('input.form-submit').click(function() {
         addThrobber();
      });
      
      function addThrobber() {
          $(view + ' > .view-content').prepend('<div class="ajax-loader reach-block-filter-loader"></div>');
          $(view + ' > .view-content .views-row').css({'-ms-filter' : 'progid:DXImageTransform.Microsoft.Alpha(Opacity=10)', 'filter' : 'progid:DXImageTransform.Microsoft.alpha(opacity=10)', 'opacity' : '0.1'});
      } 
    }
    /*if(!$('body').hasClass('reach-blog-filter-processed')) {
      var $jumpForm = $('#cl-reach-blog-filter-display-block-form');
      if($jumpForm.length) {
        $jumpForm.find('input.form-submit').hide();
        $jumpForm.find('select').change(function() {
          if($(this).children(":selected").val().length) {
            if($(form).length) {
              $(form).formClear();
              var date = $(this).children(":selected").val().split('/', 2);
              if($(form).formFilterFieldFill('#edit-date-filter-min-date', date[0]) && $(form).formFilterFieldFill('#edit-date-filter-max-date', date[1])) {
                //$(form).find('input.form-submit').click();
                $(form).submit();
                return false;
              }
            }
            else {
              $jumpForm.submit();
            }
          }
        });
      }
    }*/
    $('#block-system-main .view-id-multi_content_blog').addClass('reach-blog-filter-processed');
    
    
  }//attach
};//behaviors

/* New D7 Wrapper --> */ })(jQuery);
