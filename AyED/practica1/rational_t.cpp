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

#include "rational_t.hpp"

// constructor por defecto 
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
// getter para adquirir el num_
int
rational_t::get_num() const
{
  return num_;
}


// getter para adquirir el den_
int
rational_t::get_den() const
{
  return den_;
}


// setter para darle valor al num_
void
rational_t::set_num(const int n)
{
  num_ = n;
}


// seeter para darle varlo al den_  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// metodo para mostrar el valor de un racional que devuelve un double
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones
// metodo que compara si un racional es igual a otro que devuelve un booleano
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
  return fabs(value() - r.value()) < EPSILON; 
}


// metodo que compara si un racional es mayor a otro que devuelve un booleano
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return value() - r.value() > EPSILON;
}


// metodo que compara si un racional es menor a otro que devuelve un booleano
bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.value() - value() > EPSILON;
}


// operaciones
// metodo para sumar dos racionales que duelve un racional
rational_t
rational_t::add(const rational_t& r)
{
  return rational_t{((num_*r.den_)+(r.num_*den_)),(den_*r.den_)};
}


// metodo para restar dos racionales que duelve un racional
rational_t
rational_t::substract(const rational_t& r)
{
  return rational_t{((num_*r.den_)-(r.num_*den_)),(den_*r.den_)};
}


// metodo para multiplicar dos racionales que duelve un racional
rational_t
rational_t::multiply(const rational_t& r)
{
  return rational_t{num_*r.num_,den_*r.den_};
}


// metodo para dividir dos racionales que duelve un racional
rational_t
rational_t::divide(const rational_t& r)
{
  return rational_t{num_*r.den_,den_*r.num_};
}

void rational_t::natural()
{
  if(num_ % den_ == 0)
  {
    cout << "Es entero." << endl;
  }
  else
  {
    cout << "No es entero." << endl;
  }
}

// E/S
// metodo para imprimir un racional por pantalla
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// metodo para leer un racional por pantalla
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

