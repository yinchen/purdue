<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	oci_execute($result);
	$student = oci_fetch_array($result);

?>
<p>Hello <?php echo $student['NAME']; ?> (Student). Below is the report of your grades for each of your course evaluations:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation Name</th>
		<th>Type</th>
		<th>Grade</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT Courses.CourseName, CourseEvaluations.EvaluationName, CourseEvaluations.Type, G.Grade FROM EvaluationGrades G LEFT OUTER JOIN CourseEvaluations ON G.EvaluationID = CourseEvaluations.EvaluationID LEFT OUTER JOIN Courses ON CourseEvaluations.CourseID = Courses.CourseID WHERE G.StudentID = '" . $student['STUDENTID'] . "' ORDER BY Courses.CourseName, CourseEvaluations.DeadlineDate ASC");
		oci_execute($result);

		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['EVALUATIONNAME'] . "</td>\n";
			if ($row['TYPE'] == 0)
				echo "<td>Homework</td>\n";
			else if ($row['TYPE'] == 1)
				echo "<td>Midterm</td>\n";
			else if ($row['TYPE'] == 2)
				echo "<td>Final Exam</td>\n";
			else if ($row['TYPE'] == 3)
				echo "<td>Project</td>\n";
			echo "<td>" . $row['GRADE'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<p>And below is the report of your current grades for your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Current Grade</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT C.CourseName, C.Semester, C.Year, S2.Name, (SELECT SUM(G.Grade * E.Weightage) FROM CourseEvaluations E RIGHT OUTER JOIN EvaluationGrades AS G ON G.EvaluationID = E.EvaluationID WHERE E.CourseID = C.CourseID AND G.StudentID = S1.StudentID) AS CurrentGrade FROM CourseStudents S1 JOIN Students AS S2 ON S2.StudentID = S1.StudentID JOIN Courses AS C ON C.CourseID = S1.CourseID WHERE S1.StudentID = '" . $student['STUDENTID'] . "' ORDER BY C.CourseName");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['SEMESTER'] . "</td>\n";
			echo "<td>" . $row['YEAR'] . "</td>\n";
			echo "<td>" . $row['CurrentGrade'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>student/index.php?StudentID=<?php echo $student['STUDENTID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>