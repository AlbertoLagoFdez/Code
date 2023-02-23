// AUTOR: Alberto Lago Fernandez
// FECHA: 16/02/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
  // atributos publicos de la clase racional
public: 
  // constructor por defecto.
  rational_t(const int = 0, const int = 1);
  // destructor
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);
  // metodo value que devuelve el valor del racional
  double value(void) const;

  // FASE II
  // metodo que compara si dos racionales son iguales
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  // metodos que comparan si un racional es mayor o menor que el otro.
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  // metedo para sumar 2 racionales
  rational_t add(const rational_t&);
  // metodo para restar 2 racionales
  rational_t substract(const rational_t&);
  // metodo para multiplicar 2 racionales
  rational_t multiply(const rational_t&);
  // metodo para dividir 2 racionales
  rational_t divide(const rational_t&);
  
  //metodo para escribir por pantalla el racional
  void write(ostream& = cout) const;
  //metodo para leer un racional
  void read(istream& = cin);
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  //atributos privados de la clase racional, numerador y denominador
  int num_, den_;
};
