<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<?php

	if (empty($_GET['FacultyID']))
	{	
		$result = oci_parse($con, "SELECT * FROM Faculties ORDER BY Name ASC");
		oci_execute($result);
		while($row = oci_fetch_array($result))
		{
			$FacultyID .= "<option value='" . $row['FacultyID'] . "'>" . $row['Name'] . "</option>\n";
		}

?>
<p>Hello Faculty. Please select your name from the list below:<p>
<form action="index.php" method"get">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><select name="FacultyID"><?=$FacultyID?></select></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Continue" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php

	}
	else
	{
		$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
		oci_execute($result);
		$faculty = oci_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?> (Faculty). Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="courses?FacultyID=<?=$faculty['FacultyID']?>">Manage Courses</a>
	</div>
	<div class="item">
		<a href="evaluations?FacultyID=<?=$faculty['FacultyID']?>">Manage Evaluations</a>
	</div>
	<div class="item">
		<a href="students?FacultyID=<?=$faculty['FacultyID']?>">Manage Student Assignments</a>
	</div>
	<div class="item">
		<a href="grades?FacultyID=<?=$faculty['FacultyID']?>">Manage Grades</a>
	</div>
</div>
<br />
<p>You can also view any of the following reports:<p>
<div class="list">
	<div class="item">
		<a href="courses/report.php?FacultyID=<?=$faculty['FacultyID']?>">Report of Courses</a>
	</div>
	<div class="item">
		<a href="grades/report.php?FacultyID=<?=$faculty['FacultyID']?>">Report of Students and Grades</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php

	}

?>
<?php include "../include/footer.php"; ?>