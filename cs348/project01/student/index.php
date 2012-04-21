<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<?php

	if (empty($_GET['StudentID']))
	{	
		$result = oci_parse($con, "SELECT * FROM Students ORDER BY Name ASC");
		oci_execute($result);
		while($row = oci_fetch_array($result))
		{
			$StudentID .= "<option value='" . $row['STUDENTID'] . "'>" . $row['NAME'] . "</option>\n";
		}

?>
<p>Hello Student. Please select your name from the list below:<p>
<form action="index.php" method"get">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><select name="StudentID"><?php echo $StudentID; ?></select></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Continue" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>index.php">Click here to return home</a>
</div>
<?php

	}
	else
	{
		$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
		oci_execute($result);
		$student = oci_fetch_array($result);

?>
<p>Hello <?php echo $student['NAME']; ?> (Student). You can view any of the following reports:<p>
<div class="list">
	<div class="item">
		<a href="evaluations/report.php?StudentID=<?php echo $student['STUDENTID']; ?>">Calendar of Evaluations</a>
	</div>
	<div class="item">
		<a href="courses/report.php?StudentID=<?php echo $student['STUDENTID']; ?>">My Courses</a>
	</div>
	<div class="item">
		<a href="grades/report.php?StudentID=<?php echo $student['STUDENTID']; ?>">My Grades</a>
	</div>
</div>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>index.php">Click here to return home</a>
</div>
<?php

	}

?>
<?php include "../include/footer.php"; ?>