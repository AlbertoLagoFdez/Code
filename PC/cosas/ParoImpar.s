    .data
Titulo: .asciiz "\nIntroduzca un número:\n"
Par:    .asciiz "\nSu número es Par\n"
Impar:  .asciiz "\nSu numero es Impar\n"
    .text
main:
    #imprimir el titulo
        li $v0,4
        la $a0,Titulo
        syscall
    #introduce un numero flotante
        li $v0,5
        syscall

        move $v0,$s0        
    #if (numero % 2 == 0)
    # cout << Par
    #else
    # cout << impar
