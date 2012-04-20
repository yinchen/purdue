#! /p/php/bin/php
<?php

	$RootDirectory = "/cgi-bin/mbmccorm/348/";

	$con = oci_connect("mbmccorm@csora", "veStU554UChA", "claros.cs.purdue.edu:1524/strep");
	if (!$con)
	{
		// die("Could not connect: " . oci_error());

		$e = oci_error();
    	trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);

    	print_r($e);
	}
?>