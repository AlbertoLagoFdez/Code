.data
.text

main:
    li $t1,10
    li $t2,2
    li $v1,1
    li $t3,0
    blez $t1,out
    blez $t2,out
while:
    ble $t1,$v1,out
    addi $v1,1
    div $t4,$v1,$t2
    bnez $t4,outif
    addi $t3,1
outif:
    j while
out:
    li $v0,10
    syscall