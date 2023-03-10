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


using namespace std;

template<class T>
class vector_t
{
//Atributos publicos de la clase vector_t
public:
//Constructor y contructor por defecto
  vector_t(const int = 0);
//destructor
  ~vector_t();

//metodo resize para volver a crear de cero un objeto de la clase vector_t
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

//metodo para imprimir por pantalla un objeto de la clase vector_t
  void write(ostream& = cout) const;
//metodo para leer un objeto de la clase vector_t
  void read(istream& = cin);

//atributos privados de la clase vector_t
private:
  T *v_;
  int sz_;
  
//metodo para construir un objeto de la clase vector_t
  void build(void);
//metodo para destruir un objeto de la clase vector_t
  void destroy(void);
};


//constructor 
template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}


//destructor
template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}


//metodo para construir un objeto de la clase vector_t
template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}


//metodo para destruir un objeto de la clase vector_t
template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}


//metodo resize que destruye y vuelve a contruir un obeto de la clase vector_t
template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}


//getter
template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


//getter
template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}


//setter
template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}


//getter-setter
template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


//getter-setter
//La sobrecarga del operador [] sirve para acceder a los elementos de la clase utilizando los corchetes.
template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}


//getter-setter constante
template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


//getter-setter constante
template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}


//metodo para imprimir un objeto de la clase vector_t
template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}


//metodo para leer un objeto de la clase vector_t
template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  assert(v.get_size() == w.get_size());
  T res;
  for(int i = 0; i < v.get_size(); i++)
  {
    res = res + v.at(i)*w.at(i);
  }
  return res;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  assert(v.get_size() == w.get_size());
  double res;
  for(int i = 0; i < v.get_size(); i++)
  {
    res = res + (v.at(i) * w.at(i)).value();
  }
  return res; 
}
