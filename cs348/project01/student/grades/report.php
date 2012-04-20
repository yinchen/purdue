<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	oci_execute($result);
	$student = oci_fetch_array($result);

?>
<p>Hello <?=$student['Name']?> (Student). Below is the report of your grades for each of your course evaluations:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation Name</th>
		<th>Type</th>
		<th>Grade</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT C.CourseName, E.EvaluationName, E.Type, G.Grade FROM EvaluationGrades G LEFT OUTER JOIN CourseEvaluations AS E ON G.EvaluationID = E.EvaluationID LEFT OUTER JOIN Courses AS C ON E.CourseID = C.CourseID WHERE G.StudentID = '" . $student['StudentID'] . "' ORDER BY C.CourseName, E.DeadlineDate ASC");
		oci_execute($result);

		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['EvaluationName'] . "</td>\n";
			if ($row['Type'] == 0)
				echo "<td>Homework</td>\n";
			else if ($row['Type'] == 1)
				echo "<td>Midterm</td>\n";
			else if ($row['Type'] == 2)
				echo "<td>Final Exam</td>\n";
			else if ($row['Type'] == 3)
				echo "<td>Project</td>\n";
			echo "<td>" . $row['Grade'] . "</td>\n";
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

		$result = oci_parse($con, "SELECT C.CourseName, C.Semester, C.Year, S2.Name, (SELECT SUM(G.Grade * E.Weightage) FROM CourseEvaluations E RIGHT OUTER JOIN EvaluationGrades AS G ON G.EvaluationID = E.EvaluationID WHERE E.CourseID = C.CourseID AND G.StudentID = S1.StudentID) AS CurrentGrade FROM CourseStudents S1 JOIN Students AS S2 ON S2.StudentID = S1.StudentID JOIN Courses AS C ON C.CourseID = S1.CourseID WHERE S1.StudentID = '" . $student['StudentID'] . "' ORDER BY C.CourseName");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Semester'] . "</td>\n";
			echo "<td>" . $row['Year'] . "</td>\n";
			echo "<td>" . $row['CurrentGrade'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?=$RootDirectory?>student?StudentID=<?=$student['StudentID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>