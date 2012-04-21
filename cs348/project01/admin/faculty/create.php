<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO Faculties (FacultyID, DepartmentID, Name) VALUES ('" . $_POST['FacultyID'] . "', '" . $_POST['DepartmentID'] . "', '" . $_POST['Name'] . "')");
		oci_execute($result);

		header("Location: index.php");
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Departments");
	oci_execute($result);
	while($row = oci_fetch_array($result))
	{
		$DepartmentID .= "<option value='" . $row['DepartmentID'] . "'>" . $row['Name'] . "</option>\n";
	}

?>
<p>Hello Administrator. You are currently creating a faculty:<p>
<form action="create.php" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>ID: </b></td>
			<td><input name="FacultyID" type="text" /></td>
		</tr>
		<tr>
			<td><b>Department: </b></td>
			<td><select name="DepartmentID"><?php echo $DepartmentID; ?></select></td>
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
	<a href="<?php echo $RootDirectory; ?>admin/index.php">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>