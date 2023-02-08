/**
 * @AlbertoLagoFdez
 * @brief programa que pruba letras aleatorias hasta imprimir helloworld
*/


#include <iostream>
#include <random>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    char randomletter = std::rand();
    std::string cadenafinal{"hello world"}, cadena;
    for(int i{0}; i < cadenafinal.size(); i++) {
        cadena[i] += std::rand();
        while(cadena[i] != cadenafinal[i]){
            cadena[i] += std::rand();
            std::cout << cadena[i];
        }
    }
}