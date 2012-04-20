<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?> (Faculty). Below is the report of students and grades:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Student</th>
		<th>Current Grade</th>
	</tr>
	<?php

		$result = mysql_query("SELECT C.CourseName, C.Semester, C.Year, S2.Name, (SELECT SUM(G.Grade * E.Weightage) FROM CourseEvaluations E RIGHT OUTER JOIN EvaluationGrades AS G ON G.EvaluationID = E.EvaluationID WHERE E.CourseID = C.CourseID AND G.StudentID = S1.StudentID) AS CurrentGrade FROM CourseStudents S1 JOIN Students AS S2 ON S2.StudentID = S1.StudentID JOIN Courses AS C ON C.CourseID = S1.CourseID WHERE C.FacultyID = '" . $faculty['FacultyID'] . "' ORDER BY C.CourseName, S2.Name");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Semester'] . "</td>\n";
			echo "<td>" . $row['Year'] . "</td>\n";
			echo "<td>" . $row['Name'] . "</td>\n";
			echo "<td>" . $row['CurrentGrade'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>