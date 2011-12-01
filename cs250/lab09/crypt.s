.data
    plaintext: .ascii "There are no secrets better kept than the secrets that everybody guesses.\n"
    len = .-plaintext
    .comm ciphertext, len
    .comm decryptedtext, len

.global main

main:
    mov $0xC4, %dl
    mov %dl, %ah
    
    mov $0, %ebx
    mov $len, %ecx
    jmp loop1
    nop
    
loop1:
    // for (ebx = 0; ebx < ecx; ebx++)
    cmp %ecx, %ebx
    jge out1
    nop
    
    // restore key
    mov %ah, %dl

    // get plaintext[ebx]
    mov $plaintext, %edx
    add %ebx, %edx
    
    // compute xor
    mov (%edx), %al
    xor %dl, %al
    
    // get ciphertext[ebx]
    mov $ciphertext, %edx
    add %ebx, %edx
    
    // store value
    mov %al, (%edx)
    
    incl %ebx    
    jmp loop1
    nop

out1:
    mov $0, %ebx
    mov $len, %ecx
    jmp loop2
    nop

loop2:
    // for (ebx = 0; ebx < ecx; ebx++)
    cmp %ecx, %ebx
    jge out2
    nop
    
    // restore key
    mov %ah, %dl

    // get ciphertext[ebx]
    mov $ciphertext, %edx
    add %ebx, %edx
    
    // compute xor
    mov (%edx), %al
    xor %dl, %al
    
    // get decryptedtext[ebx]
    mov $decryptedtext, %edx
    add %ebx, %edx
    
    // store value
    mov %al, (%edx)
    
    incl %ebx    
    jmp loop1
    nop

out2:
    // print plaintext
    mov $len, %edx
    mov $plaintext, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80
    
    // print ciphertext
    mov $len, %edx
    mov $ciphertext, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80
    
    // print decryptedtext
    mov $len, %edx
    mov $decryptedtext, %ecx
    mov $1, %ebx
    mov $4, %eax
    int $0x80

    // exit
    mov $0,%ebx
    mov $1, %eax
    int $0x80

