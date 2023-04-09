.data
matrix: .word 1, 2, 3, 4, 5, 
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15
newline: .asciiz "\n"
space:   .asciiz " "

.text
main:
    li $t0, 0         # inicializa el contador de filas
    la $t1, matrix    # carga la dirección base de la matriz
    
print_loop:
    li $t2, 0         # inicializa el contador de columnas
    
column_loop:
    lw $a0, ($t1)     # carga el valor actual de la matriz
    li $v0, 1         # prepara la llamada al sistema para imprimir
    syscall           # imprime el valor
    
    # imprime un espacio después de cada columna, excepto después de la última columna
    addi $t2, $t2, 1
    beq $t2, 5, no_space
    la $a0, space
    li $v0, 4
    syscall
    
no_space:
    addi $t1, $t1, 4   # incrementa el índice de matriz por el tamaño de palabra
    addi $t2, $t2, 1   # incrementa el contador de columnas
    
    # verifica si se han impreso todas las columnas
    bne $t2, 6, column_loop   # columnas + 1 (por el espacio)
    
    la $a0, newline           # imprime una nueva línea después de cada fila
    li $v0, 4
    syscall
    
    addi $t0, $t0, 1  # incrementa el contador de filas
    
    # verifica si se han impreso todas las filas
    bne $t0, 3, print_loop
    
    li $v0, 10        # llamada al sistema para salir
    syscall

