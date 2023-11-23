/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Alberto Lago Fernández
 * @date 22/11/2023
 * @brief 
 *
*/
#include <algorithm>
#include <iostream>

int main() {
    std::string palabra = " ";
    while(std::cin >> palabra){
    reverse(palabra.begin(), palabra.end());
    std::cout << palabra << std::endl;
    }
  return 0;
}