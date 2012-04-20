#! /p/php/bin/php
<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE Faculties SET DepartmentID='" . $_POST['DepartmentID'] . "', Name='" . $_POST['Name'] . "' WHERE FacultyID='" . $_GET['id'] . "'");
		oci_execute($result);

		header("Location: " . $RootDirectory . "admin/faculty");
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Faculties WHERE FacultyID='" . $_GET['id'] . "'");
	$row = oci_fetch_array($result);
	oci_execute($result);

	$result2 = oci_parse($con, "SELECT * FROM Departments");
	oci_execute($result2);
	while($row2 = oci_fetch_array($result2))
	{
		if ($row['DepartmentID'] == $row2['DepartmentID'])
			$DepartmentID .= "<option value='" . $row2['DepartmentID'] . "' selected='true'>" . $row2['Name'] . "</option>\n";
		else
			$DepartmentID .= "<option value='" . $row2['DepartmentID'] . "'>" . $row2['Name'] . "</option>\n";
	}

?>
<p>Hello Administrator. You are currently editing a faculty:<p>
<form action="edit.php?id=<?=$row['FacultyID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Department: </b></td>
			<td><select name="DepartmentID"><?=$DepartmentID?></select></td>
		</tr>
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" value="<?=$row['Name']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Faculty" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>