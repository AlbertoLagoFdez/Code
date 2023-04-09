// AUTOR: Alberto Lago Fernández
// FECHA: 28/03/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLL_NODET_H_
#define SLL_NODET_H_

#include <iostream>

// Clase para nodos de listas enlazadas
template <class T> class sll_node_t {
  //parte publica de la clase sll_node_t
 public:
  // constructores
  sll_node_t(void) : data_(), next_(NULL) {}  // constructor por defecto
  sll_node_t(const T& data) : data_(data), next_(NULL) {} // constructor

  // destructor
  ~sll_node_t(void) {};

  // getters & setters
  //getter y setter del atributo next_
  sll_node_t<T>* get_next(void) const { return next_; }
  void set_next(sll_node_t<T>* next) { next_ = next; }

  //getter y setter del atributo data_
  const T& get_data(void) const { return data_; }
  void set_data(const T& data) { data_ = data; }

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

//parte privada de la clase sll_node_t
 private:
  T data_;
  sll_node_t<T>* next_;
};


// E/S
//metodo para imprimir por pantalla
template <class T> std::ostream& sll_node_t<T>::write(std::ostream& os) const  {
  os << data_;
  return os;
}

#endif  // SLL_NODET_H_
