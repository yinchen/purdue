#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	$result = mysql_query("DELETE FROM EvaluationGrades WHERE EvaluationID='" . $_GET['evaluationid'] . "' AND StudentID='" . $_GET['studentid'] . "'"); // AND FacultyID='" . $faculty['FacultyID'] . "'");

	header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
	exit;

?>