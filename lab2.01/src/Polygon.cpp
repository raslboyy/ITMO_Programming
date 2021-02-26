#include "Polygon.hpp"

Polygon::Polygon(const Broken &broken) : Closed(broken) {
  try {
    if (!this->is_convex())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Polygon::Polygon(const Broken &broken)\n";
  }
}
Polygon::Polygon(const Polygon &other) : Closed(other.broken_) {}

void Polygon::swap(Polygon &other) {
  Closed::swap(other);
}
Polygon &Polygon::operator=(const Polygon &other) {
  Polygon(other).swap(*this);
  return *this;
}

bool Polygon::is_triangle() const {
  if (broken_.count() != 3)
    return false;
  for (int i = 0; i < 4; i++) {
    double a1 = broken_.get(i, i + 1).len();
    double a2 = broken_.get(i + 1, i + 2).len();
    double a3 = broken_.get(i + 2, i + 3).len();
    if (a1 >= a2 + a3)
      return false;
  }
  return true;
}
bool Polygon::is_trapezoid() const {
  if (broken_.count() != 4)
    return false;
  return (broken_.get(0, 1) || broken_.get(2, 3)) ||
      (broken_.get(1, 2) || broken_.get(3, 4));
}
bool Polygon::is_regular() const {
  unsigned n = broken_.count();
  if (n < 3)
    return false;
  for (int i = 0; i < n; i++)
    if (std::fabs(broken_.get(i, i + 1).len() - broken_.get(i + 1, i + 2).len()) > EPS)
      return false;
  double cross_product = -100;
  for (size_t i = 0; i != n; i++) {
    Vector v1(broken_.get(i, i + 1));
    Vector v2(broken_.get(i + 1, i + 2));
    if (cross_product != -100 && fabs(asin(v1 * v2 / v1.len() / v2.len()) - cross_product) > EPS)
      return false;
    cross_product = asin(v1 * v2 / v1.len() / v2.len());
  }
  return true;
}
double Polygon::area() const {
  double S = 0;
  unsigned n = broken_.count();
  for (int i = 0; i < n; i++)
    S +=
        double(broken_.get(i).x() * broken_.get((i + 1) % n).y() - broken_.get(i).y() * broken_.get((i + 1) % n).x());
  S /= 2;
  S = std::fabs(S);
  return S;
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
  os << "area = " << polygon.area() << " ";
  os << polygon.broken();
  return os;
}
