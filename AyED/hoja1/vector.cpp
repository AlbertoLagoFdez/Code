#include <iostream>

int main() {
    int vector[] = {1,2,3,4,5,6,7};
    int *ptri, *ptrf, aux;
    ptri = vector;
    ptrf = vector + 6;

    while (ptri < ptrf) {
        aux = *ptri;
        *ptri = *ptrf;          //se intercambian los valores
        *ptrf = aux;
        ptri++;                 //se incrementa una posicion
        ptrf--;                 //se resta una posicion
    }
    for (int i{0}; i < 7; i++) {
        std::cout << vector[i];
    }
    std::cout << std::endl;
}