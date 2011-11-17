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
array1:     sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            la $s0, array1a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size1             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k1
            li $v1, 0                 # start with first element
            jal recurSel
            jal printFinal
            
            j rest


# array2()
array2:     sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            la $s0, array2a           # load the array
            move $a0, $s0
            li $a1, 0                 # set index = 0
            lw $a2, size2             # load array size
            addi $a2, $a2, -1         # update size for zero-based index
            lw $a3, k2     
            li $v1, 0                 # start with first element
            jal recurSel
            jal printFinal
            
            j rest


# printFinal($a0 = list, $a1 = start, $a2 = end, $a3 = k)
printFinal: sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            move $a1, $v0
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
            
            j rest


# partition($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex) 
partition:  sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            mul $s0, $a3, 4
            add $s0, $a0, $s0
            lw $t0, 0($s0)            # $t0 = list[pivotIndex]

            mul $s0, $a2, 4
            add $s0, $a0, $s0
            lw $t1, 0($s0)            # $t1 = list[right]

            move $t2, $t0             # pivotValue($t2) = list[pivotIndex]
            
            move $t9, $t0
            move $t0, $t1             
            move $t1, $t9             # swap list[pivotIndex]($t0) and list[right]($t1)
            
            move $t6, $a1             # storeIndex($t6) = left($a1)
            
            li $s7, 0                 # numCompare($s7) = 0
            
            move $s4, $a1             # i($s4) = left($a1)
            j loop                    # jump to for loop
            
            mul $s0, $t6, 4
            add $s0, $a0, $s0
            lw $t3, 0($s0)            # $t3 = list[storeIndex]
            
            move $t9, $t1
            move $t1, $t3             
            move $t3, $t9             # swap list[right]($t1) and list[storeIndex]($t3)
            
            move $v0, $t6             # $v0 = storeIndex
            j rest                    # return

# for i from left to right-1
loop:       addi $s7, $s7, 1          # numCompare($s7) = numCompare($s7) + 1
            
            mul $s0, $s4, 4
            add $s0, $a0, $s0
            lw $t4, 0($s0)            # $t4 = list[i]
            
            blt $t4, $t2, loop1       # if list[i]($t4) < pivotValue($t2)
            
            move $t9, $t1
            move $t1, $t3             
            move $t3, $t9             # swap list[right]($t1) and list[storeIndex]($t3)
            
            blt $s4, $a2, loop

loop1:      sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            move $t9, $t3
            move $t3, $t4             
            move $t4, $t9             # swap list[storeIndex]($t3) and list[i]($t4)
            
            addi $t6, $t6, 1          # storeIndex($t6) = storeIndex($t6) + 1
            
            j rest
            

# rescurSel($a0 = list, $a1 = left, $a2 = right, $a3 = k) 
recurSel:   sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            move $t0, $a3             # $t0 = k($a3)

            sub $a3, $a2, $a1         # pivotIndex($a3) = right($a2) - left($a1)
            srl $a3, $a3, 1           # pivotIndex($a3) = pivotIndex($a3) / 2
            add $a3, $a1, $a3         # pivotIndex($a3) = left($a1) + pivotIndex($a3)
            jal partition             

            beq $t0, $v0, recurSel1   # if k($t0) = pivotNewIndex($v0)
            blt $t0, $v0, recurSel2   # if k($t0) < pivotNewIndex($v0)
            bgt $t0, $v0, recurSel3   # if k($t0) > pivotNewIndex($v0)


# recurSel1($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel1:  sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            mul $s0, $a3, 4
            add $s0, $a0, $s0
            lw $v0, 0($s0)            # $v0 = list[k]
            
            j rest

# recurSel2($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel2:  sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            addi $t0, $v0, -1         # $t0 = pivotNewIndex - 1
            move $a2, $s1
            jal recurSel
            
            j rest

# recurSel3($a0 = list, $a1 = left, $a2 = right, $a3 = pivotIndex)
recurSel3:  sub $sp, $sp, 4           # increase the stack size 
            sw $ra, 0($sp)            # save ra 
            
            addi $t0, $v0, 1          # $t0 = pivotNewIndex + 1
            move $a1, $s1
            jal recurSel
            
            j rest


rest:       lw $ra, 0($sp)            # restore ra 
            addi $sp, $sp, 4          # decrease the stack size 
            
            jr $ra
