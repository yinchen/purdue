<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	oci_execute($result);
	$faculty = oci_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO EvaluationGrades (EvaluationID, StudentID, Grade) VALUES ('" . $_POST['EvaluationID'] . "', '" . $_POST['StudentID'] . "', '" . $_POST['Grade'] . "')");
		oci_execute($result);

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "' ORDER BY CourseName ASC");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$EvaluationID .= "<optgroup label='" . $row['CourseName'] . "'>\n";

		$result2 = oci_parse($con, "SELECT * FROM CourseEvaluations WHERE CourseID='" . $row['CourseID'] . "' ORDER BY EvaluationName ASC");
		oci_execute($result2);
		while($row2 = oci_fetch_array($result2))
		{
			$EvaluationID .= "<option value='" . $row2['EvaluationID'] . "'>" . $row2['EvaluationName'] . "</option>\n";
		}

		$EvaluationID .= "</optgroup>\n";
	}

	$result = oci_parse($con, "SELECT * FROM Students ORDER BY Name ASC");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$StudentID .= "<option value='" . $row['StudentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello <?php echo $faculty['Name']; ?> (Faculty). You are currently creating a grade:<p>
<form action="create.php?FacultyID=<?php echo $faculty['FacultyID']; ?>" method="post">
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
			<td><input name="Grade" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Grade" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>faculty/index.php?FacultyID=<?php echo $faculty['FacultyID']; ?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>