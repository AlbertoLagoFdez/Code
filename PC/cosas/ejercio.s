ncol = 4
nfil = 3
tam_elto = 4

.data
v:          .word       3, 8, 12, 5, 
            .word       4, 1, 6, 3, 
            .word       4, 7, 9, 2

enun:       .asciiz     "\nQue columna quieres sumar (del 0 al 3).\n"
.text
main:
        la $a0, enun
        li $v0, 4
        syscall

        li $v0, 5
        syscall
        move $v0, $t2               #$t2 = n; columna que queremos sumar

        la $s2, v                   #$s2 dir base v

        li $s0, 0                   #suma = 0 -> $s0
        li $s1, 0                   #i = 0 -> $s1
        li $s3, nfil                #size_fil

for:    bge $s1, $s3, finfor

        li $t4, tam_elto

        mul $t3, $t4, 4
        add $t3, $t3, $s2
        lw  $t2, 0($t2)
        add $s0,$s0,$t2
        addi $s1,1
        j for
finfor:
        move $s0, $a0
        li $v0, 1
        syscall

        li $v0, 10
        syscall