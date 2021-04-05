#include "Polygon.hpp"

Polygon::Polygon(const Closed &closed) : closed_(closed) {
  try {
    if (!this->closed_.is_convex())
      throw std::exception();
  }
  catch (...) {}
}
Polygon::Polygon(const Polygon &other) : closed_(other.closed_) {}

void Polygon::swap(Polygon &other) {
  closed_.swap(other.closed_);
}
Polygon &Polygon::operator=(const Polygon &other) {
  Polygon(other).swap(*this);
  return *this;
}

bool Polygon::is_triangle() const {
  if (closed_.broken().count() != 3)
    return false;
  for (int i = 0; i < 4; i++) {
    double a1 = closed_.broken().get(i, i + 1).len();
    double a2 = closed_.broken().get(i + 1, i + 2).len();
    double a3 = closed_.broken().get(i + 2, i + 3).len();
    if (a1 >= a2 + a3)
      return false;
  }
  return true;
}
bool Polygon::is_trapezoid() const {
  if (closed_.broken().count() != 4)
    return false;
  return (closed_.broken().get(0, 1) || closed_.broken().get(2, 3)) ||
      (closed_.broken().get(1, 2) || closed_.broken().get(3, 4));
}
bool Polygon::is_regular() const {
  unsigned n = closed_.broken().count();
  if (n < 3)
    return false;
  for (int i = 0; i < n; i++)
    if (std::fabs(closed_.broken().get(i, i + 1).len() - closed_.broken().get(i + 1, i + 2).len()) > EPS)
      return false;
  double cross_product = -100;
  for (size_t i = 0; i != n; i++) {
    Vector v1(closed_.broken().get(i, i + 1));
    Vector v2(closed_.broken().get(i + 1, i + 2));
    if (cross_product != -100 && fabs(asin(v1 * v2 / v1.len() / v2.len()) - cross_product) > EPS)
      return false;
    cross_product = asin(v1 * v2 / v1.len() / v2.len());
  }
  return true;
}
double Polygon::area() const {
  double S = 0;
  unsigned n = closed_.broken().count();
  for (int i = 0; i < n; i++)
    S +=
        double(closed_.broken().get(i).x() * closed_.broken().get((i + 1) % n).y() - closed_.broken().get(i).y() * closed_.broken().get((i + 1) % n).x());
  S /= 2;
  S = std::fabs(S);
  return S;
}
const Closed &Polygon::closed() const {
  return closed_;
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
  os << "area = " << polygon.area() << " ";
  os << polygon.closed().broken();
  return os;
}