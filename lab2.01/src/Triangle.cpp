#include "Triangle.hpp"

#include <iostream>

Triangle::Triangle(const Broken &broken) : Polygon(broken) {
  try {
    if (!this->is_triangle())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Triangle::Triangle(const Broken &broken)\n";
  }
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Polygon(Broken({
                                                                      p1, p2, p3, p1
                                                                  })) {
  try {
    if (!this->is_triangle())
      throw std::exception();
  }
  catch (std::exception) {
    std::cerr << "Error in Triangle::Triangle(Point p1, Point p2, Point p3)\n";
  }
}

Triangle &Triangle::operator=(const Triangle &other) {
  Triangle(other).swap(*this);
  return *this;
}
