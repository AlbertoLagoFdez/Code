.data
msgintroduce: .asciiz "Introduzca un numero flotante: "
msgnumit: .asciiz "El numero de iteraciones necesario es: "
.text
main:
#muestra por pantalla el mensaje
    la $a0,msgintroduce
    li $v0,4
    syscall
#lee un flotante
    li $v0,6
    syscall
#mueve el flotante a $f2
    move.s $f2,$f0