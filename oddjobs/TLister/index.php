<?php
/* ************************************************** *
 * TLister - Index.php                        
 * 
 * TLister is a nice little php library that prints 
 * out a directory's .mp3 and .wav files, much like 
 * what a typical apache directory listing would look 
 * like.
 *
 * It also uses the javascript libaries:
 *
 * - Soundmanager
 * - JQuery 
 * 
 * to build a clean UI that allows the visitor either 
 * play the songs in their browser, or download them 
 * to their local machine.
 
 * (c) 2013 Danny Hadley under the MIT license *
 * ************************************************** */


// Save the current working directory
$cwd = getcwd( );

$host = $_SERVER['HTTP_HOST'];
$ruri = $_SERVER['REQUEST_URI'];
$title = ucfirst( preg_replace( '/^\/(.+)\/$/', '$1', $ruri ) );


// Create a new directory handle
$dir = opendir( $cwd );

$file   = "";
$tracks = array( );
$id     = 0;
while ( false !== ( $file = readdir ( $dir ) ) ) { 
    if ( is_dir( $cwd . "/" . $file ) || preg_match('/^.+\.(mp3|wav|MP3|WAV)$/', $file) !== 1 ) { continue; }
    $tracks[] = array( 
        "name"     => preg_replace( '/^(.+)\.(mp3|wav|MP3|WAV)$/', '$1', $file ),
        "location" => "http://" . $host . $ruri . $file,
        "type"     => strtolower( preg_replace( '/^(.+)\.(mp3|wav|MP3|WAV)$/', '$2', $file ) ),
        "changed"  => date( "M d", filemtime ( $file ) ),
        "original" => $file,
        "id"       => ++$id
    );
}

closedir($dir);

?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Track List | <?php echo $title; ?></title>
    
    <link href='http://fonts.googleapis.com/css?family=Raleway:400,200,500,600' rel='stylesheet' type='text/css'>
    <link rel="stylesheet" type="text/css" href="css/global.css">
    <link rel="stylesheet" type="text/css" href="css/main.css">
</head>
<body>
    <section class="pw middle">
        <h1>Tracks under <em><?php echo $title; ?></em></h1>
        <ul class="tracks">
        <?php foreach( $tracks as $track ) { ?> 
        <li>
<a class="play t" href="" title="" data-name="<?php echo $track['original']; ?>" data-id="<?php echo $track['id']; ?>"><span class="icon t"></span></a>
<a class="track cf" href="<?php echo $track['location']; ?>" data-name="<?php echo $track['name']; ?>" data-type="<?php echo $track['type']; ?>" data-original="<?php echo $track['original']; ?>">
    <span class="status t"></span>
    <span class="f changed"><?php echo $track['changed']; ?></span> 
    <span class="f t name"><?php echo $track['name']; ?></span>
    <span class="f type">[<?php echo $track['type']; ?>]</span>
    <span class="f dl t">download</span>
</a>
        </li>
        <?php } ?>
        </ul>
    </section>
    
    <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
    <script type="text/javascript" src="js/soundmanager2-nodebug-jsmin.js"></script>
    <script type="text/javascript" src="js/main.min.js"></script>
</body>
</html>
