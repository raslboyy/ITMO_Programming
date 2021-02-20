#ifndef LAB2_01_SRC_TRAPEZOID_HPP_
#define LAB2_01_SRC_TRAPEZOID_HPP_

#include "Polygon.hpp"

class Trapezoid : public Polygon {
 public:
  explicit Trapezoid(const Broken &broken);
  Trapezoid(Point p1, Point p2, const Point& p3, Point p4);
  Trapezoid(const Trapezoid &other);
  Trapezoid &operator=(const Trapezoid &other);
};


#endif //LAB2_01_SRC_TRAPEZOID_HPP_
