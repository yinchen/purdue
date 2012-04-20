<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?>. Below is the list of your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course Name</th>
		<th>Meets At</th>
		<th>Room Number</th>
		<th>Students</th>
		<th>Evaluations</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = mysql_query("SELECT C.CourseID, C.CourseName, C.Meets_At, C.Room, (SELECT COUNT(*) FROM CourseStudents S WHERE S.CourseID = C.CourseID) AS NumStudents, (SELECT COUNT(*) FROM CourseEvaluations E WHERE E.CourseID = C.CourseID) AS NumEvaluations FROM Courses C WHERE C.FacultyID = '" . $faculty['FacultyID'] . "'");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Meets_At'] . "</td>\n";
			echo "<td>" . $row['Room'] . "</td>\n";
			echo "<td>" . $row['NumStudents'] . "</td>\n";
			echo "<td>" . $row['NumEvaluations'] . "</td>\n";
			echo "<td><a href=\"" . $RootDirectory . "faculty/courses/edit.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['CourseID'] . "\">Edit</a>
			          <a href=\"" . $RootDirectory . "faculty/courses/delete.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['CourseID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Course" onClick="location.href='<?=$RootDirectory?>faculty/courses/create.php?FacultyID=<?=$faculty['FacultyID']?>';" />
<br />
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>