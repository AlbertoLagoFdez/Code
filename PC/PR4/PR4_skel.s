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


    .text
main:
            #cout << title ;
            la $a0,title
            li $v0,4
            syscall

            #cargar los vectores con los numeros dichos
            #for(int i = 0; i < maxdim; i++)
            #{
            #v[i]=10 + i;
            #}

            li $t0,size                 #tamaño bytes
            li $t1,maxdim               #maximo dimension de cada vector
            move $t2,$zero                    #posicion del vector
            la $s0,v1                   #cargar el vector 1 en $s0
            li.s $f4,10.0

buclev1:    mul $t3,$t2,$t0
            addu $t3,$s0,$t3
            swc1 $f4,0($t3)
            addi.s $f4,$f4,1.0
            addi $t2,$t2,1
            




            bne $t2,maxdim,buclev1



            #fin del programa
            la $a0,msg_fin
            li $v0,4
            syscall
            
            li $v0,10
            syscall