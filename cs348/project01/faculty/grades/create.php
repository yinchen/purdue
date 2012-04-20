<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO EvaluationGrades (EvaluationID, StudentID, Grade) VALUES ('" . $_POST['CourseID'] . "', '" . $_POST['EvaluationName'] . "', '" . $_POST['Type'] . "', '" . $_POST['Weightage'] . "', '" . $_POST['DeadlineDate'] . "', '" . $_POST['MeetingRoom'] . "')");

		header("Location: " . $RootDirectory . "faculty/evaluations?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = mysql_query("SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "'");
	while($row = mysql_fetch_array($result))
	{
		$CourseID .= "<option value='" . $row['CourseID'] . "'>" . $row['CourseName'] . "</option>\n";
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently creating a course evaluation:<p>
<form action="create.php?FacultyID=<?=$faculty['FacultyID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Evaluation: </b></td>
			<td><select name="EvaluationID"><?=$EvaluationID?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?=$StudentID?></select></td>
		</tr>
		<tr>
			<td><b>Grade: </b></td>
			<td><input name="Grade" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Evaluation" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>