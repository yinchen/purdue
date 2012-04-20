<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<?php

	$result = mysql_query("SELECT * FROM Students WHERE StudentID='" . $_GET['StudentID'] . "'");
	$student = mysql_fetch_array($result);

?>
<p>Hello <?=$student['Name']?>. Below is the list of your grades:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Evaluation Name</th>
		<th>Course</th>
		<th>Weightage</th>
		<th>Grade</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM EvaluationGrades G LEFT OUTER JOIN CourseEvaluations AS E ON G.EvaluationID = E.EvaluationID LEFT OUTER JOIN Courses AS C ON E.CourseID = C.CourseID WHERE G.StudentID = '" . $student['StudentID'] . "' ORDER BY E.DeadlineDate ASC");

		while($row = mysql_fetch_array($result))
		{
			echo "<tr>\n";
			echo "<td>" . $row['EvaluationName'] . "</td>\n";
			echo "<td>" . $row['CourseName'] . "</td>\n";
			echo "<td>" . $row['Weightage'] . "</td>\n";
			echo "<td>" . $row['Grade'] . "</td>\n";
			echo "</tr>\n";
		}

	?>
</table>
<div class="home">
	<a href="<?=$RootDirectory?>student?StudentID=<?=$student['StudentID']?>">Click here to return to the menu</a>
</div>
<?php include "../../include/footer.php"; ?>