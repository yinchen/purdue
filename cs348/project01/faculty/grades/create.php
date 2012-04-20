<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO EvaluationGrades (EvaluationID, StudentID, Grade) VALUES ('" . $_POST['EvaluationID'] . "', '" . $_POST['StudentID'] . "', '" . $_POST['Grade'] . "')");

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = mysql_query("SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "' ORDER BY CourseName ASC");
	while($row = mysql_fetch_array($result))
	{
		$EvaluationID .= "<optgroup label='" . $row['CourseName'] . "'>\n";

		$result2 = mysql_query("SELECT * FROM CourseEvaluations WHERE CourseID='" . $row['CourseID'] . "' ORDER BY EvaluationName ASC");
		while($row2 = mysql_fetch_array($result2))
		{
			$EvaluationID .= "<option value='" . $row2['EvaluationID'] . "'>" . $row2['EvaluationName'] . "</option>\n";
		}

		$EvaluationID .= "</optgroup>\n";
	}

	$result = mysql_query("SELECT * FROM Students ORDER BY Name ASC");
	while($row = mysql_fetch_array($result))
	{
		$StudentID .= "<option value='" . $row['StudentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently creating a grade:<p>
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
	<input type="submit" value="Create Grade" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>