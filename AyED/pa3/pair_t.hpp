#include <iostream>

using namespace std;

template<class T>
class pair_t
{
public:
  pair_t() : val_(), inx_(-1) {}
  pair_t(const T val, const int inx_) : val_(val), inx_(inx_) {}

  T get_val() const { return val_; }
  int get_inx() const { return inx_; }
  void set(const T val, const int inx) { val_ = val, inx_ = inx; }

  istream& read(istream& is = cin) { is >> inx_ >> val_; }
  ostream& write(ostream& os = cout) { os << "(" << inx_ << ":" << val_ << ")" ; }

private:
  T val_;
  int inx_;
};  //class pair_t

ostream& operator<<(ostream& os, const pair_t<T> p)
{
  return p.write();
}
