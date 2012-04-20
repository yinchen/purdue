#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("DELETE FROM Departments WHERE DepartmentID='" . $_GET['id'] . "'");

	header("Location: " . $RootDirectory . "admin/departments");
	exit;

?>