(function ($) {
  $(document).ready(function() {

    //In D7 you can no longer target multiple
    // $('select[multiple]').each(
    $('.views-exposed-widget .form-select').each( 
       function(selectIndex) {
        
        var $this = $(this);
        
        var name = $this.attr('name');
        var $parent = $this.parent();
        var $slider = $('<div></div');
        var value = 0;
        
        $this.find('option').each(
          
            function(optionIndex) {
            
              if ($(this).attr('selected') && value == 0) {
              
                value = optionIndex + 1;
              
              } // if
   
            } // function
          
          ); // $.each

        if (selectIndex == 0) {

          var $key = $('<div class="views-exposed-widget" style="margin-top:1.7em; line-height: 1.5em;"></div>');

          $key.prepend('<div class="skillscale">0 - none</div>');
          $this.find('option').each(
          
            function() {
            
              var optionValue = $(this).attr('value');
              options.push(optionValue);      
    
              $key.prepend('<div class="skillscale">' + $(this).attr('label') + '</div>');
   
            } // function
          
          ); // $.each
                 
          
             
          $this.parents('.views-exposed-widgets .views-exposed-widget:last').before($key);
          
          $url = Drupal.settings.basePath;
          //$url = window.location.href
          //$url = '/?q=crew_connect/find';
          $url = '/';
                    
          $this.parents('form').attr( 'action' , $url).submit(
          
            function() {
            
              $('.ui-slider').each(
              
                function() {
                
                  var $this = $(this);
                  var value = $this.slider('value');
                  
                  var $parent = $this.parent();
                  
                  $parent.append('<input type="hidden" name="q" value="crew-connect/find" />');
                    
                  if (value > 0) {
                    
                    while (value < 6) {
                      
                      $parent.append('<input type="hidden" name="' + $this.data('name') + '" value="' + options[value-1] + '" />');
                      value++;
                    
                    } // while
                  
                  } // if
                
                } // function
              
              );
                          
            } // function
          
          ) // $.submit

        } // if
        
        $this.remove();
        
        $parent.css({padding:'1em'});
        
        $slider.appendTo($parent).data('name',name).slider({'min':0,'max':5,'value':value,'orientation':'vertical'});

      } // function
    
    ); // $.each
  
  });
})(jQuery);



var options = [];
