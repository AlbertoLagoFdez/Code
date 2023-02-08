#include <iostream>

int main() {
    int número;
    std::cout << "Introduzca un número: ";
    std::cin >> número;
    if(número % 2 == 0) {
        std::cout << "Su número es par." << std::endl;
    } else {
        std::cout <<"Su número es impar." << std::endl;
    }
    return 0;
}