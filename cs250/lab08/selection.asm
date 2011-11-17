.data

newline:    .asciiz "\n"
heading1:   .asciiz "Array "
heading2:   .asciiz " (of size "
headbrack:  .asciiz "):"
heading3:   .asciiz "\nThe element number "
heading4:   .asciiz "i is: "
heading5:   .asciiz "\nThe number of compare operations used is: "


.text

# main()
main:       jal array1
            jal array2

            li $v0, 10                # syscall code 10 is for exit.
            syscall                   # make the syscall.


# array1()
array1:     la $s0, array1a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size1             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k1
            li $v1, 0                 # start with first element
            jal recurSel
            jal printFinal


# array2()
array2:     la $s0, array2a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size2             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k2     
            li $v1, 0                 # start with first element
            jal recurSel
            jal printFinal


# printFinal($a0 = list, $a1 = left, $a2 = right, $a3 = k)
printFinal: move $a1, $v0
            move $a2, $v1
            la $a0, heading3          # format heading
            li $v0, 4                 # syscall code 4 is for printing.
            syscall                   # make the syscall.

            move $a0, $a3             # assuming a3 has the value of k
            li $v0, 1                 # syscall code 1 is for printing.
            syscall                   # make the syscall.

            la $a0, heading4          # format heading
            move $a1, $v0
            move $a2, $v1
            li $v0, 4                 # syscall code 4 is for printing.
            syscall                   # make the syscall.
            
            jr $ra


# partition($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex) 
partition:  mul $s0, $a3, 4
            add $s0, $a0, $s0
            lw $t0, 0($s0)            # $t0 = list[pivotIndex]

            mul $s0, $a2, 4
            add $s0, $a0, $s0
            lw $t1, 0($s0)            # $t1 = list[right]

            move $t2, $t0             # swap $t0 and $t1
            move $t0, $t1             
            move $t1, $t2
            
            move $t2, $a1             # $t2 = left
            
            # for loop
            
            move $t2, $t0             # swap $t0 and $t1
            move $t0, $t1             
            move $t1, $t2
            
            move $v0, $t2             # $v0 = storeIndex
            jr $ra

# rescurSel($a0 = list, $a1 = left, $a2 = right, $a3 = k) 
recurSel:   move $t0, $a3             # $t0 = k

            sub $a3, $a2, $a1
            srl $a3, $a3, 1           # $a3 = (right - left) / 2
            jal partition

            beq $t0, $v0, recurSel1   # if k = pivotNewIndex
            blt $t0, $v0, recurSel2   # if k < pivotNewIndex
            bgt $t0, $v0, recurSel3   # if k > pivotNewIndex


# recurSel1($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel1:  mul $s0, $a3, 4
            add $s0, $a0, $s0
            lw $v0, 0($s0)            # $v0 = list[k]
            jr $ra

# recurSel2($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel2:  addi $t0, $v0, -1         # $t0 = pivotNewIndex - 1
            move $a2, $s1
            jal recurSel
            jr $ra

# recurSel3($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel3:  addi $t0, $v0, 1          # $t0 = pivotNewIndex + 1
            move $a1, $s1
            jal recurSel
            jr $ra

