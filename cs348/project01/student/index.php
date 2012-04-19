<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<p>Hello Student. Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?=$RootDirectory?>student/calendar">Calendar of Evaluations</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>student/courses">My Courses</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>student/grades">My Grades</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../include/footer.php"; ?>