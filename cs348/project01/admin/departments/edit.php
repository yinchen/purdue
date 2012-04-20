<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE Departments SET Name='" . $_POST['Name'] . "', HeadName='" . $_POST['HeadName'] . "' WHERE DepartmentID='" . $_GET['id'] . "'");
		oci_execute($result);

		header("Location: " . $RootDirectory . "admin/departments");
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Departments WHERE DepartmentID='" . $_GET['id'] . "'");
	$row = oci_fetch_array($result);
	oci_execute($result);

?>
<p>Hello Administrator. You are currently editing a department:<p>
<form action="edit.php?id=<?=$row['DepartmentID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" value="<?=$row['Name']?>" /></td>
		</tr>
		<tr>
			<td><b>Head Name: </b></td>
			<td><input name="HeadName" type="text" value="<?=$row['HeadName']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Department" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>