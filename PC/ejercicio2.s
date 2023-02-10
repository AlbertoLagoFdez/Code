.data
.text

main:
    li $t1,10
    li $t2,0
    li $t3,0
    li $s0,1
    bgt $zero,$t1,final
    bgt $zero,$t2,final
bucle:
    blez $s0,$t1,final
    add $s0,$s0,1
    div $t4,$s0,$t2
    beqz $t4,nocuenta
    addi $t3,1
nocuenta:
    j bucle
final:
    li $v0,10
    syscall