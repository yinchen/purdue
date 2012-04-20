#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO Faculties (DepartmentID, Name) VALUES ('" . $_POST['DepartmentID'] . "', '" . $_POST['Name'] . "')");

		header("Location: " . $RootDirectory . "admin/faculty");
		exit;
	}

	$result = mysql_query("SELECT * FROM Departments");
	while($row = mysql_fetch_array($result))
	{
		$DepartmentID .= "<option value='" . $row['DepartmentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello Administrator. You are currently creating a faculty:<p>
<form action="create.php" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Department: </b></td>
			<td><select name="DepartmentID"><?=$DepartmentID?></select></td>
		</tr>
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Faculty" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>