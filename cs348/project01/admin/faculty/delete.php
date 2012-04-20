#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("DELETE FROM Faculties WHERE FacultyID='" . $_GET['id'] . "'");

	header("Location: " . $RootDirectory . "admin/faculty");
	exit;

?>