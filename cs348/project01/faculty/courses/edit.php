<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("UPDATE Courses SET CourseName='" . $_POST['CourseName'] . "', Semester='" . $_POST['Semester'] . "', Year='" . $_POST['Year'] . "', Meets_At='" . $_POST['Meets_At'] . "', Room='" . $_POST['Room'] . "' WHERE CourseID='" . $_GET['id'] . "' AND FacultyID='" . $faculty['FacultyID'] . "'");

		header("Location: " . $RootDirectory . "faculty/courses?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

	$result = mysql_query("SELECT * FROM Courses WHERE CourseID='" . $_GET['id'] . "' AND FacultyID='" . $faculty['FacultyID'] . "'");
	$row = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?>. You are currently editing a course:<p>
<form action="edit.php?FacultyID=<?=$faculty['FacultyID']?>&id=<?=$row['CourseID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course Name: </b></td>
			<td><input name="CourseName" type="text" value="<?=$row['CourseName']?>" /></td>
		</tr>
		<tr>
			<td><b>Semester: </b></td>
			<td><input name="Semester" type="text" value="<?=$row['Semester']?>" /></td>
		</tr>
		<tr>
			<td><b>Year: </b></td>
			<td><input name="Year" type="text" value="<?=$row['Year']?>" /></td>
		</tr>
		<tr>
			<td><b>Meets At: </b></td>
			<td><input name="Meets_At" type="text" value="<?=$row['Meets_At']?>" /></td>
		</tr>
		<tr>
			<td><b>Room: </b></td>
			<td><input name="Room" type="text" value="<?=$row['Room']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Course" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>