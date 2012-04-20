#! /p/php/bin/php
<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<?php

	if (empty($_GET['StudentID']))
	{	
		$result = mysql_query("SELECT * FROM Students ORDER BY Name ASC");
		while($row = mysql_fetch_array($result))
		{
			$StudentID .= "<option value='" . $row['StudentID'] . "'>" . $row['Name'] . "</option>\n";
		}

?>
<p>Hello Student. Please select your name from the list below:<p>
<form action="index.php" method"get">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><select name="StudentID"><?=$StudentID?></select></td>
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
		$result = mysql_query("SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
		$student = mysql_fetch_array($result);

?>
<p>Hello <?=$student['Name']?> (Student). You can view any of the following reports:<p>
<div class="list">
	<div class="item">
		<a href="evaluations/report.php?StudentID=<?=$student['StudentID']?>">Calendar of Evaluations</a>
	</div>
	<div class="item">
		<a href="courses/report.php?StudentID=<?=$student['StudentID']?>">My Courses</a>
	</div>
	<div class="item">
		<a href="grades/report.php?StudentID=<?=$student['StudentID']?>">My Grades</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php

	}

?>
<?php include "../include/footer.php"; ?>