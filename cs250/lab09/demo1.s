.data
	.comm integer,4
	
.global main

main:

	mov $1279676242,%eax
	mov %ax,(integer)
	mov $integer,%ecx

	mov $2,%edx
	mov $integer,%ecx
	mov $1,%ebx
	mov $4,%eax
	int $0x80

	mov $0,%ebx
	mov $1, %eax
	int $0x80

