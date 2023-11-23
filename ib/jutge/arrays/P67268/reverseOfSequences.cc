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
#include <iostream>
#include <vector>

int main() {
  int knumero{0};
  while (std::cin >> knumero) {
    std::vector<int> v(knumero);
    for (int i = 0; i < knumero; ++i) {
      std::cin >> v[i];
    }
    int aux;
    for (int j = 0; j < knumero / 2; ++j) {
      aux = v[j];
      v[j] = v[knumero - j - 1];
      v[knumero - j - 1] = aux;
    }
    for (int k = 0; k < knumero; ++k) {
      std::cout << v[k];
      if (k != knumero - 1)
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}