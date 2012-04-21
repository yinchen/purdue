<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). Below is the list of the grades for your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation</th>
		<th>Student</th>
		<th>Grade</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT E.EvaluationID, S.StudentID, C.CourseName, E.EvaluationName, S.Name, G.Grade FROM EvaluationGrades G JOIN Students AS S ON S.StudentID = G.StudentID JOIN CourseEvaluations AS E ON E.EvaluationID = G.EvaluationID JOIN Courses AS C ON C.CourseID = E.CourseID WHERE C.FacultyID = '" . $faculty['FACULTYID'] . "'");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['EVALUATIONNAME'] . "</td>\n";
			echo "<td>" . $row['NAME'] . "</td>\n";
			echo "<td>" . $row['GRADE'] . "</td>\n";
			echo "<td><a href=\"edit.php?FacultyID=" . $faculty['FACULTYID'] . "&evaluationid=" . $row['EVALUATIONID'] . "&studentid=" . $row['STUDENTID'] . "\">Edit</a>
			          <a href=\"delete.php?FacultyID=" . $faculty['FACULTYID'] . "&evaluationid=" . $row['EVALUATIONID'] . "&studentid=" . $row['STUDENTID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Grade" onClick="location.href='create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>';" />
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>