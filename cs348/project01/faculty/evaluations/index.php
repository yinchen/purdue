<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Faculties WHERE FacultyID='" . $_GET['FacultyID'] . "'");
	$faculty = mysql_fetch_array($result);

?>
<p>Hello <?=$faculty['Name']?> (Faculty). Below is the list of your course evaluations:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Course</th>
		<th>Evaluation Name</th>
		<th>Weightage</th>
		<th>Type</th>
		<th>Deadline Date</th>
		<th>Meeting Room</th>
		<th>Actions</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM CourseEvaluations E LEFT OUTER JOIN Courses AS C ON E.CourseID = C.CourseID WHERE C.FacultyID = '" . $faculty['FacultyID'] . "' ORDER BY E.DeadlineDate ASC");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['EvaluationName'] . "</td>\n";
			echo "<td>" . $row['Weightage'] . "</td>\n";
			if ($row['Type'] == 0)
				echo "<td>Homework</td>\n";
			else if ($row['Type'] == 1)
				echo "<td>Midterm</td>\n";
			else if ($row['Type'] == 2)
				echo "<td>Final Exam</td>\n";
			else if ($row['Type'] == 3)
				echo "<td>Project</td>\n";
			echo "<td>" . date("F j, Y, g:i a", strtotime($row['DeadlineDate'])) . "</td>\n";
			echo "<td>" . $row['MeetingRoom'] . "</td>\n";
			echo "<td><a href=\"edit.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['EvaluationID'] . "\">Edit</a>
			          <a href=\"delete.php?FacultyID=" . $faculty['FacultyID'] . "&id=" . $row['EvaluationID'] . "\">Delete</a></td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<br />
<input type="button" value="Create Evaluation" onClick="location.href='create.php?FacultyID=<?=$faculty['FacultyID']?>';" />
<br />
<div class="home">
	<a href="<?=$RootDirectory?>faculty?FacultyID=<?=$faculty['FacultyID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>