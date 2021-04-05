#include "Closed.hpp"

Closed::Closed(const Broken &broken) : broken_(broken) {
  try {
    if (!broken.is_closed())
      throw std::exception();
  }
  catch (...) {}
}
//Closed::Closed(const Closed &other) : broken_(other.broken_) {}

void Closed::swap(Closed &other) {
  this->broken_.swap(other.broken_);
}
Closed & Closed::operator=(const Closed &other) {
  Closed(other).swap(*this);
  return *this;
}

double Closed::len() const {
  return broken_.len();
}
bool Closed::is_convex() const {
  unsigned n = broken_.count();
  int cnt1 = 0;
  int cnt2 = 0;
  for (unsigned i = 0; i < n; i++) {
    Vector v1(broken_.get(i, i + 1));
    Vector v2(broken_.get(i + 1, i + 2));
    if (v1 * v2 < 0)
      cnt1++;
    else
      cnt2++;
  }
  return cnt1 * cnt2 == 0;
}
const Broken &Closed::broken() const {
  return broken_;
}

std::ostream &operator<<(std::ostream &os, const Closed &closed) {
  os << closed.broken();
  return os;
}