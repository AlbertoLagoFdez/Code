    .data
Titulo:     .asciiz     "\nEvaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s]\n"
P1:         .asciiz     "\nIntroduzca los valores de a,b,c y d (separados por retorno de carro): \n"
P2:         .asciiz     "\nIntroduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro): \n" 
End:        .asciiz     "\n\nTermina el programa\n"
funcion1:   .asciiz     "\nf("
funcion2:   .asciiz     ") = "
comp:       .float     2.1

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
        move $s2,$s0            #x = r (entero)
for:   
        bgt $s2,$s1,forFin
#float f = a*x*x*x+b*x*x+c*x+d
        mtc1 $s2,$f4
        cvt.s.w $f6,$f4

        mov.s	$f28, $f26		#f=d

	mul.s	$f8, $f24, $f6		#$f8 = c*x
        add.s	$f28, $f28, $f8		#f= f+ $f28 = f+ c*x

	mul.s	$f10, $f6, $f6		#$f10 = x*x
	mul.s	$f16, $f22, $f10	#$f16 = b * $f10= b*x*x
	add.s	$f28, $f28, $f16	#f= f + $f16 = f+ b*x*x

	mul.s	$f10, $f10, $f6		#$f10 = $f10 * x= x*x*x
	mul.s	$f16, $f20, $f10	#$f16 = a* $f10 = a*x*x*x
	add.s	$f28, $f28, $f16	#f = f+$f16 = f + a*x*x*x

#if (f>= 2.1) { 
        l.s $f8,comp
        c.lt.s $f28,$f8         #si f < 2.1 va al outIf;
        bc1t outIf
#print string "f("
        li $v0,4
        la $a0,funcion1
        syscall
#cambiar de float a entero
#print float x     
        li $v0,2
        mov.s $f12,$f6
        syscall
#print string ") = "
        li $v0,4
        la $a0,funcion2
        syscall
#print float f
        li $v0,2
        mov.s $f12,$f28
        syscall
outIf:
        addi $s2,$s2,1
        b for
forFin:
#print string End:
        li $v0,4
        la $a0,End
        syscall

        li $v0,10
        syscall