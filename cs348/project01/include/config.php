<?php

	$RootDirectory = "/cgi-bin/mbmccorm/348/";

	$con = oci_connect("mbmccorm", "veStU554UChA", "csora");
	if (!$con)
	{
		$e = oci_error();
    	trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
	}
?>