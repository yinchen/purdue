#! /p/php/bin/php
<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<p>Hello Administrator. Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="departments">Manage Departments</a>
	</div>
	<div class="item">
		<a href="faculty">Manage Faculty</a>
	</div>
	<div class="item">
		<a href="students">Manage Students</a>
	</div>
</div>
<br />
<p>You can also view any of the following reports:<p>
<div class="list">
	<div class="item">
		<a href="departments/report.php">Department Report</a>
	</div>
	<div class="item">
		<a href="faculty/report.php">Faculty Report</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../include/footer.php"; ?>