<?php include "../../include/config.php"; ?>
<?php include "../../include/header.php"; ?>
<p>Hello Student. Below is the list of your grades:<p>
<table cellpadding="0" cellspacing="0">
	<tr>
		<th>Evaluation Name</th>
		<th>Course Name</th>
		<th>Weightage</th>
		<th>Grade</th>
	</tr>
	<?php

		$result = mysql_query("SELECT * FROM EvaluationGrades G LEFT OUTER JOIN CourseEvaluations AS E ON G.EvaluationID = E.EvaluationID LEFT OUTER JOIN Courses AS C ON E.CourseID = C.CourseID");

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
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../../include/footer.php"; ?>