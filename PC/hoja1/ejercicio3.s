.data
.text
main:
    li $t1,1
    li $t2,2
    li $t3,1

    sub $v1,$t2,$t3
    beq $t0,$v1,$t1
    slt $t4,$t1,$t3
    sge $t6,$t2,$t3
    and $t7,$t4,$t6
    or $t5,$t7,$t6

final:
    li $v0,10
    syscall