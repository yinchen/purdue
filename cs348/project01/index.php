<?php include "include/config.php"; ?>
<?php include "include/header.php"; ?>
<p>Please select your context from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>admin/index.php">Administrator</a>
	</div>
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>faculty/index.php">Faculty</a>
	</div>
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>student/index.php">Student</a>
	</div>
</div>
<?php include "include/footer.php"; ?>