<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<p>Hello Faculty. Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/courses">Manage Courses</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/evaluations">Manage Evaluations</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>faculty/students">Manage Students</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../include/footer.php"; ?>