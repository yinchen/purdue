#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO CourseStudents (CourseID, StudentID) VALUES ('" . $_POST['CourseID'] . "', '" . $_POST['StudentID'] . "')");

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = mysql_query("SELECT * FROM Courses WHERE FacultyID='" . $faculty['FacultyID'] . "'");
	while($row = mysql_fetch_array($result))
	{
		$CourseID .= "<option value='" . $row['CourseID'] . "'>" . $row['CourseName'] . "</option>\n";
	}

	$result = mysql_query("SELECT * FROM Students");
	while($row = mysql_fetch_array($result))
	{
		$StudentID .= "<option value='" . $row['StudentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently assigning a student to one of your courses:<p>
<form action="create.php?FacultyID=<?=$faculty['FacultyID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course: </b></td>
			<td><select name="CourseID"><?=$CourseID?></select></td>
		</tr>
		<tr>
			<td><b>Student: </b></td>
			<td><select name="StudentID"><?=$StudentID?></select></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Assign Student" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>