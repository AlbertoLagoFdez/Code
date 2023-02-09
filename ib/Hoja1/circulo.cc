#include <iostream>
#include <cmath>

double perimetro(double radio) {
    double perimetro{2 * M_PI * radio};
    return perimetro;
}

double area(double radio) {
    double area{M_PI * pow(radio,2)} ;
    return area;
}

int main() {
    double radio{};
    std::cout << "Introduzca un radio: ";
    std::cin >> radio;
    std::cout << "Perímetro: " << perimetro(radio) << std::endl;
    std::cout << "Área: " << area(radio) << std::endl;
    return 0;
}