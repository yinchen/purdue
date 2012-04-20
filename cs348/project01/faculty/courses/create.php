<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO Courses (CourseName, Semester, Year, Meets_At, Room, FacultyID) VALUES ('" . $_POST['CourseName'] . "', '" . $_POST['Semester'] . "', '" . $_POST['Year'] . "', '" . $_POST['Meets_At'] . "', '" . $_POST['Room'] . "', '" . $faculty['FacultyID'] . "')");

		header("Location: index.php?FacultyID=" . $faculty['FacultyID']);
		exit;
	}

?>
<p>Hello <?=$faculty['Name']?> (Faculty). You are currently creating a course:<p>
<form action="create.php?FacultyID=<?=$faculty['FacultyID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Course Name: </b></td>
			<td><input name="CourseName" type="text" /></td>
		</tr>
		<tr>
			<td><b>Semester: </b></td>
			<td><input name="Semester" type="text" /></td>
		</tr>
		<tr>
			<td><b>Year: </b></td>
			<td><input name="Year" type="text" /></td>
		</tr>
		<tr>
			<td><b>Meets At: </b></td>
			<td><input name="Meets_At" type="text" /></td>
		</tr>
		<tr>
			<td><b>Room: </b></td>
			<td><input name="Room" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Course" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>