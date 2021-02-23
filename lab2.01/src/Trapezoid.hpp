#ifndef LAB2_01_SRC_TRAPEZOID_HPP_
#define LAB2_01_SRC_TRAPEZOID_HPP_

#include <exception>

#include "Polygon.hpp"

class Trapezoid : public Polygon {
 public:
  explicit Trapezoid(const Broken &broken);
  Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
  Trapezoid(const Trapezoid &other) = default;
  Trapezoid &operator=(const Trapezoid &other);
};


#endif //LAB2_01_SRC_TRAPEZOID_HPP_
