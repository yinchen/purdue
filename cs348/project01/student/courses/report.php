<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	oci_execute($result);
	$student = oci_fetch_array($result);

?>
<p>Hello <?php echo $student['NAME']; ?> (Student). Below is the report of your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Meets At</th>
		<th>Room</th>
		<th>Faculty</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT * FROM CourseStudents S LEFT OUTER JOIN Courses ON S.CourseID = Courses.CourseID LEFT OUTER JOIN Faculties ON Courses.FacultyID = Faculties.FacultyID WHERE S.StudentID = '" . $student['STUDENTID'] . "' ORDER BY CourseName");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['SEMESTER'] . "</td>\n";
			echo "<td>" . $row['YEAR'] . "</td>\n";
			echo "<td>" . $row['MEETS_AT'] . "</td>\n";
			echo "<td>" . $row['ROOM'] . "</td>\n";
			echo "<td>" . $row['NAME'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>student/index.php?StudentID=<?php echo $student['STUDENTID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>