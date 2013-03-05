<?php



// Make sure we have a param
if( !isset( $_GET["t"] ) ) { echo ""; return false; }

// Save the track name
$track = $_GET['t'];

// Make sure the param is a file
if( !is_file( $track ) ) { echo ""; return false; }

// Set header information
header('Pragma: public'); 
header('Expires: 0');
header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
header('Cache-Control: private', false);
header('Content-Type: application/force-download');
header('Content-Disposition: attachment; filename="' . basename( $track ) . '"');
header('Content-Transfer-Encoding: binary');
header('Content-Length: ' . filesize( $track ) );  

// Open up the file and dump it out
readfile($track);

?>