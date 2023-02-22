.data
        pi: .float 3.1416
.text
main:
#lee un entero por pantalla        
        li $v0, 5
        syscall
#hace una copia cruda y cambia el codigo del entero
        mtc1 $v0,$f4
        cvt.s.w $f6,$f4
#carga pi en un float
        l.s $f8,pi
#realiza la operacion del area
        mul.s $f10,$f8,$f6
#muestra el resultado por pantalla
        move.s $f12,$f10
        li $v0,2
        syscall
#exit
        li $v0,10
        syscall
















#Realiza un programa en MIPS que calcule el área de un círculo a partir del radio, que deberá ser
#introducido por el teclado por el usuario. ¿Qué registros has utilizado? ¿Qué deberías hacer para
#pasar tu programa a doble precisión?.
#Ejecuta en Qtspim paso a paso el programa, realiza las depuraciones utilizando todas las
#funcionalidades de la herramienta.