#include <iostream>
using namespace std;

class complex_t
{
    public:
     complex_t(const int a = 1.0, const int b = 1.0);
     ~complex_t();
     void write();
     complex_t suma(const complex_t& n);
     complex_t resta(const complex_t& n);
     complex_t producto(const complex_t& n);
     complex_t division(const complex_t& n);
    private:
     double a_;
     double b_;
};