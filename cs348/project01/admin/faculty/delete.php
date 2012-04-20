<?php include "../../include/config.php"; ?>
<?php

	$result = oci_parse($con, "DELETE FROM Faculties WHERE FacultyID='" . $_GET['id'] . "'");
	oci_execute($result);

	header("Location: " . $RootDirectory . "admin/faculty");
	exit;

?>