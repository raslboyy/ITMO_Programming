#include "Point.hpp"

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(const Point &other) : x_(other.x()), y_(other.y()) {}

void Point::swap(Point &other) {
  std::swap(x_, other.x_);
  std::swap(y_, other.y_);
}
Point &Point::operator=(const Point &other) {
  Point(other).swap(*this);
  return *this;
}

double Point::x() const {
  return x_;
}
double Point::y() const {
  return y_;
}

bool operator==(const Point &p1, const Point &p2) {
  return p1.x() == p2.x() && p1.y() == p2.y();
}
std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "(" << p.x() << ", " << p.y() << ")";
  return os;
}