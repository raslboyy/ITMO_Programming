#include "Polygon.hpp"

Polygon::Polygon(const Broken &broken) : Closed(broken), area_(0) {
  if (!this->is_convex())
    std::cout << "Error" << std::endl;
  size_t n = broken_.count();
  for (int i = 0; i != n; i++)
    area_ += double(broken_.get(i).a().x() * broken_.get(i).b().y() - broken_.get(i).a().y() * broken_.get(i).b().x());
  area_ /= 2;
  area_ = std::fabs(area_);
}
Polygon::Polygon(const Polygon &other) : Closed(other.broken_), area_(other.area_) {}

void Polygon::swap(Polygon &other) {
  Closed::swap(other);
  std::swap(area_, other.area_);
}
Polygon &Polygon::operator=(const Polygon &other) {
  Polygon(other).swap(*this);
  return *this;
}

bool Polygon::is_triangle() const {
  if (broken_.count() != 3)
    return false;
  for (int i = 0; i != 3; i++)
    if (broken_.get(i).len() >= broken_.get((i + 1) % 3).len() + broken_.get((i + 2) % 3).len())
      return false;
  return true;
}
bool Polygon::is_trapezoid() const {
  if (broken_.count() != 4)
    return false;
  return (broken_.get(0) || broken_.get(2)) || (broken_.get(1) || broken_.get(3));
}
bool Polygon::is_regular() const {
  size_t n = broken_.count();
  if (n < 3)
    return false;
  for (int i = 0; i < n - 1; i++)
    if (std::fabs(broken_.get(i).len() - broken_.get(i + 1).len()) > EPS)
      return false;
  double cross_product = -100;
  for (size_t i = 0; i != n; i++){
    Vector v1(broken_.get(i));
    Vector v2(broken_.get((i + 1) % n));
    if (cross_product != -100 && fabs(asin(v1 * v2 / v1.len() / v2.len()) - cross_product) > EPS)
      return false;
    cross_product = asin(v1 * v2 / v1.len() / v2.len());
  }
  return true;
}
double Polygon::area() const {
  return area_;
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
  os << "area = " << polygon.area() << " ";
  os << polygon.broken();
  return os;
}
