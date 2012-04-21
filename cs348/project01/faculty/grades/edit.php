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

		header("Location: index.php?FacultyID=" . $faculty['FACULTYID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM EvaluationGrades WHERE StudentID='" . $_GET['studentid'] . "' AND EvaluationID='" . $_GET['evaluationid'] . "'");
	oci_execute($result);
	$row = oci_fetch_array($result);

	$result2 = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FACULTYID'] . "' ORDER BY CourseName ASC");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		$EvaluationID .= "<optgroup label='" . $row2['COURSENAME'] . "'>\n";

		$result3 = oci_parse($con, "SELECT * FROM CourseEvaluations WHERE CourseID='" . $row2['COURSEID'] . "' ORDER BY EvaluationName ASC");
		oci_execute($result3);
		while($row3 = oci_fetch_array($result3))
		{
			if ($row3['EVALUATIONID'] == $row['EVALUATIONID'])
				$EvaluationID .= "<option value='" . $row3['EVALUATIONID'] . "' selected='true'>" . $row3['EVALUATIONNAME'] . "</option>\n";
			else
				$EvaluationID .= "<option value='" . $row3['EVALUATIONID'] . "'>" . $row3['EVALUATIONNAME'] . "</option>\n";
		}

		$EvaluationID .= "</optgroup>\n";
	}

	$result2 = oci_parse($con, "SELECT * FROM Students ORDER BY Name ASC");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		if ($row2['STUDENTID'] == $row['STUDENTID'])
			$StudentID .= "<option value='" . $row2['STUDENTID'] . "' selected='true'>" . $row2['NAME'] . "</option>\n";
		else
			$StudentID .= "<option value='" . $row2['STUDENTID'] . "'>" . $row2['NAME'] . "</option>\n";
	}

?>
<p>Hello <?php echo $faculty['NAME']; ?> (Faculty). You are currently editing a grade:<p>
<form action="edit.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>&studentid=<?php echo $row['STUDENTID']; ?>&evaluationid=<?php echo $row['EVALUATIONID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Evaluation: </b></td>
			<td><select name="EvaluationID"><?php echo $EvaluationID; ?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?php echo $StudentID; ?></select></td>
		</tr>
		<tr>
			<td><b>Grade: </b></td>
			<td><input name="Grade" type="text" value="<?php echo $row['GRADE']; ?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Grade" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FACULTYID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>