# Autor: Alberto Lago Fernandez
# Fecha ultima modificacion: 18/04/2023

size = 4     # bytes que ocupa cada elemento
maxdim = 40  # dimension maxima que puede tener un vector
    .data
v1:         .space 160
v2:         .space 160 
n1:         .word 0 # numero eltos vector 1. Inicialmente suponemos vacios
n2:         .word 0 # numero eltos vector 2. Inicialmente suponemos vacios
space:      .asciiz " "
newline:    .asciiz "\n"
title:      .asciiz "\nPractica 4 de Principios de Computadores. Subrutinas.\n"
menu:       .ascii  "\n(1) Cambiar dimension de un vector\n(2) Cambiar un elemento de un vector\n"
            .ascii  "(3) Invertir un vector\n(4) Calcular el producto escalar de dos vectores\n"
            .asciiz "(0) Salir\n\nElija opcion: ";
cabvec:     .asciiz "\nVector con dimension "
error_op:   .asciiz "\nError: opcion incorrecta.\n"
elige_vec:  .asciiz "\nElija vector para realizar la operacion (1) para v1 (2) para v2: "
elige_elto: .asciiz "\nElija el indice del elemento a cambiar: "
newval:     .asciiz "\nIntroduce nuevo valor para el elemento elegido: "
newdim:     .asciiz "\nIntroduzca nueva dimension para el vector (1-40): "
error_dim:  .asciiz "\nError: Dimension incorrecta.\n"
error_ind:  .asciiz "\nError: Indice incorrecto.\n"
error_d_dim:    .asciiz "\nError: Los vectores tienen distinta dimension.\n"
msg_prodesc:    .asciiz "\nEl producto escalar de los vectores es: "
msg_fin:    .asciiz "\nFIN DEL PROGRAMA."
msg_vectorbuca:      .asciiz "\n¿Que numero quieres buscar?\n"
msg_encontrado:      .asciiz "\nEncontrado. En la posicion: "
msg_noencontrado:   .asciiz "\nNo Encontrado\n"


    .text

#funcion Busqueda modificacion

busqueda:
move $s0, $a0
move $s2, $a1
mov.s $f20, $f12

li $s7, 0           #posicion del vector encontrado



buclebusqueda:

bgt $s7, $s2, salidamala

l.s $f4, 0($s0)
c.eq.s $f4, $f20
bc1t salidabuena

addi $s7, $s7,1      #cambio la posicion

addi $s1, $s1, 1
addi $s0, $s0, 4
bgt $s1, $s2, buclebusqueda



salidamala:
la $a0, msg_noencontrado
li $v0, 4
syscall

li $a0, -1
li $v0, 1
syscall

la $a0,newline
li $v0, 4
syscall

jr $ra

salidabuena:

la $a0, msg_encontrado
li $v0, 4
syscall

move $a0, $s7
li $v0, 1
syscall

la $a0, newline
li $v0, 4
syscall

jr $ra
#funcion void print_vec() que recibe $a0 = v1  , $a1 = n1, $a2 = space
print_vec:

                add $sp, $sp -16
                sw $s0, 0($sp)
                sw $s1, 4($sp)
                sw $s2, 8($sp)
                sw $s3, 12($sp)
                move $s0, $a0
                move $s2, $a1
                move $s3, $a2
                li $s1,0

#for(int i = 0, i < vector.size(); i++)
buclevectorprin:
                l.s $f4, 0($s0)
                mov.s $f12, $f4
                li $v0, 2
                syscall

                move $a0, $s3
                li $v0, 4
                syscall

                addi $s1, $s1, 1
                addi $s0, $s0, 4
                blt $s1, $s2, buclevectorprin

                lw $s3, 0($sp)
                lw $s2, 4($sp)
                lw $s1, 8($sp)
                lw $s0, 12($sp)
                addi $sp, $sp, 16
print_vec_fin:  jr $ra

#funcion void change_elto()

change_elto:
                mul $a1, $a1, 4
                add $a0, $a0, $a1
                s.s $f12, 0($a1)

change_elto_fin: jr $ra
                

#main del codigo 

main:
#imprimir titulo 
                la $a0, title
                li $v0, 4
                syscall
#cargar el maximo de elementos en n1 y en n2
                li $t0, 40
                sw $t0, n1
                sw $t0, n2
bucle:

                li $t0, 0
                li.s $f4, 10.0

                la $a1, v1
                lw $a2, n1

buclev1:
                s.s $f4, 0($a1)
                li.s $f5, 1.0
                add.s $f4, $f5, $f4

                addi $t0, $t0, 1

                addi $a1, $a1, 4
                blt $t0, $a2, buclev1

                li $t1, 0
                li.s $f5, 40.0

                la $s0, v2
                lw $s1, n2
