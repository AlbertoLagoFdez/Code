.data
.text

main:
    li $t0,4
    li $t1,1
    div $t2,$t1,$t0
    li $v0,10
    syscall