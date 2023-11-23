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
#include <time.h>

std::vector<double> GenerateVector(const int size, const double lower, const double upper) {
  std::vector<double> result;
  result.resize(size);
  std::cout << result.size();
  std::srand(time(nullptr));
  for (long unsigned int i = 0; i < result.size() ; i++) {
    double random_double = lower + (upper - lower) * (random() % RAND_MAX) / RAND_MAX;
    result.push_back(random_double);
  }
  return result;
}

int main() {
  std::vector<double> my_vector = GenerateVector(30, 5.0, 10.0);
  for (const auto& value: my_vector) {
    std::cout << "Component: " << value << std::endl;
  }
  return 0;
}