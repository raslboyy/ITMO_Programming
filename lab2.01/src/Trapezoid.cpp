#include "Trapezoid.hpp"

Trapezoid::Trapezoid(const Closed &closed) : Polygon(closed) {
  try {
    if (!this->is_trapezoid())
      throw std::exception();
  }
  catch (...) {}
}
Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point &p3, const Point& p4) : Polygon(Closed(Broken({
                                                                                         p1, p2, p3, p4, p1
                                                                                     }))) {
  try {
    if (!this->is_trapezoid())
      throw std::exception();
  }
  catch (...) {}
}
Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
  Trapezoid(other).swap(*this);
  return *this;
}

double Trapezoid::h() const {
  if (closed_.broken().get(0, 1) || closed_.broken().get(2, 3)) {
    double S_triangle = Triangle({closed_.broken().get(0), closed_.broken().get(2), closed_.broken().get(3)}).area();
    return 2 * S_triangle / closed_.broken().get(2, 3).len();
  }
  if (closed_.broken().get(1, 2) || closed_.broken().get(3, 4)) {
    double S_triangle = Triangle({closed_.broken().get(1), closed_.broken().get(3), closed_.broken().get(4)}).area();
    return 2 * S_triangle / closed_.broken().get(3, 4).len();
  }
}
double Trapezoid::area() const {
  if (closed_.broken().get(0, 1) || closed_.broken().get(2, 3))
    return 0.5 * (closed_.broken().get(0, 1).len() + closed_.broken().get(2, 3).len()) * h();
  if (closed_.broken().get(1, 2) || closed_.broken().get(3, 4))
    return 0.5 * (closed_.broken().get(1, 2).len() + closed_.broken().get(3, 4).len()) * h();
}

bool Trapezoid::is_trapezoid() const {
  return true;
}