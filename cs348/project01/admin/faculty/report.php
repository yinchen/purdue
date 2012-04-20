<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<p>Hello Administrator. Below is the list of faculty:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Department</th>
		<th>Name</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT * FROM Faculties F LEFT OUTER JOIN Departments AS D ON F.DepartmentID = D.DepartmentID");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row[4] . "</td>\n";
			echo "<td>" . $row[2] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>