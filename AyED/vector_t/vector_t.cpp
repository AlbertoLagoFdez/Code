#include "vector_t.hpp"

void vector_t::build_(void)
{
}

void vector_t::destroy_(void)
{
}

vector_t::vector_t(const int n)
{
    n_ = n;
    base_ = new double[n_];
    assert(base_ != NULL);
}

vector_t::vector_t(const vector_t& v)
{
    n_ = v.n_;
    //resize
    for (int i=0;i<n_;++i)
    {
        //at(i)=v.at(i); //at(i)=v.at[i]
    }
}

vector_t::~vector_t()
{
    if (base_ != NULL)
    {
        delete[]base_;
        base_=NULL;
    }
}

void vector_t::resize(const int n)
{
    //destroy_();
    n_ = n;
    //build();
}

double vector_t::at(const int i) const
{
    assert(i >= 0 && i <n_);
    return base_[i];
}

double vector_t::at(const int i)
{
    assert(i >= 0 && i < n_);
    return base_[i];
}

double vector_t::operator[](const int i) const
{
    return at(i);
}

double vector_t::operator[] (const int i)
{
    return at(i);
}

ostream& vector_t::write(ostream& os) const
{
    os << get_size() << endl;
    for(int i = 0; i < get_size(); i++)
    {
        os << at(i) << " ";
    } 
    os << endl;
    return os;
}

istream& vector_t::read(istream& is)
{
    is >> n_;
    for(int i = 0; i < n_; i++)
    {
        is >> at(i);
    }
    return is;
}

ostream& operator<<(ostream& os, const vector_t& v)
{
    return v.write(os);
}

istream& operator>>(istream& is, const vector_t& v)
{
    return v.read(is);
}