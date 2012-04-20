<?php

	$RootDirectory = "/cgi-bin/mbmccorm/348/";

	$con = oci_connect("mbmccorm", "veStU554UChA", "claros.cs.purdue.edu:1524/strep");
	if (!$con)
	{
		$e = oci_error();
    	trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
	}
?>