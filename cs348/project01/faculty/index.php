<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<?php

	if (empty($_GET['FacultyID']))
	{	
		$result = mysql_query("SELECT * FROM Faculties ORDER BY Name ASC");
		while($row = mysql_fetch_array($result))
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
		$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
		$faculty = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?>. Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/courses?FacultyID=<?=$faculty['FacultyID']?>">Manage Courses</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/evaluations?FacultyID=<?=$faculty['FacultyID']?>">Manage Evaluations</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/students?FacultyID=<?=$faculty['FacultyID']?>">Manage Students</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/grades?FacultyID=<?=$faculty['FacultyID']?>">Manage Grades</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php

	}

?>
<?php include "../include/footer.php"; ?>