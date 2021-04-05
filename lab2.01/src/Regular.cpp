#include "Regular.hpp"

#include <iostream>

Regular::Regular(const Closed &closed) : Polygon(closed) {
  try {
    if (!this->is_regular())
      throw std::exception();
  }
  catch (...) {}
}
Regular & Regular::operator=(const Regular &other) {
  Regular(other).swap(*this);
  return *this;
}

double Regular::area() const {
  double a = closed_.broken().count();
  double b = closed_.broken().get(0, 1).len();
  return a * b * closed_.broken().get(0, 1).len() / 4 / tan(M_PI / a);
}

bool Regular::is_regular() const {
  return true;
}