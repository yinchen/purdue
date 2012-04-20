<?php include "../../include/config.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	$result = mysql_query("DELETE FROM Courses WHERE CourseID='" . $_GET['id'] . "' AND FacultyID='" . $faculty['FacultyID'] . "'");

	header("Location: " . $RootDirectory . "faculty/courses?FacultyID=" . $faculty['FacultyID']);
	exit;

?>