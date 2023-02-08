.data
.text
main:
    li $t1,3
    li $t2,1
    bgt $t1,$t2,opcion1
    move $t3,$t1
    j siguiente
opcion1:
    move $t3,$t2
     $t3,$t2
siguiente:
    bgt $t1,$t2,opcion2
    move $t4,$t2
    j siguiente2
opcion2:
    move $t4,$t1
siguiente2:
    move $t5,$t3,$t4
    li $v0,10
    syscall