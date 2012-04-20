#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("UPDATE EvaluationGrades SET EvaluationID='" . $_POST['EvaluationID'] . "', StudentID='" . $_POST['StudentID'] . "', Grade='" . $_POST['Grade'] . "' WHERE EvaluationID='" . $_GET['evaluationid'] . "' AND StudentID='" . $_GET['studentid'] . "'");

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = mysql_query("SELECT * FROM EvaluationGrades WHERE StudentID='" . $_GET['studentid'] . "' AND EvaluationID='" . $_GET['evaluationid'] . "'");
	$row = mysql_fetch_array($result);

	$result2 = mysql_query("SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "' ORDER BY CourseName ASC");
	while($row2 = mysql_fetch_array($result2))
	{
		$EvaluationID .= "<optgroup label='" . $row2['CourseName'] . "'>\n";

		$result3 = mysql_query("SELECT * FROM CourseEvaluations WHERE CourseID='" . $row2['CourseID'] . "' ORDER BY EvaluationName ASC");
		while($row3 = mysql_fetch_array($result3))
		{
			if ($row3['EvaluationID'] == $row['EvaluationID'])
				$EvaluationID .= "<option value='" . $row3['EvaluationID'] . "' selected='true'>" . $row3['EvaluationName'] . "</option>\n";
			else
				$EvaluationID .= "<option value='" . $row3['EvaluationID'] . "'>" . $row3['EvaluationName'] . "</option>\n";
		}

		$EvaluationID .= "</optgroup>\n";
	}

	$result2 = mysql_query("SELECT * FROM Students ORDER BY Name ASC");
	while($row2 = mysql_fetch_array($result2))
	{
		if ($row2['StudentID'] == $row['StudentID'])
			$StudentID .= "<option value='" . $row2['StudentID'] . "' selected='true'>" . $row2['Name'] . "</option>\n";
		else
			$StudentID .= "<option value='" . $row2['StudentID'] . "'>" . $row2['Name'] . "</option>\n";
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently editing a grade:<p>
<form action="edit.php?FacultyID=<?=$faculty['FacultyID']?>&studentid=<?=$row['StudentID']?>&evaluationid=<?=$row['EvaluationID']?>" method="post">
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
			<td><input name="Grade" type="text" value="<?=$row['Grade']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Grade" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>