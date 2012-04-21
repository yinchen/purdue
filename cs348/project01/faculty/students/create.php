<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO CourseStudents (CourseID, StudentID) VALUES ('" . $_POST['CourseID'] . "', '" . $_POST['StudentID'] . "')");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "'");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$CourseID .= "<option value='" . $row['CourseID'] . "'>" . $row['CourseName'] . "</option>\n";
	}

	$result = oci_parse($con, "SELECT * FROM Students");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$StudentID .= "<option value='" . $row['StudentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello <?php echo faculty['Name']; ?> (Faculty). You are currently assigning a student to one of your courses:<p>
<form action="create.php?FacultyID=<?php echo faculty['FacultyID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course: </b></td>
			<td><select name="CourseID"><?php echo CourseID; ?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?php echo StudentID; ?></select></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Assign Student" />
</form>
<div class="home">
	<a href="<?php echo RootDirectory; ?>faculty/index.php?FacultyID=<?php echo faculty['FacultyID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>