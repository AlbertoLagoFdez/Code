.data
.text

main:
    li $s0,0
    li $t2,1000
    li $t1,1
bucle:
    bgt $t1,$t2,fuera
    add $s0,$s0,$t1
    addi $t1,1
    j bucle
fuera:
    li $v0,10
    syscall
    