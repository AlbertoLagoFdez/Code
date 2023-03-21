# Autor:
# Correo electrónico:
# Fecha: 

##include<iostream>
##include<cmath>

#int main(void) {
#    std::cout << "\n\nAproximación a sen(x) (-1 <= x <= 1) con un error máximo, usando Taylor\n";
#    do {
#    	double x;
#        do {
#        std::cout << "\n\nIntroduzca el valor de x (-1 <= x <= 1): ";
#        std::cin >> x;
#        } while ( (x < -1) || (x > 1));
#        double error;
#        do {
#            std::cout << "\nIntroduzca el error maximo permitido en la aproximación (0 < error < 1) (error <= 0 sale del programa): ";
#            std::cin >> error;
#        } while (error >= 1);
#        if (error <= 0) break;
#        int n = 0; // iteraciones
#        double numerador = x; // primer numerador del termino para n=0
#        int denominador = 1; // primer denominador del termino para n=0
#        int signo = 1;
#        double sen_x = x; // primer termino
#        double xx = x*x; // el numerador siempre se multiplica por x^2 
#        double error_calculado;
#        do {
#            double old_senx = sen_x;
#            n++; // incremento el termino
#            signo = -signo; // el signo se alterna
#            numerador *= xx; 
#            denominador = (2*n+1) * 2*n * denominador;
#            double termino = signo * numerador / denominador; // ultimo termino
#            sen_x += termino;
#            error_calculado = fabs((sen_x - old_senx) / sen_x);
#        } while (error_calculado >= error);
#        std::cout << "\n\n\nsen(x) calculado: " << sen_x;
#        std::cout << "\nerror calculado: " << error_calculado;
#        std::cout << "\nnumero de iteraciones calculadas: " << n;
#    } while (true);
#    std::cout << "\nFin del programa\n";
#    return 0;
#}

    .data
titulo: .asciiz "\n\nAproximación a sen(x) (-1 <= x <= 1) con un error máximo, usando Taylor\n"
petx:   .asciiz "\n\nIntroduzca el valor de x (-1 <= x <= 1): "
pete:   .asciiz "\nIntroduzca el error maximo permitido en la aproximación (0 < error < 1) (error <= 0 sale del programa): "
cadsen: .asciiz "\n\n\nsen(x) calculado: "
caderr: .asciiz "\nerror calculado: "
cadite: .asciiz "\nnumero de iteraciones calculadas: "
cadfin: .asciiz "\nFin del programa\n"
    
    .text
main:
        #imprimir por pantalla titulo
        li $v0,4
        la $a0,titulo
        syscall
#do1{ while(true){}
do1:
do2:
#imprimir por pantalla petx
        li $v0,4
        la $a0,petx
        syscall
#pedir por pantalla x -> $f20
        li $v0,3
        syscall
        mov.d $f20,$f0
#while(x<-1 || x>1)
        li.d $f6,-1.0
        c.lt.d $f20,$f6
        bc1t do2
        li.d $f6,1.0
        c.lt.d $f20,$f6
        bc1f do2
do3:
#imprimir por pantalla pete
        li $v0,4
        la $a0,pete
        syscall
#pedir el error -> $f22
        li $v0,3
        syscall
        mov.d $f22,$f0
#while(error >= 1);
        li.d $f6,1.0
        c.lt.d $f22,$f6
        bc1f do3
#if (error <= 0) break; 
        li.d $f6,0.0
        c.le.d $f22,$f6
        bc1f outProgram
#int n = 0; n -> $s0
        li $s0,0
#double numerador = x; numerador -> $f24
        mov.d $f24,$f20
#int denominador = 1; denominador -> $s1
        li $s1,1
#int signo = 1; signo -> $s2
        li $s2,1
#double sen_x = x; sen_x -> $f26
        mov.d $f26,$f20
#double xx = x*x; xx -> $f28
        mul.d $f28,$f20,$f20
#double error_calculado -> $f30
do4:
#double old_senx = sen_x; old_senx -> $f4
        mov.d $f4,$f26
#n++
        addi $s0,1
#signo = -signo
        mul $s3,$s2,-1
#numerador *= xx
        mul.d $f24,$f24,$f28
#denominador = (2*n+1) * 2*n * denominador;$s1,$s0,
        mul $t0,$s0,2
        mul $t1,$s0,$t1
        add $t2,$t0,1
        mul $s1,$t1,$t2
#double termino = signo * numerador / denominador;
        mtc1 $s3,$f6
        cvt.d.w $f6,$f6
        mul.s $f30,$f6,$f24

        mtc1 $s1,$f8
        cvt.d.w $f8,$f8
        div.s $f30,$f30,$f8
#sen_x += termino;
        add.s $f26,$f26,$f30
#error_calculado = fabs((sen_x - old_senx) / sen_x);
        sub.s $f31,$f26,$f4
        div.s $f21,$f31,$$f26

        c.lt.s $f21,0.0
        bc1f fabs
        li.s $f5,-1.0
        mul.s $f21,$f5
fabs:
        c.lt.s $f21,$f22
        bc1f do2

        



outProgram:
        li $v0,10
        syscall
