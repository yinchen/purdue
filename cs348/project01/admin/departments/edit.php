<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE Departments SET DepartmentID='" . $_POST['DepartmentID'] . "', Name='" . $_POST['Name'] . "', HeadName='" . $_POST['HeadName'] . "' WHERE DepartmentID='" . $_GET['id'] . "'");
		oci_execute($result);

		header("Location: index.php");
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Departments WHERE DepartmentID='" . $_GET['id'] . "'");
	$row = oci_fetch_array($result);
	oci_execute($result);

?>
<p>Hello Administrator. You are currently editing a department:<p>
<form action="edit.php?id=<?php echo $row['DEPARTMENTID']; ?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>ID: </b></td>
			<td><input name="DepartmentID" type="text" value="<?php echo $row['DEPARTMENTID']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" value="<?php echo $row['NAME']; ?>" /></td>
		</tr>
		<tr>
			<td><b>Head Name: </b></td>
			<td><input name="HeadName" type="text" value="<?php echo $row['HEADNAME']; ?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Department" />
</form>
<div class="home">
	<a href="<?php echo $RootDirectory; ?>admin/index.php">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>