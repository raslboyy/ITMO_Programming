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