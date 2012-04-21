<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). Below is the list of your courses:<p>
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

		$result = oci_parse($con, "SELECT * FROM Courses C WHERE C.FacultyID = '" . $faculty['FACULTYID'] . "' ORDER BY C.CourseName");

		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['COURSENAME'] . "</td>\n";
			echo "<td>" . $row['SEMESTER'] . "</td>\n";
			echo "<td>" . $row['YEAR'] . "</td>\n";
			echo "<td>" . $row['MEETS_AT'] . "</td>\n";
			echo "<td>" . $row['ROOM'] . "</td>\n";
			echo "<td><a href=\"edit.php?FacultyID=" . $faculty['FACULTYID'] . "&id=" . $row['COURSEID'] . "\">Edit</a>
			          <a href=\"delete.php?FacultyID=" . $faculty['FACULTYID'] . "&id=" . $row['COURSEID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Course" onClick="location.href='create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>';" />
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>