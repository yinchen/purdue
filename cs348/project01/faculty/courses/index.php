#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?> (Faculty). Below is the list of your courses:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Name</th>
		<th>Semester</th>
		<th>Year</th>
		<th>Meets At</th>
		<th>Room Number</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM Courses C WHERE C.FacultyID = '" . $faculty['FacultyID'] . "' ORDER BY C.CourseName");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Semester'] . "</td>\n";
			echo "<td>" . $row['Year'] . "</td>\n";
			echo "<td>" . $row['Meets_At'] . "</td>\n";
			echo "<td>" . $row['Room'] . "</td>\n";
			echo "<td><a href=\"edit.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['CourseID'] . "\">Edit</a>
			          <a href=\"delete.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['CourseID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Course" onClick="location.href='create.php?FacultyID=<?=$faculty['FacultyID']?>';" />
<br />
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>