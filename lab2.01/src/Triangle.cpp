#include "Triangle.hpp"

#include <iostream>

Triangle::Triangle(const Broken &broken) : Polygon(broken) {
  if (!this->is_triangle())
    std::cout << "Error" << std::endl;
}

Triangle::Triangle(Point p1, Point p2, Point p3) : Polygon(Broken({
                                                                      Segment(p1, p2),
                                                                      Segment(p2, p3),
                                                                      Segment(p3, p1)
                                                                  })) {
  if (!this->is_triangle())
    std::cout << "Error" << std::endl;
}

Triangle::Triangle(const Triangle &other) : Polygon(other.broken_) {}

Triangle &Triangle::operator=(const Triangle &other) {
  Triangle(other).swap(*this);
  return *this;
}
