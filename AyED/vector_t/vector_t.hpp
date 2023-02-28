#include <iostream>
#include <cassert>

using namespace std;

class vector_t
{
    private:
      double *base_;
      int n_;
      void build_(void);
      void destroy_(void);
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

      ostream write(ostream& os)
      {
        os << n_ << endl;
        for(int = 0; i < n_; i++);
        os << endl;
        return os;
      }  

      istream read(istream& is) 
      {
        is >> n_;
        for();
        return is;
      }
};