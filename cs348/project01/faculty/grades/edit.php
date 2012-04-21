<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE EvaluationGrades SET EvaluationID='" . $_POST['EvaluationID'] . "', StudentID='" . $_POST['StudentID'] . "', Grade='" . $_POST['Grade'] . "' WHERE EvaluationID='" . $_GET['evaluationid'] . "' AND StudentID='" . $_GET['studentid'] . "'");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM EvaluationGrades WHERE StudentID='" . $_GET['studentid'] . "' AND EvaluationID='" . $_GET['evaluationid'] . "'");
	oci_execute($result);
	$row = oci_fetch_array($result);

	$result2 = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "' ORDER BY CourseName ASC");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		$EvaluationID .= "<optgroup label='" . $row2['CourseName'] . "'>\n";

		$result3 = oci_parse($con, "SELECT * FROM CourseEvaluations WHERE CourseID='" . $row2['CourseID'] . "' ORDER BY EvaluationName ASC");
		oci_execute($result3);
		while($row3 = oci_fetch_array($result3))
		{
			if ($row3['EvaluationID'] == $row['EvaluationID'])
				$EvaluationID .= "<option value='" . $row3['EvaluationID'] . "' selected='true'>" . $row3['EvaluationName'] . "</option>\n";
			else
				$EvaluationID .= "<option value='" . $row3['EvaluationID'] . "'>" . $row3['EvaluationName'] . "</option>\n";
		}

		$EvaluationID .= "</optgroup>\n";
	}

	$result2 = oci_parse($con, "SELECT * FROM Students ORDER BY Name ASC");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		if ($row2['StudentID'] == $row['StudentID'])
			$StudentID .= "<option value='" . $row2['StudentID'] . "' selected='true'>" . $row2['Name'] . "</option>\n";
		else
			$StudentID .= "<option value='" . $row2['StudentID'] . "'>" . $row2['Name'] . "</option>\n";
	}

?>
<p>Hello <?php echo $faculty['Name']; ?> (Faculty). You are currently editing a grade:<p>
<form action="edit.php?FacultyID=<?php echo $faculty['FacultyID']; ?>&studentid=<?php echo $row['StudentID']; ?>&evaluationid=<?php echo $row['EvaluationID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Evaluation: </b></td>
			<td><select name="EvaluationID"><?php echo EvaluationID; ?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?php echo $studentID; ?></select></td>
		</tr>
		<tr>
			<td><b>Grade: </b></td>
			<td><input name="Grade" type="text" value="<?php echo $row['Grade']; ?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Grade" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FacultyID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>