<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). Below is the report of students and grades:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Student</th>
		<th>Current Grade</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT Courses.CourseName, Courses.Semester, Courses.Year, Students.Name, (SELECT SUM(EvaluationGrades.Grade * E.Weightage) FROM CourseEvaluations E RIGHT OUTER JOIN EvaluationGrades ON EvaluationGrades.EvaluationID = E.EvaluationID WHERE E.CourseID = Courses.CourseID AND EvaluationGrades.StudentID = CourseStudents.StudentID) AS CurrentGrade FROM CourseStudents JOIN Students ON Students.StudentID = CourseStudents.StudentID JOIN Courses ON Courses.CourseID = CourseStudents.CourseID WHERE Courses.FacultyID = '" . $faculty['FACULTYID'] . "' ORDER BY Courses.CourseName, Students.Name");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['SEMESTER'] . "</td>\n";
			echo "<td>" . $row['YEAR'] . "</td>\n";
			echo "<td>" . $row['NAME'] . "</td>\n";
			echo "<td>" . $row['CURRENTGRADE'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>