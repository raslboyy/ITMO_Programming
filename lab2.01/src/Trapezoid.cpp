#include "Trapezoid.hpp"

Trapezoid::Trapezoid(const Broken &broken) : Polygon(broken) {
  if (!this->is_trapezoid())
    return;
}
Trapezoid::Trapezoid(const Trapezoid &other) : Polygon(other.broken_) {}
Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4) : Polygon(Broken({
                                                                                  Segment(p1, p2),
                                                                                  Segment(p2, p3),
                                                                                  Segment(p3, p4),
                                                                                  Segment(p4, p1)
                                                                              })) {
  if (!this->is_trapezoid())
    return;
}
Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
  Trapezoid(other).swap(*this);
  return *this;
}