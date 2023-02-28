#include "complex_t.hpp"

complex_t::complex_t(const int a,const int b)
{
    a_ = a;
    b_ = b;
}

void complex_t::write()
{
    cout << "(" << a_ << "," << b_ << ")" << endl;
}

complex_t complex_t::suma(const complex_t &n)
{
    return complex_t(a_ + n.a_ , b_ + n.b_);
}

complex_t complex_t::resta(const complex_t& n)
{
    return complex_t(a_ - n.a_ , b_ - n.b_);
}

complex_t complex_t::producto(const complex_t &n)
{
    return complex_t((a_*n.a_)-(b_*n.b_),(a_*n.b_)+(b_*n.a_));
}

complex_t complex_t::division(const complex_t &n)
{
    return complex_t();
}
