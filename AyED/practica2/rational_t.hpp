// AUTOR: Alberto Lago Fernandez
// FECHA: 2/3/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
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
//atributos publicos de la classe rational_t
public:
//constructor y constructor por defecto
  rational_t(const int = 0, const int = 1);
//destructor
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

//metodo value que devuelve el valor del racional y es constante
  double value(void) const;
//metodo que devuelve el opuesto de un numero racional
  rational_t opposite(void) const;
//metodo que devuelve el reciprocuo de un numero racional
  rational_t reciprocal(void) const;

//metodo que comprueba que dos racionales son iguales
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
//metodo que comprueba que un racional es mayor que otro
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
//metodo que comprueba que un racional es menor que otro
  bool is_less(const rational_t&, const double precision = EPSILON) const;

//metodo que suma dos racionales
  rational_t add(const rational_t&) const;
//metodo que resta dos racionales
  rational_t substract(const rational_t&) const;
//metodo que multiplica deos racionales
  rational_t multiply(const rational_t&) const;
//metodo  que divide ds racionales
  rational_t divide(const rational_t&) const;

//metodo que imprime un racional
  void write(ostream& os = cout) const;
//metodo que lee un racional
  void read(istream& is = cin);

//atributos privados de la clase rational_t  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

