<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("DELETE FROM Students WHERE StudentID='" . $_GET['id'] . "'");

	header("Location: " . $RootDirectory . "admin/students");
	exit;

?>