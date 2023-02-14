.data
.text
main:
    li $t1,1
    li $t2,2
    li $t3,1

    sub $s0,$t2,$t3
    seq $t4,$s0,$t1
    slt $t6,$t1,$t3
    sge $t7,$t2,$t3
    and $t0,$t6,$t7
    or $t5,$t0,$t4

final:
    li $v0,10
    syscall