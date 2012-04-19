<?php include "../include/config.php"; ?>
<?php include "../include/header.php"; ?>
<p>Hello Administrator. Please select an action from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?=$RootDirectory?>admin/departments">Manage Departments</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>admin/faculty">Manage Faculty</a>
	</div>
	<div class="item">
		<a href="<?=$RootDirectory?>admin/students">Manage Students</a>
	</div>
</div>
<div class="home">
	<a href="<?=$RootDirectory?>">Click here to return home</a>
</div>
<?php include "../include/footer.php"; ?>