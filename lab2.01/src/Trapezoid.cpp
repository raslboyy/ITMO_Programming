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

double Trapezoid::h() const {
  if (broken_.get(0, 1) || broken_.get(2, 3)) {
    double S_triangle = Triangle({broken_.get(0), broken_.get(2), broken_.get(3)}).area();
    return 2 * S_triangle / broken_.get(2, 3).len();
  }
  if (broken_.get(1, 2) || broken_.get(3, 4)) {
    double S_triangle = Triangle({broken_.get(1), broken_.get(3), broken_.get(4)}).area();
    return 2 * S_triangle / broken_.get(3, 4).len();
  }
}
double Trapezoid::area() const {
  if (broken_.get(0, 1) || broken_.get(2, 3))
    return 0.5 * (broken_.get(0, 1).len() + broken_.get(2, 3).len()) * h();
  if (broken_.get(1, 2) || broken_.get(3, 4))
    return 0.5 * (broken_.get(1, 2).len() + broken_.get(3, 4).len()) * h();
}