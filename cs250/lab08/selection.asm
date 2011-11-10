.data

newline:    .asciiz "\n"
heading1:   .asciiz "Array "
heading2:   .asciiz " (of size "
headbrack:  .asciiz "):"
heading3:   .asciiz "\nThe element number "
heading3:   .asciiz "i is: "
heading5:   .asciiz "\nThe number of compare operations used is: "


.text

main:       jal array1
            jal array2


array1:     la $s0, array1a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size1             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k1
            li $v1, 0                 # start with first element
            jal recurSel
            jal printfinal


array2:     la $s0, array2a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size2             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k2     
            li $v1, 0                 # start with first element
            jal recurSel
            jal printfinal

            li $v0, 10                # syscall code 10 is for exit.
            syscall                   # make the syscall.


printfinal: la $a0, heading3          # format heading
            move $a1, $v0
            move $a2, $v1
            li $v0, 4                 # syscall code 4 is for printing.
            syscall                   # make the syscall.

            move $a0, $a3             # assuming a3 has the value of k
            li $v0, 1                 # syscall code 1 is for printing.
            syscall                   # make the syscall.

            jr $ra


recurSel:   # choose a pivotIndex between left and right
            jal partition

            beq $a3, $v0, recurSel1
            blt $a3, $v0, recurSel2
            bgt $a3, $v0, recurSel3


recurSel1:  jr $ra
recurSel2:  jal recurSel
            jr $ra
recurSel3:  jal recurSel
            jr $ra

partition:

            jr $ra

            
rest:       lw $a0, 0($sp)            # restore a0
            lw $a1, 4($sp)            # restore a1
            lw $a2, 8($sp)            # restore a2
            lw $a3, 12($sp)           # restore a3
            lw $ra, 16($sp)           # restore ra
 
            addi $sp, $sp, 16         # decrease the stack size 
            jr $ra

