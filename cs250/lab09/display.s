.data
    .comm integer, 4

.global main

main:
    // print AL
    mov $0x524F464C, %eax
    mov %al, (integer)
    
    mov $1, %edx
    mov $integer, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80
    
    // print AH
    mov $0x524F464C, %eax
    mov %ah, (integer)
    
    mov $2, %edx
    mov $integer, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80
    
    // print AX
    mov $0x524F464C, %eax
    mov %ax, (integer)
    
    mov $3, %edx
    mov $integer, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80
    
    // print EAX
    mov $0x524F464C, %eax
    mov %eax, (integer)
    
    mov $4, %edx
    mov $integer, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80

    // exit
    mov $0, %ebx
    mov $1, %eax
    int $0x80

