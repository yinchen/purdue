<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<p>Hello Administrator. Below is the list of faculty:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Department</th>
		<th>Name</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = oci_parse($con, "SELECT * FROM Faculties F LEFT OUTER JOIN Departments ON F.DepartmentID = Departments.DepartmentID");
		oci_execute($result);
		
		while($row = oci_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row[4] . "</td>\n";
			echo "<td>" . $row[2] . "</td>\n";
			echo "<td><a href=\"" . $RootDirectory . "admin/faculty/edit.php?id=" . $row[0] . "\">Edit</a>
			          <a href=\"" . $RootDirectory . "admin/faculty/delete.php?id=" . $row[0] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Faculty" onClick="location.href='<?php echo $RootDirectory; ?>admin/faculty/create.php';" />
<br />
<div class="home">
	<a href="<?php echo $RootDirectory; ?>admin/index.php">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>