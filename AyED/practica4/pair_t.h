// AUTOR: Alberto Lago Fernández
// FECHA: 28/03/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
//parte publica de la clase pair_t
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;
//parte privada de la clase pair_t
 private:
  T val_;
  int inx_;
};


//constructor por defecto
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

//constructor
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

//destructor
template<class T> pair_t<T>::~pair_t() {}

//setter
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

//getter del atributo inx_
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

//getter del atributo val_
template<class T> T pair_t<T>::get_val() const {
  return val_;
}

//metodo para leer por pantalla
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

//metodo para imprimir por pantalla
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

//sobrecarga del operador <<
template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
