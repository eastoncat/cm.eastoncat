(function ($) {
  $(function () {
    media_cc_chapters.addClickEvent('.chapter-trigger');
    $('a[href="#chapters"]').on('shown.bs.tab', function(){
      media_cc_chapters.addClickEvent('.chapter-trigger');
    })
//    $('.chapter-trigger').click(function (e) {
//      e.preventDefault();
//      media_cc_chapters.goToChapter($(this).data('cid'), $(this))
//    });
  });
})(jQuery);

media_cc_chapters = {
  addClickEvent: function(selector) {
    $ = jQuery;
    $(selector).off('click').on('click', function(e){
      e.preventDefault();
      var description = $(this).find('.chapter-description');
      media_cc_chapters.toggleDescription(description);
      media_cc_chapters.hideDescriptions(description);
      media_cc_chapters.goToChapter($(this).data('cid'), $(this));
    });
  },
  toggleDescription: function(elem) {
    $ = jQuery;
    if ($(elem).is(':visible')) {
      $(elem).hide();
    } else {
      $(elem).show();
    }
  },
  hideDescriptions: function(exlude_element) {
    $ = jQuery;
    $('.chapter-description').each(function() {
      if (!$(this).is($(exlude_element))) {
        $(this).hide();
      }
    });
  },
  goToChapter: function (cid, elem) {
    $ = jQuery;
    var fid = $(elem).data('fid');
    var iframe = $('#file-'+ fid).find('iframe.media-cloudcast-player');
    var orig = iframe.attr('src');
    var orig_parts = orig.split('?');
    var base_path = orig_parts[0];
    var query = orig_parts[1];
    var new_url, new_query;
    if(!this.getParameterByName(query, 'chapter'))
      new_query = this.removeQueryParameter(query, 'video') + '&chapter=' + cid;
    else {
      new_query = this.removeQueryParameter(query, 'video');
      new_query = this.removeQueryParameter(new_query, 'chapter') + "&chapter=" + cid;
    }
    if(!this.getParameterByName(query, 'autoplay')) {
      new_query += "&autoplay=true";
    } else {
      new_query = this.removeQueryParameter(new_query, 'autoplay') + "&autoplay=true";
    }
      new_url = base_path + "?" + new_query;
    iframe.attr('src', new_url);
  },
  getParameterByName: function (query, name) {
    name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
    var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
            results = regex.exec(query);
    return results == null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
  },
  removeQueryParameter: function (query, name) {
    var prefix = encodeURIComponent(name) + '=';
    var parts = query.split(/[&;]/g);

    for(var i = parts.length; i-- > 0; ) {
      if(parts[i].lastIndexOf(prefix, 0) !== -1) {
        parts.splice(i, 1);
      }
    }

    return parts.join('&');
  }
}