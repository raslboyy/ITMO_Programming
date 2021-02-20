#include "Vector.hpp"

#include "math.h"

Vector::Vector(const Segment &segment) : r(segment.b().x() - segment.a().x(), segment.b().y() - segment.a().y()) {
  len_ = sqrt(r.x() * r.x() + r.y() * r.y());
}
double Vector::x() const {
  return r.x();
}
double Vector::y() const {
  return r.y();
}
double Vector::len() const {
  return len_;
}
double operator*(const Vector &v1, const Vector &v2) {
  return v1.x() * v2.y() - v1.y() * v2.x();
}