<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<p>Hello Administrator. Below is the list of faculty:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>ID</th>
		<th>Department</th>
		<th>Name</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM Faculties F LEFT OUTER JOIN Departments AS D ON F.DepartmentID = D.DepartmentID");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row[0] . "</td>\n";
			echo "<td>" . $row[4] . "</td>\n";
			echo "<td>" . $row[2] . "</td>\n";
			echo "<td><a href=\"" . $RootDirectory . "admin/faculties/edit.php?id=" . $row[0] . "\">Edit</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../../include/footer.php"; ?>