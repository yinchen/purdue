<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO CourseEvaluations (EvaluationID, CourseID, EvaluationName, Type, Weightage, DeadlineDate, MeetingRoom) VALUES ('" . $_POST['EvaluationID'] . "', '" . $_POST['CourseID'] . "', '" . $_POST['EvaluationName'] . "', '" . $_POST['Type'] . "', '" . $_POST['Weightage'] . "', '" . $_POST['DeadlineDate'] . "', '" . $_POST['MeetingRoom'] . "')");
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

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). You are currently creating a course evaluation:<p>
<form action="create.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>ID: </b></td>
			<td><input name="EvaluationID" text="text" /></td>
		</tr>
		<tr>
			<td><b>Course: </b></td>
			<td><select name="CourseID"><?php echo $CourseID; ?></select></td>
		</tr>
		<tr>
			<td><b>Name: </b></td>
			<td><input name="EvaluationName" type="text" /></td>
		</tr>
		<tr>
			<td><b>Type: </b></td>
			<td><select name="Type">
				<option value="0">Homework</option>
				<option value="1">Midterm</option>
				<option value="2">Final Exam</option>
				<option value="3">Project</option>
				</select></td>
		</tr>
		<tr>
			<td><b>Weightage: </b></td>
			<td><input name="Weightage" type="text" /></td>
		</tr>
		<tr>
			<td><b>Deadline Date: </b></td>
			<td><input name="DeadlineDate" type="text" /> Format is "DD-MON-YY"</td>
		</tr>
		<tr>
			<td><b>Meeting Room: </b></td>
			<td><input name="MeetingRoom" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Evaluation" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>