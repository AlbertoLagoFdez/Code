// AUTOR: Alberto Lago Fernandez
// FECHA: 2/3/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public: //Atributos y métodos públicos
//Constructor por defecto
  matrix_t(const int = 0, const int = 0);
  //Destructor
  ~matrix_t();
  //Método para colocar el tamaño de la matriz
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;

  vector_t<T> SumaMatrizSec();

  vector_t<T> SumaFilasPares() const;

  matrix_t<T> traspuesta();
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);
  //Método para escribir por pantalla y leer por teclado respectivamente
  void write(ostream& = cout) const;
  void read(istream& = cin);
//Atributos privados
private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};




//Plantilla de  constructor de la clase matrix_t
template<class T> matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


//Plantilla del destructor de matrix_t
template<class T> matrix_t<T>::~matrix_t() {}


//Plantilla de metodo para cambia el tamaño de la matriz
template<class T> void matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


//Plantilla de getter de las filas
template<class T> inline int matrix_t<T>::get_m() const
{
  return m_;
}


//Plantilla de getter de las columnas
template<class T> inline int matrix_t<T>::get_n() const
{
  return n_;
}


//Plantilla que comprueba que las filas y las columnas concuerden con la matriz, devuelve la posición del vector utilizando el método pos()
template<class T> T& matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


//Sobrecarga del operador()
//La sobrecarga de operador () sirve para acceder a los elementos de la clase utilizando los parentesis.
template<class T> T& matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}


//Plantilla que comprueba que las filas y columnas sean correctas y retorne la posición.
template<class T> const T& matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


//sobrecarga del operador () para que puedas utilizar (i, j)para accedes a una posición de la matriz
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}


//Plantilla para escribir en pantalla la matriz
template<class T> void matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}


//Plantilla para leer desde teclado las filas y las columnas
template<class T> void matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

//Plantilla del método apra calcular la posición vectorial de cada numero de la matriz
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_m() ==  B.get_n());
  resize(A.get_m(), B.get_n());
  //matrix_t<T> C[A.get_m()][B.get_n()];

  for (int i = 1; i < A.get_n(); ++i)
  {
    for (int j = 1; j < B.get_m(); ++j)
    {
    T sum = 0;
    for(int k = 1; k <= A.get_n(); ++k)
    {
      sum = sum + (A(i, k) * B(k, j));
    }
    at(i,j) = sum;   
    }
  }
}

template <class T>
vector_t<T> matrix_t<T>::SumaMatrizSec()
{
vector_t<T> resultado;
resultado.resize(1);
int k = 0;
  for(int i = m_  ; i > 0 ; --i)
  {
    for (int j  = 1 ; j <= m_; ++j )
    {
      if ( j != i)
      {
      resultado.at(k) = resultado.at(k) + at(i, j); 
      }
    }
  }
  return resultado;
}

//Sumar filas pares
template<class T>
vector_t<T> matrix_t<T>::SumaFilasPares() const{
  vector_t<T> vector_resultado;
  vector_resultado.resize(get_m() / 2);
  for(int i = 1; i<= get_m(); ++i)
  {
    if(i % 2 == 0)
    {
      int k= 0;
      for(int j = 1; j <= get_n(); ++j)
      {
        vector_resultado.at(k) = vector_resultado.at(k) + at(i, j);
      }
      k++;
    }
  }
  return vector_resultado;
}

/*
//traspuesta
template <class T>
matrix_t<T> matrix_t<T>::traspuesta()
{
  matrix_t<T> C;
  C.resize(get_n(),get_m());
  for(int i = 1; i < get_m(); ++i)
  {
    for(int j = 1; j < get_n(); ++j)
    {
      C.at(i,j) = at(j, i);
    }
  } 
  return C;
}
*/
