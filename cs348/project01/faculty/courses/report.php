<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). Below is the report of courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Meets At</th>
		<th>Room Number</th>
		<th>Students</th>
		<th>Evaluations</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT C.CourseID, C.CourseName, C.Meets_At, C.Room, (SELECT COUNT(*) FROM CourseStudents S WHERE S.CourseID = C.CourseID) AS NUMSTUDENTS, (SELECT COUNT(*) FROM CourseEvaluations E WHERE E.CourseID = C.CourseID) AS NUMEVALUATIONS FROM Courses C WHERE C.FacultyID = '" . $faculty['FACULTYID'] . "' ORDER BY C.CourseName");
		oci_execute($result);

		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['MEETS_AT'] . "</td>\n";
			echo "<td>" . $row['ROOM'] . "</td>\n";
			echo "<td>" . $row['NUMSTUDENTS'] . "</td>\n";
			echo "<td>" . $row['NUMEVALUATIONS'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>