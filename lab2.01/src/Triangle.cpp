#include "Triangle.hpp"

#include <iostream>

Triangle::Triangle(const Closed &closed) : Polygon(closed) {
  try {
    if (!this->is_triangle())
      throw std::exception();
  }
  catch (...) {}
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Polygon(Closed(Broken({
                                                                      p1, p2, p3, p1
                                                                  }))) {
  try {
    if (!this->is_triangle())
      throw std::exception();
  }
  catch (...) {}
}

Triangle &Triangle::operator=(const Triangle &other) {
  Triangle(other).swap(*this);
  return *this;
}

double Triangle::semi_p() const {
  return closed_.broken().len() / 2;
}
double Triangle::area() const {
  double S = sqrt(semi_p() * (semi_p() - closed_.broken().get(0, 1).len()) * (semi_p() - closed_.broken().get(1, 2).len()) * (semi_p() - closed_.broken().get(2, 3).len()));
  return S;
}
bool Triangle::is_triangle() const {
  return true;
}