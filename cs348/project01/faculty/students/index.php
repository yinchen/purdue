#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?> (Faculty). Below is the list of the students assigned to your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Student</th>
		<th>Course</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT C.CourseID, S.StudentID, P.Name, C.CourseName FROM Courses C JOIN CourseStudents AS S ON S.CourseID = C.CourseID LEFT OUTER JOIN Students AS P ON P.StudentID = S.StudentID WHERE C.FacultyID = '" . $faculty['FacultyID'] . "'");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['Name'] . "</td>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td><a href=\"delete.php?FacultyID=" . $faculty['FacultyID'] . "&courseid=" . $row['CourseID'] . "&studentid=" . $row['StudentID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Assign Student" onClick="location.href='create.php?FacultyID=<?=$faculty['FacultyID']?>';" />
<br />
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>