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

		$result = oci_parse($con, "SELECT C.CourseName, C.Semester, C.Year, S2.Name, (SELECT SUM(G.Grade * E.Weightage) FROM CourseEvaluations E RIGHT OUTER JOIN EvaluationGrades AS G ON G.EvaluationID = E.EvaluationID WHERE E.CourseID = C.CourseID AND G.StudentID = S1.StudentID) AS CurrentGrade FROM CourseStudents S1 JOIN Students AS S2 ON S2.StudentID = S1.StudentID JOIN Courses AS C ON C.CourseID = S1.CourseID WHERE C.FacultyID = '" . $faculty['FACULTYID'] . "' ORDER BY C.CourseName, S2.Name");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['SEMESTER'] . "</td>\n";
			echo "<td>" . $row['YEAR'] . "</td>\n";
			echo "<td>" . $row['NAME'] . "</td>\n";
			echo "<td>" . $row['CurrentGrade'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>