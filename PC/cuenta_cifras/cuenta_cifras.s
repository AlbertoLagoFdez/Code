#/*
#Enunciado:
#Realizar un programa que haga lo siguiente:
#1) Pedir al usuario que introduzca por teclado dos números enteros x y c.
#2) comprobar que x es mayor o igual que cero, y que c es mayor o igual que cero y menor o igual que nueve.
#3) Si se cumple la condición descrita en el punto 2, el programa debe contar el número de veces que 
#   aparece la cifra c, en el número x, mostrar el resultado por pantalla y volver al punto 1.
#4) Si no se cumple la condición descrita en el punto 2, el programa debe finalizar.

#Por ejemplo si el usuario introduce como x el valor 12242 y como c el valor 2, 
#debe imprimir por la pantalla el número 3 (que es las veces que aparece 2 en 12242).
#*/

#	Cadena de caracteres
	.data
Titulo:	  .asciiz	"Este programa cuenta el numero de veces que aparece una cifra en un numero entero positivo.\n"
Pet1:     .asciiz "Introduzca un numero entero positivo (introduzca negativo para finalizar el programa): "
Pet2:     .asciiz "Introduzca la cifra (0-9, introduzca otra cosa para finalizar el programa): "
str_num:  .asciiz "El numero de veces que aparece la cifra en el numero es: "
endl:     .asciiz "\n"
str_fin:  .asciiz "Fin del programa.\n"


##include <iostream>
#int main() {
  .text
main:
  
#    int x, c;
#    int cuenta = 0;
  move $s2, $zero

#    while (true) {
while:

#        std::cout << "Este programa cuenta el numero de veces que aparece una cifra en un numero entero positivo.\n";
  la $a0, Titulo
  li $v0, 4
  syscall
#        std::cout << "Introduzca un numero entero positivo (introduzca negativo para finalizar el programa): ";
  la $a0, Pet1
  li $v0, 4
  syscall
#        std::cin >> x;
  li $v0, 5
  syscall
  move $s0, $v0
#        if (x < 0) break;
  bltz $s0, whilefin
#        std::cout << "Introduzca la cifra (0-9, introduzca otra cosa para finalizar el programa): ";
  la $a0, Pet2
  li $v0, 4
  syscall
#        std::cin >> c;
  li $v0, 5
  syscall
  move $s1, $v0
  
#        if ((c < 0) || (c > 9)) break;
  bltz $s1, whilefin
  bgt  $s1, 9, whilefin
  
#        cuenta = 0;
  move $s2, $zero
#        int resto;
#        while ( x != 0 ) {
while2: beqz $s0, while2fin
#            resto = x % 10;
#            x /= 10;
  li  $t1, 10
  div $s0, $t1
  mflo $s0
  mfhi $t0
  
#            if ( resto == c ) cuenta++;
  bne $t0, $s1, if_fin
  addi $s2, $s2, 1
if_fin:
  b while2
#        }

while2fin:
#        std::cout << "El numero de veces que aparece la cifra en el numero es: " << cuenta << std::endl;
  la $a0, str_num
  li $v0, 4
  syscall
  move $a0, $s2
  li $v0, 1
  syscall
  la $a0, endl
  li $v0, 4
  syscall
  b while
  
#    }
whilefin:

#    std::cout << "Fin del programa.\n";
  la $a0, str_fin
  li $v0, 4
  syscall

#    return 0;
#}
  li $v0, 10
  syscall

# Tabla de datos
# 
# x       ->    $s0
# c       ->    $s1
# cuenta  ->    $s2
# resto   ->    $t0
