<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "INSERT INTO Departments (Name, HeadName) VALUES ('" . $_POST['Name'] . "', '" . $_POST['HeadName'] . "')");
		oci_execute($result);

		header("Location: index.php");
		exit;
	}

?>
<p>Hello Administrator. You are currently creating a department:<p>
<form action="create.php" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" /></td>
		</tr>
		<tr>
			<td><b>Head Name: </b></td>
			<td><input name="HeadName" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Department" />
</form>
<div class="home">
	<a href="<?php echo RootDirectory; ?>admin/index.php">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>