.data
        msgdividendo: .asciiz "Introduzca un dividendo: "
        msgdivisor: .asciiz "Introduzca un divisor: "
        msgresultado: .asciiz "El resultado es: "
.text
main:
        la $a0,msgdividendo
        li $v0,4
        syscall

        li $v0,5
        syscall

        mtc1 $v0,$f4
        cvt.s.w $f6,$f4

        la $a0,msgdivisor
        li $v0,4
        syscall

        li $v0,5
        syscall

        mtc1 $v0,$f8
        cvt.s.w $f10,$f8 

        div.s $f12,$f6,$f10
        
        la $a0,msgresultado
        li $v0,4
        syscall

        li $v0,2
        syscall

        li $v0,10
        syscall