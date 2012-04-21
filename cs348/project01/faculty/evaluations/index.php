<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). Below is the list of your course evaluations:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation Name</th>
		<th>Weightage</th>
		<th>Type</th>
		<th>Deadline Date</th>
		<th>Meeting Room</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT * FROM CourseEvaluations E LEFT OUTER JOIN Courses ON E.CourseID = Courses.CourseID WHERE Courses.FacultyID = '" . $faculty['FACULTYID'] . "' ORDER BY E.DeadlineDate ASC");
		oci_execute($result);

		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['EVALUATIONNAME'] . "</td>\n";
			echo "<td>" . $row['WEIGHTAGE'] . "</td>\n";
			if ($row['TYPE'] == 0)
				echo "<td>Homework</td>\n";
			else if ($row['TYPE'] == 1)
				echo "<td>Midterm</td>\n";
			else if ($row['TYPE'] == 2)
				echo "<td>Final Exam</td>\n";
			else if ($row['TYPE'] == 3)
				echo "<td>Project</td>\n";
			echo "<td>" . date("F j, Y, g:i a", strtotime($row['DEADLINEDATE'])) . "</td>\n";
			echo "<td>" . $row['MEETINGROOM'] . "</td>\n";
			echo "<td><a href=\"edit.php?FacultyID=" . $faculty['FACULTYID'] . "&id=" . $row['EVALUATIONID'] . "\">Edit</a>
			          <a href=\"delete.php?FacultyID=" . $faculty['FACULTYID'] . "&id=" . $row['EVALUATIONID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Evaluation" onClick="location.href='create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>';" />
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>