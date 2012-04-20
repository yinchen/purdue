#! /p/php/bin/php
<?php

	$RootDirectory = "/cgi-bin/mbmccorm/348/";

	$con = mysql_connect("data.mccormicktechnologies.com", "mccormick_tech", "mcc0rm1ck_t3ch!");
	if (!$con)
	{
		die("Could not connect: " . mysql_error());
	}

	mysql_select_db("mbmccormick_cs348", $con);

?>