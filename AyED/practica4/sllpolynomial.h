// AUTOR: Alberto Lago Fernandez
// FECHA: 28/03/2023
// EMAIL: alu0101562247@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
  //parte publica del SllPolynomial
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  //metodo para imprimir por pantalla
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  //modificacion inventada
  void Resta(const SllPolynomial&, SllPolynomial&, const double= EPS);
  void mulEsca(int num, SllPolynomial&, const double= EPS);
  SllPolynomial posPar();
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor de la clase SllPolynimial
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for(int i = v.get_size() -1; i>=0; i--)
  {
    if(IsNotZero(v.get_val(i)))
    {
      pair_double_t SandroDinamita (v.get_val(i), i);
      sll_node_t<pair_double_t>* n;
      n = new sll_node_t<pair_double_t> (SandroDinamita);
      push_front(n);
    }
  }
}

// E/S
//Metodo para imprimir por pantalla
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
  
}

//sobrecarga del operador << 
std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux = get_head();
  while(aux != NULL) 
  {
    result = result + (aux ->get_data().get_val() * pow(x, aux->get_data().get_inx()));
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {
  bool differents = false;
  SllPolyNode* Paco = get_head();
  SllPolyNode* Peña = sllpol.get_head();
  while( Paco != NULL && Peña != NULL)
  {
    if(Paco->get_data().get_val() != Peña->get_data().get_val())
    {
      differents = true;
    }
    Paco = Paco->get_next();
    Peña = Peña->get_next();
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) 
{
  sll_node_t<pair_double_t>* Paco = get_head();
  sll_node_t<pair_double_t>* Manolo = sllpol.get_head();
  SllPolynomial sllpolsumcopi;
  while (Paco != NULL || Manolo != NULL) 
  {
    if (Paco == NULL) 
    {                                              
      while (Manolo != NULL) 
      {
        pair_double_t hijo(Manolo->get_data().get_val(), Manolo->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Manolo = Manolo->get_next();
      }
      break;
    } 
    else if (Manolo == NULL) 
    {
      while (Paco != NULL) 
      {
        pair_double_t hijo(Paco->get_data().get_val(), Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
      }
      break;
    } 
    else 
    {
      if (Paco->get_data().get_inx() == Manolo->get_data().get_inx()) 
      {
        double val = Paco->get_data().get_val() + Manolo->get_data().get_val();
        if (val < eps && val > -eps) 
        {
          Paco = Paco->get_next();
          Manolo = Manolo->get_next();
        }
        pair_double_t hijo(val, Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
        Manolo = Manolo->get_next();
      } 
      else if (Paco->get_data().get_inx() > Manolo->get_data().get_inx()) 
      {
        pair_double_t hijo(Manolo->get_data().get_val(), Manolo->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Manolo = Manolo->get_next();
      } 
      else 
      {
        pair_double_t hijo(Paco->get_data().get_val(), Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
      }
    }
  }
  sll_node_t<pair_double_t>* aux = sllpolsumcopi.get_head();
  while (aux != NULL)
  {
    pair_double_t suma(aux->get_data().get_val(), aux->get_data().get_inx());
    sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(suma);
    sllpolsum.push_front(n);
    aux = aux->get_next();
  }
}



//MODIFICACIONES
void SllPolynomial::Resta(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) 
{
  sll_node_t<pair_double_t>* Paco = get_head();
  sll_node_t<pair_double_t>* Manolo = sllpol.get_head();
  SllPolynomial sllpolsumcopi;
  while (Paco != NULL || Manolo != NULL) 
  {
    if (Paco == NULL) 
    {                                              
      while (Manolo != NULL) 
      {
        pair_double_t hijo(Manolo->get_data().get_val(), Manolo->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Manolo = Manolo->get_next();
      }
      break;
    } 
    else if (Manolo == NULL) 
    {
      while (Paco != NULL) 
      {
        pair_double_t hijo(Paco->get_data().get_val(), Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
      }
      break;
    } 
    else 
    {
      if (Paco->get_data().get_inx() == Manolo->get_data().get_inx()) 
      {
        double val = Paco->get_data().get_val() - Manolo->get_data().get_val();
        if (val < eps && val > -eps) 
        {
          Paco = Paco->get_next();
          Manolo = Manolo->get_next();
        }
        pair_double_t hijo(val, Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
        Manolo = Manolo->get_next();
      } 
      else if (Paco->get_data().get_inx() > Manolo->get_data().get_inx()) 
      {
        pair_double_t hijo(Manolo->get_data().get_val(), Manolo->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Manolo = Manolo->get_next();
      } 
      else 
      {
        pair_double_t hijo(Paco->get_data().get_val(), Paco->get_data().get_inx());
        sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(hijo);
        sllpolsumcopi.push_front(n);
        Paco = Paco->get_next();
      }
    }
  }
  sll_node_t<pair_double_t>* aux = sllpolsumcopi.get_head();
  while (aux != NULL)
  {
    pair_double_t suma(aux->get_data().get_val(), aux->get_data().get_inx());
    sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(suma);
    sllpolsum.push_front(n);
    aux = aux->get_next();
  }
}

SllPolynomial SllPolynomial::posPar()
{
  SllPolynomial posicionPar, resultado;
  sll_node_t<pair_double_t>* aux = get_head();
  while( aux != NULL)
  {
    if(aux->get_data().get_inx() % 2 == 0)
    {
      pair_double_t pos(aux->get_data().get_val(), aux->get_data().get_inx());
      sll_node_t<pair_double_t>* n = new sll_node_t<pair_double_t>(pos);
      posicionPar.push_front(n);
    }
  aux = aux->get_next();
  }
  sll_node_t<pair_double_t>* aux2 = posicionPar.get_head(); 
  while (aux2 != NULL)
  {
    pair_double_t posi(aux2->get_data().get_val(), aux2->get_data().get_inx());
    sll_node_t<pair_double_t>* n1 = new sll_node_t<pair_double_t>(posi);
    resultado.push_front(n1);
    aux2 = aux2->get_next();
  }
  

  return resultado;
}

#endif  // SLLPOLYNOMIAL_H_
