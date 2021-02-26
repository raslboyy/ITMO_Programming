#include "Regular.hpp"

#include <iostream>

Regular::Regular(const Broken &broken) : Polygon(broken) {
  try {
    if (!this->is_regular())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Regular::Regular(const Broken &broken)\n";
  }
}
Regular & Regular::operator=(const Regular &other) {
  Regular(other).swap(*this);
  return *this;
}

double Regular::area() const {
  double a = broken_.count();
  double b = broken_.get(0, 1).len();
  return a * b * broken_.get(0, 1).len() / 4 / tan(M_PI / a);
}