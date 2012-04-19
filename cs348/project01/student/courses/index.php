<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	$student = mysql_fetch_array($result);

?>
<p>Hello <?=$student['Name']?>. Below is the list of your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course Name</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Meets At</th>
		<th>Room</th>
		<th>Faculty</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM CourseStudents S LEFT OUTER JOIN Courses AS C ON S.CourseID = C.CourseID LEFT OUTER JOIN Faculties AS F ON C.FacultyID = F.FacultyID WHERE S.StudentID = '" . $student['StudentID'] . "'");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Semester'] . "</td>\n";
			echo "<td>" . $row['Year'] . "</td>\n";
			echo "<td>" . $row['Meets_At'] . "</td>\n";
			echo "<td>" . $row['Room'] . "</td>\n";
			echo "<td>" . $row['Name'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<div class="home">
	<a href="<?=$RootDirectory?>student?StudentID=<?=$student['StudentID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>