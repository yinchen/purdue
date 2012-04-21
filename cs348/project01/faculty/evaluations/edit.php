<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE CourseEvaluations SET CourseID='" . $_POST['CourseID'] . "', EvaluationName='" . $_POST['EvaluationName'] . "', Type='" . $_POST['Type'] . "', Weightage='" . $_POST['Weightage'] . "', DeadlineDate='" . $_POST['DeadlineDate'] . "', MeetingRoom='" . $_POST['MeetingRoom'] . "' WHERE EvaluationID='" . $_GET['id'] . "'");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM CourseEvaluations WHERE EvaluationID='" . $_GET['id'] . "'");
	oci_execute($result);
	$row = oci_fetch_array($result);

	$result2 = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "'");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		if ($row['CourseID'] == $row2['CourseID'])
			$CourseID .= "<option value='" . $row2['CourseID'] . "' selected='true'>" . $row2['CourseName'] . "</option>\n";
		else
			$CourseID .= "<option value='" . $row2['CourseID'] . "'>" . $row2['CourseName'] . "</option>\n";
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently editing a course evaluation:<p>
<form action="edit.php?FacultyID=<?=$faculty['FacultyID']?>&id=<?=$row['EvaluationID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course: </b></td>
			<td><select name="CourseID"><?=$CourseID?></select></td>
		</tr>
		<tr>
			<td><b>Name: </b></td>
			<td><input name="EvaluationName" type="text" value="<?=$row['EvaluationName']?>" /></td>
		</tr>
		<tr>
			<td><b>Type: </b></td>
			<td><select name="Type">
				<option value="0" <?php if ($row['Type'] == 0) echo "selected='true'"; ?>>Homework</option>
				<option value="1" <?php if ($row['Type'] == 1) echo "selected='true'"; ?>>Midterm</option>
				<option value="2" <?php if ($row['Type'] == 2) echo "selected='true'"; ?>>Final Exam</option>
				<option value="3" <?php if ($row['Type'] == 3) echo "selected='true'"; ?>>Project</option>
				</select></td>
		</tr>
		<tr>
			<td><b>Weightage: </b></td>
			<td><input name="Weightage" type="text" value="<?=$row['Weightage']?>" /></td>
		</tr>
		<tr>
			<td><b>Deadline Date: </b></td>
			<td><input name="DeadlineDate" type="text" value="<?=$row['DeadlineDate']?>" /> Format is "YYYY-MM-DD HH:MM:SS"</td>
		</tr>
		<tr>
			<td><b>Meeting Room: </b></td>
			<td><input name="MeetingRoom" type="text" value="<?=$row['MeetingRoom']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Evaluation" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty/index.php?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>