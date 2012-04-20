<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	$result = mysql_query("DELETE FROM CourseEvaluations WHERE EvaluationID='" . $_GET['id'] . "'"); // AND FacultyID='" . $faculty['FacultyID'] . "'");

	header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
	exit;

?>