    .data
Titulo: .asciiz "\nEvaluacion polinomio f(x)= ax^3+bx^2+cx+d en un intervalo [r,s]\n"
P1:     .asciiz "\nIntroduzca los valores de a,b,c y d (separados por retorno de carro): \n"
P2:     .asciiz "\nIntroduzca [r,s] (r y s enteros, r <= s) (separados por retorno de carro): \n" 
End:    .asciiz "\n\nTermina el programa\n"
    .text
main:
# print string Titulo:
    li $v0,4
    la $a0,Titulo
    syscall
#print string P1:
    li $v0,4
    la $a0,P1
    syscall
#pido las variables a, b, c y d
#pido un flotante -> a
    li $v0,6
    syscall

    mov.s $f20,$f0
#pido un flotante -> b
    li $v0,6
    syscall

    mov.s $f22,$f0
#pido un flotante -> c
    li $v0,6
    syscall

    mov.s $f24,$f0
#pido un flotante -> d
    li $v0,6
    syscall

    mov.s $f26,$f0
do:
# print string P2:
    li $v0,4
    la $a0,P2
    syscall
#pideo un entero -> r
    li $v0,5
    syscall
    move $s0,$v0
#pideo un entero -> s
    li $v0,5
    syscall
    move $s1,$v0
# while(r>s)
    bgt $s0,$s1,do
#for(int x = r; x <= s; x++){
# x -> $
#float f = a*x*x*x+b*x*x+c*x+d
#if (f>= 2.1) { 
#cout << "\nf(" << x << ") = " << f;
#}
#}
#cout << end: