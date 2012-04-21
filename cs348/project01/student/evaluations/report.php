<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	oci_execute($result);
	$student = oci_fetch_array($result);

?>
<p>Hello <?php echo $student['NAME']; ?> (Student). Below is the report of your evaluations:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation Name</th>
		<th>Weightage</th>
		<th>Type</th>
		<th>Deadline Date</th>
		<th>Meeting Room</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT * FROM CourseEvaluations E LEFT OUTER JOIN Courses ON E.CourseID = Courses.CourseID LEFT OUTER JOIN CourseStudents ON Courses.CourseID = CourseStudents.CourseID WHERE CourseStudents.StudentID = '" . $student['STUDENTID'] . "' ORDER BY E.DeadlineDate ASC");
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
			echo "<td>" . date("F j, Y", strtotime($row['DEADLINEDATE'])) . "</td>\n";
			echo "<td>" . $row['MEETINGROOM'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>student/index.php?StudentID=<?php echo $student['STUDENTID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>