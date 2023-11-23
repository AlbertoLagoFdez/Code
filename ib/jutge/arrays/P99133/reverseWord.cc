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
#include <vector>

int main() {
  std::string palabra;
  int knumero_palabras;
  std::cin >> knumero_palabras;
  std::vector<std::string> words(knumero_palabras);
  for (int i = knumero_palabras - 1; i >= 0; --i) {
    std::cin >> palabra;
    words[i] = palabra;
  }
  for (int j = 0; j < knumero_palabras; ++j) {
    palabra = words[j];
    reverse(palabra.begin(), palabra.end());
    std::cout << palabra << std::endl;
  }
  return 0;
}