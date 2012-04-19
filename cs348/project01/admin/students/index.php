<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<p>Hello Administrator. Below is the list of students:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>ID</th>
		<th>Name</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM Students ORDER BY Name ASC");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['StudentID'] . "</td>\n";
			echo "<td>" . $row['Name'] . "</td>\n";
			echo "<td><a href=\"" . $RootDirectory . "admin/students/edit.php?id=" . $row['StudentID'] . "\">Edit</a>
			          <a href=\"" . $RootDirectory . "admin/students/delete.php?id=" . $row['StudentID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Student" onClick="location.href='<?=$RootDirectory?>admin/students/create.php';" />
<br />
<div class="home">
	<a href="<?=$RootDirectory?>admin">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>