.data
        msgdividendo: .asciiz "Introduzca un dividendo: "
        msgdivisor: .asciiz "Introduzca un divisor: "
        msgresultado: .asciiz "El resultado es: "
.text
main:
#muestra por pantalla el mensaje de msgdividendo
        la $a0,msgdividendo
        li $v0,4
        syscall
#lee un entero por pantalla
        li $v0,5
        syscall
#hace una copia cruda del entero a flotante y despues le cambia el codigo
        mtc1 $v0,$f4
        cvt.s.w $f6,$f4
#muestra por pantalla el mensaje de msg dividendo
        la $a0,msgdivisor
        li $v0,4
        syscall
#lee un entero por pantalla
        li $v0,5
        syscall
#hace una copia cruda del entero a flotante y despues le cambia el codigo
        mtc1 $v0,$f8
        cvt.s.w $f10,$f8 
#divide el dividendo y el divisor y los guarda en $f12
        div.s $f12,$f6,$f10
#muestra por pantalla el mensaje de msgresultado
        la $a0,msgresultado
        li $v0,4
        syscall
#muestra por pantalla el float guardado en $f12
        li $v0,2
        syscall
#exit
        li $v0,10
        syscall