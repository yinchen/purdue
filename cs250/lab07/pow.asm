# usage: pow <m> <n>
#   m = integer
#   n = non-negative integer

main:       li $v0, 5                 # load m to the argument register
            syscall                 # syscall code 5 is for input.
            move $a0, $v0
     
            li $v0, 5                 # load n to the argument register
            syscall                 # syscall code 5 is for input.
            move $a1, $v0
     
            jal pow                    # call pow
     
            move $a0, $v0             # print out the return argument.
            li $v0, 1                 # syscall code 1 is for printing.
            syscall
     
            li $v0, 10                 # syscall code 10 is for exit.
            syscall                 # make the syscall.
 

pow:        sub $sp, $sp, 12         # make space to save registers on stack 
            sw $a0, 0($sp)            # save a0
            sw $a1, 4($sp)            # save a1
            sw $ra, 8($sp)            # save ra
     
            bgt $a1, $0, gen        # if n>0 then goto generic case 
      
            li $v0, 1                 # if n=0 then set output = 1
            j rest                     # goto restore registers 


gen:        addi $a1, $a1, -1         # n = n-1 
 
            jal pow                    # compute pow(m, n-1)  
            mul $v0, $a0, $v0        # calculate return value = m * pow(m, n-1)
 

rest:       lw $a0, 0($sp)            # restore a0
            lw $a1, 4($sp)            # restore a1
            lw $ra, 8($sp)            # restore ra
 
            addi $sp, $sp, 12         # decrease the stack size 
            jr $ra
