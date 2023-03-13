#include <iostream>
#include <cassert>

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t
{
private:
  int n_;
  int nz_;
  pair_vector_t pv_;
public:
  sparse_vector_t(const vector_t<double>& v, const double eps = EPS)
  {
    n_ = v.get_size();
    //(1) recorrer v y contar el numero de elementos != 0; hay que usar una funcion especial.
    //(2) redimensoinar pv_ al tamaño nz_
    //(3) recorrer v_ y almacenar los elementos != 0 en pv_ { indice al valor sucesivamenteç}    
  }

  sparse_vector_t(const sparse_vector_t& sv) // me copio sin ser nada
  {   
    *this = sv; //invoca a operator=
  }

  sparse_vector_t operator=(const sparse_vector_t& sv) // me copio siendo algo
  {
    n_ = sv.n_;
    nz_ = sv.nz_;
    pv_ = sv.pv_;    // ese = -> vector_t::operator=
    return *this;
  }
  
  ~sparse_vector_t() {}

  int get_n() const { return n_;}
  int get_nz() const { return nz_;}
  pair_double_t& at(const int i)
  {
    assert(i >= 0 && i < get_nz());
    return pv[i];
  }
  pair_double_t operator[](const int i)
  {
    return at(i);
  }

};