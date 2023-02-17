.data
        pi: .float 3.1416
.text
main:
        li $v0,5
        syscall

        mtc1 $v0,$f4
        cvt.s.w $f6,$f4

        l.s $f10,pi
        mul.s $f8,$f6,$f6
        mul.s $f12,$f10,$f8

        li $v0,2
        syscall

        li $v0,10
        syscall

