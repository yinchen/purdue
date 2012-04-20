<?php include "../../include/config.php"; ?>
<?php

	$result = oci_parse($con, "DELETE FROM Departments WHERE DepartmentID='" . $_GET['id'] . "'");
	oci_execute($result);
	
	header("Location: " . $RootDirectory . "admin/departments");
	exit;

?>