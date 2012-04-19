<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = mysql_query("INSERT INTO Students (Name) VALUES ('" . $_POST['Name'] . "')");

		header("Location: " . $RootDirectory . "admin/students");
		exit;
	}

?>
<p>Hello Administrator. You are currently creating a student:<p>
<form action="create.php" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Create Student" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>