$( document ).ready(function()
	{
  if(!$("#edit-field-om-theme-nid-nid :selected").val()){
	  $("#edit-field-om-genre-value").attr("disabled", "disabled");
	}
	
  $('#edit-field-om-theme-nid-nid').change(function(){
  
  var theme = $('#edit-field-om-theme-nid-nid :selected').text();
  var parent = false;
  
   if($("#edit-field-om-theme-nid-nid").val()){
      $("#edit-field-om-genre-value").removeAttr("disabled");
   }
    
  //console.log('changing Theme to ' + theme);

  $('#edit-field-om-genre-value option').each(function(){
    
    if($(this).text() != '- None -' && $(this).text().substring(0,1) != '-'){
        //console.log('PARENT CHANGE! this is not a sub item, set parent to ' + $(this).text());
        parent = $(this);
        
      }
    
    if(!parent){
      //console.log('checking main ' + $(this).text());
      if ($(this).text() != theme) {
        $(this).attr("disabled", "disabled");
        $(this).hide();
        //console.log('hiding - ' + $(this).text() + ' != ' + theme);
      } else {
        $(this).removeAttr("disabled");
        $(this).show();
        
        //console.log('showing - ' + $(this).text() + ' = ' + theme);
      }

    } else {
    //console.log('checking sub ' + $(this).text());
    if (parent.text() != theme) {
    //if ($(this).val() != theme && $parent.val() != theme) {
      $(this).attr("disabled", "disabled");
      $(this).hide();
      //console.log('hiding - ' + $(this).text() + ' because ' + parent.text() + ' != ' + theme);
    }
    else {
      $(this).removeAttr("disabled");
      $(this).show();
      //console.log('showing - ' + $(this).text() + ' because ' + parent.text() + ' = ' + theme);
    }
    }

   

    }); // $.each

  }); // $.change

}) // $.ready