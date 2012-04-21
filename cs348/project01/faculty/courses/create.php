<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO Courses (CourseID, CourseName, Semester, Year, Meets_At, Room, FacultyID) VALUES ('" . $_POST['CourseID'] . "', '" . $_POST['CourseName'] . "', '" . $_POST['Semester'] . "', '" . $_POST['Year'] . "', '" . $_POST['Meets_At'] . "', '" . $_POST['Room'] . "', '" . $faculty['FACULTYID'] . "')");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FACULTYID']);
		exit;
	}

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). You are currently creating a course:<p>
<form action="create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>ID: </b></td>
			<td><input name="CourseID" type="text" /></td>
		</tr>
		<tr>
			<td><b>Course Name: </b></td>
			<td><input name="CourseName" type="text" /></td>
		</tr>
		<tr>
			<td><b>Semester: </b></td>
			<td><input name="Semester" type="text" /></td>
		</tr>
		<tr>
			<td><b>Year: </b></td>
			<td><input name="Year" type="text" /></td>
		</tr>
		<tr>
			<td><b>Meets At: </b></td>
			<td><input name="Meets_At" type="text" /></td>
		</tr>
		<tr>
			<td><b>Room: </b></td>
			<td><input name="Room" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Course" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>