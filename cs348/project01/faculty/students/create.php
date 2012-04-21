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

		header("Location: index.php?FacultyID=" . $faculty['FACULTYID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FACULTYID'] . "'");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$CourseID .= "<option value='" . $row['COURSEID'] . "'>" . $row['COURSENAME'] . "</option>\n";
	}

	$result = oci_parse($con, "SELECT * FROM Students");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$StudentID .= "<option value='" . $row['STUDENTID'] . "'>" . $row['NAME'] . "</option>\n";
	}

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). You are currently assigning a student to one of your courses:<p>
<form action="create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course: </b></td>
			<td><select name="CourseID"><?php echo $CourseID; ?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?php echo $studentID; ?></select></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Assign Student" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>