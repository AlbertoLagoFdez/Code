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

bool is_palindrome(const std::string &s) {
  int palin = s.length() - 1;
  for (int i = 0; i <= palin; ++i) {
    if (s[i] != s[palin])
      return false;
    --palin;
  }
  return true;
}

int main() {
  std::string palindromo;
  while (std::cin >> palindromo) {
    std::cout << is_palindrome(palindromo) << std::endl;
  }
  return 0;
}