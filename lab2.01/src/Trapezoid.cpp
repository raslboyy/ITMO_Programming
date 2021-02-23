#include "Trapezoid.hpp"

Trapezoid::Trapezoid(const Broken &broken) : Polygon(broken) {
  try {
    if (!this->is_trapezoid())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Trapezoid::Trapezoid(const Broken &broken)\n";
  }
}
Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point &p3, const Point& p4) : Polygon(Broken({
                                                                                         p1, p2, p3, p4, p1
                                                                                     })) {
  try {
    if (!this->is_trapezoid())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point &p3, const Point& p4)\n";
  }
}
Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
  Trapezoid(other).swap(*this);
  return *this;
}