.data
	sourceString: .ascii "abcde.\n"
	len = .-sourceString
	.comm destinationString,len
	
.global main

main:
	mov $sourceString,%esi
	mov $destinationString,%edi
	mov $len,%ecx
	rep movsb

	/* print */

	mov $len,%edx
	mov $destinationString,%ecx
	mov $1,%ebx
	mov $4,%eax
	int $0x80

	/* exit */

	mov $0,%ebx
	mov $1, %eax
	int $0x80
