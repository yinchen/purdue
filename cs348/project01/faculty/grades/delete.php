<?php include "../../include/config.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	$result = oci_parse($con, "DELETE FROM EvaluationGrades WHERE EvaluationID='" . $_GET['evaluationid'] . "' AND StudentID='" . $_GET['studentid'] . "'"); // AND FacultyID='" . $faculty['FacultyID'] . "'");
	oci_execute($result);

	header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
	exit;

?>