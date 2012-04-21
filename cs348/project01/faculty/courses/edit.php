<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE Courses SET CourseName='" . $_POST['CourseName'] . "', Semester='" . $_POST['Semester'] . "', Year='" . $_POST['Year'] . "', Meets_At='" . $_POST['Meets_At'] . "', Room='" . $_POST['Room'] . "' WHERE CourseID='" . $_GET['id'] . "' AND FacultyID='" . $faculty['FacultyID'] . "'");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Courses WHERE CourseID='" . $_GET['id'] . "' AND FacultyID='" . $faculty['FacultyID'] . "'");
	oci_execute($result);
	$row = oci_fetch_array($result);

?>
<p>Hello <?php echo $faculty['Name']; ?> (Faculty). You are currently editing a course:<p>
<form action="edit.php?FacultyID=<?php echo $faculty['FacultyID']; ?>&id=<?php echo $row['CourseID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course Name: </b></td>
			<td><input name="CourseName" type="text" value="<?php echo $row['CourseName']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Semester: </b></td>
			<td><input name="Semester" type="text" value="<?php echo $row['Semester']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Year: </b></td>
			<td><input name="Year" type="text" value="<?php echo $row['Year']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Meets At: </b></td>
			<td><input name="Meets_At" type="text" value="<?php echo $row['Meets_At']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Room: </b></td>
			<td><input name="Room" type="text" value="<?php echo $row['Room']; ?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Course" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FacultyID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>