buclev2:        
                s.s $f5, 0($s0)
                li.s $f6, -1.0
                add.s $f5, $f6, $f5

                addi $t1, $t1, 1

                addi $s0, $s0,4
                blt $t1, $s1, buclev2

msgvectores:    la $a0, cabvec
                li $v0,4
                syscall

                
                lw $a2, n1
                move $a0, $a2
                li $v0, 1
                syscall

                
                la $a0, newline
                li $v0, 4
                syscall

                la $a0, v1
                lw $a1, n1
                la $a2, space
                jal print_vec

                li $v0, 4
                la $a0, newline
                syscall


                la $a0, cabvec
                li $v0, 4
                syscall

                
                lw $a2 n2
                move $a0, $a2
                li $v0, 1
                syscall

                
                la $a0, newline
                li $v0, 4
                syscall
                
                la $a0, v2
                lw $a1, n2
                la $a2, space
                jal print_vec

                
                la $a0, newline
                li $v0, 4
                syscall

                
                la $a0, menu
                li $v0, 4
                syscall
                
                li $v0, 5
                syscall
                move $t0, $v0
                
                beq $t0, 1, opcion_1
                beq $t0, 2, opcion_2
                beq $t0, 3, opcion_3
                beq $t0, 4, opcion_4
                beq $t0, 5, opcion_5

                beq $t0, 0, fin

                la $a0, error_op
                li $v0, 4
                syscall

                j msgvectores

opcion_1:       la $a0, elige_vec
                li $v0, 4
                syscall

                li $v0, 5
                syscall
                move $t1, $v0

                blt $t1, 1, ErrorDeVector
                bgt $t1, 2, ErrorDeVector

                beq $t1, 2, Vector2CambioDeElementos

#cambio de elementos del vector 1
                la $a0, newdim
                li $v0, 4
                syscall

                li $v0, 5
                syscall 
                move $s0, $v0

                blt $s0, 1, ErrorDeDimension
                bgt $s0, 40, ErrorDeDimension

                sw $s0, n1
                j msgvectores

Vector2CambioDeElementos:
            
                la $a0, newdim
                li $v0, 4
                syscall

                li $v0, 5
                syscall 
                move $s0, $v0

                blt $s0, 1, ErrorDeDimension
                bgt $s0, 40, ErrorDeDimension

                sw $s0, n2
                j msgvectores

ErrorDeVector:  la $a0, error_op
                li $v0, 4
                syscall

                j msgvectores

ErrorDeDimension:
                la $a0, error_dim
                li $v0, 4
                syscall

                j msgvectores


opcion_2:       la $a0, elige_vec
                li $v0, 4
                syscall

                li $v0, 5
                syscall
                move $t1, $v0

                blt $t1, 1, ErrorDeVector2
                bgt $t1, 2, ErrorDeVector2

                beq $t1, 2, VectorNum2CambioElto

                la $a0, elige_elto
                li $v0, 4
                syscall

                li $v0, 5
                syscall
                move $s0, $v0

                la $a0, newval
                li $v0, 4
                syscall

                li $v0, 6
                syscall 
                mov.s $f20, $f0

                la $a0, v1
                move $a1, $s0
                mov.s $f12, $f20
                jal change_elto

                j msgvectores


VectorNum2CambioElto:

                la $a0, elige_elto
                li $v0, 4
                syscall

                li $v0, 5 
                syscall
                move $s0, $a0

                la $a0, newval
                li $v0, 4
                syscall

                li $v0, 6
                syscall 
                mov.s $f20, $f0

                la $a0, v2
                move $a1, $s0
                mov.s $f12, $f20
                jal change_elto

                j msgvectores


ErrorDeDimension2:
                la $a0, error_dim
                li $v0, 4
                syscall

                j msgvectores

ErrorDeVector2: la $a0, error_op
                li $v0, 4
                syscall

                j msgvectores



opcion_3:



                j msgvectores

opcion_4:

                j msgvectores
                

opcion_5:
#la $a0, elige_vec
#li $v0, 4
#syscall

#li $v0, 5
#syscall
#move $t1, $v0

la $a0, msg_vectorbuca
li $v0,4
syscall

li $v0,6
syscall
mov.s $f20,$f0

la $a0, v1
lw $a1, n1
mov.s $f12, $f20

jal busqueda


                j msgvectores
            
                #fin del programa
fin:            la $a0, msg_fin
                li $v0, 4
                syscall

                li $v0, 10
                syscall


