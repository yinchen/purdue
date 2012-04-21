<?php include "../../include/config.php"; ?>
<?php

	$result = oci_parse($con, "DELETE FROM Students WHERE StudentID='" . $_GET['id'] . "'");
	oci_execute($result);

	header("Location: index.php");
	exit;

?>