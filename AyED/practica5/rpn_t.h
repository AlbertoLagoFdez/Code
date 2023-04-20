// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      //poner codigo
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {

      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  // poner código
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  
  int aux1, aux2;
  
  if(c == 'r' || c == 'l' || c == 'c')
  {
    aux1 = stack_.top();
    std::cout << "   Sacamos de la pila un operando: " << aux1 << std::endl;
    stack_.pop();
  }
  else
  {
  aux1 = stack_.top();
  std::cout << "   Sacamos de la pila un operando: " << aux1 << std::endl;
  stack_.pop();

  aux2 = stack_.top();
  std::cout << "   Sacamos de la pila otro operando: " << aux2 << std::endl;
  stack_.pop();
  }

  int resultado;
  switch (c) {
    case '+':
      resultado = aux1 + aux2;
      break;
    
    case '-':
      resultado = aux2 - aux1;
      break;

    case '*':
      resultado = aux1 * aux2;
      break;

    case '/':
      resultado = aux1 / aux2;
      break;

    case '^':
      resultado = pow(aux1, aux2);
      break;

    case 'r':
      resultado = sqrt(aux1);  
      break;

    case 'l':
      resultado = log(aux1);
      break;

    case 'c':
      resultado = pow(aux1,2);
      break;
    // poner código resto de operadores
  }

  stack_.push(resultado);

  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}

 
#endif  // RPNT_H_
