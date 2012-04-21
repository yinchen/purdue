<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	if (empty($_POST) == false)
	{
		$result = oci_parse($con, "UPDATE Students SET Name='" . $_POST['Name'] . "' WHERE StudentID='" . $_GET['id'] . "'");
		oci_execute($result);

		header("Location: index.php");
		exit;
	}

	$result = oci_parse($con, "SELECT * FROM Students WHERE StudentID='" . $_GET['id'] . "'");
	oci_execute($result);
	$row = oci_fetch_array($result);

?>
<p>Hello Administrator. You are currently editing a student:<p>
<form action="edit.php?id=<?=$row['StudentID']?>" method="post">
	<table cellpadding="0" cellspacing="0">
		<tr>
			<td><b>Name: </b></td>
			<td><input name="Name" type="text" value="<?=$row['Name']?>" /></td>
		</tr>
	</table>
	<br />
	<input type="submit" value="Edit Student" />
</form>
<div class="home">
	<a href="<?=$RootDirectory?>admin/index.php">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>