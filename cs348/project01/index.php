<?php include "include/config.php"; ?>
<?php include "include/header.php"; ?>
<p>Please select your context from the list below:<p>
<div class="list">
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>admin">Administrator</a>
	</div>
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>faculty">Faculty</a>
	</div>
	<div class="item">
		<a href="<?php echo $RootDirectory; ?>student">Student</a>
	</div>
</div>
<?php include "include/footer.php"; ?>