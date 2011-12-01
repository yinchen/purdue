.data
	sourceString: .ascii "Oh,\"Today is a beautiful day.\"\n"
	len = .-sourceString
	
	
	
.global main

main:	
	mov $0,%ebx
	mov $len,%ecx
loop1:
	cmp %ecx,%ebx
	jge out1
	nop

	mov $sourceString,%edx
	add %ebx,%edx
	mov (%edx),%al
	add $1, %al
	mov %al,(%edx)
	incl %ebx
	jmp loop1
	nop

out1:	
	mov $len,%edx
	mov $sourceString,%ecx
	mov $1,%ebx
	mov $4,%eax
	int $0x80

	mov $0,%ebx
	mov $1, %eax
	int $0x80

