#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	$result = mysql_query("DELETE FROM CourseStudents WHERE CourseID='" . $_GET['courseid'] . "' AND StudentID='" . $_GET['studentid'] . "'");

	header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
	exit;

?>