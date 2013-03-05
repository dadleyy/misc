/* ******************************************* * 
 * Main.js                                     *
 * Scripting definitions for the TLister track *
 * DirectoryIndex file library.                *
 * (c) 2013 Danny Hadley under the MIT license *
 * ******************************************* */ 
(function ( SoundManEn, SM ) { 
    
    "use strict";
    
    var // local copy of SoundManager
        _SM = (SoundManEn) ? SM : false,
        // soundmager readyness
        _smReady = false,
        // soundmanager ready func
        _smLoad,
        // the trigger 
        _smTrigger,
        // the playing function 
        _smPlaying,
        // the current sound
        _smSound = false,
        
        // initialization function
        domReady,
        
        // the downloader 
        _dlframe,
        
        // click event handler 
        _onclick;
        
        
        
    _smPlaying = function ( ) { };
    
    _smTrigger = function ( evt ) {
        if ( !_smReady ) { return evt.preventDefault && evt.preventDefault(); }
        
        var link = this,
            name = ( link.dataset ) ? link.dataset.name : $(link).data("name"),
            id   = ( link.dataset ) ? link.dataset.id : $(link).data("id"),
            sid  = (_smSound !== false) && _smSound.id;
    
        if ( sid !== false ) {
            
            _SM.stopAll( );
                 
            _SM.destroySound( sid );
            
            $(link).parent().parent().find(".playin").removeClass("playin");
            
            _smSound = false;
            
            if ( id === sid ) {
                return evt.preventDefault && evt.preventDefault();
            }
    
        }
        
        $(link).parent().addClass( "playin" );
        _smSound = _SM.createSound({ id : id, url : name, autoPlay : true, whileplaying : _smPlaying });
    
        return evt.preventDefault && evt.preventDefault();
    };
    
    _smLoad = function ( ) { _smReady = true; };
        
    _onclick = function ( evt ) {
        var track = this,
            name  = ( track.dataset ) ? track.dataset.original : $(track).data("original");
        
        _dlframe
            .attr("src", "dl.php?t=" + name );
        
        return evt.preventDefault && evt.preventDefault(); 
    }; 
    
    domReady = function ( ) {
        _dlframe = $("<iframe>")
                        .attr("src","dl.php")
                        .css({"display":"none"});
        
        if ( _SM !== false ) {
            _SM.setup({ "url" : "swf/", "onready" : _smLoad });
        }
        
        $(document.body)
            .append( _dlframe )
            .on("click", "a.track", _onclick )
            .on("click", "a.play", _smTrigger );
    };
    
    $(document).ready( domReady );
    
})( !!soundManager, soundManager );