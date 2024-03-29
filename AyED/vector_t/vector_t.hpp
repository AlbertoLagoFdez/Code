#include <iostream>
#include <cassert>

using namespace std;

class vector_t
{
    public:
    //constructor, copia y destructor
      vector_t(const int n = 0);
      vector_t(const vector_t& v);
      ~vector_t();
    //METODOS
      void resize(const int n);
      int get_size() const { return n_; }
      
      double at(const int i) const;
      double at(const int i);

      double operator[] (const int i ) const;
      double operator[] (const int i );

      ostream& write (ostream& = cout) const; 
      istream& read (istream& = cin);

    private:
      double *base_;
      int n_;
      void build_(void);
      void destroy_(void);
};