#ifndef LAB2_01_SRC_TRIANGLE_HPP_
#define LAB2_01_SRC_TRIANGLE_HPP_

#include "Polygon.hpp"

class Triangle : public Polygon {
 public:
  explicit Triangle(const Broken &broken);
  Triangle(const Point& p1, const Point& p2, const Point& p3);
  Triangle(const Triangle &other) = default;
  Triangle &operator=(const Triangle &other);
};

#endif //LAB2_01_SRC_TRIANGLE_HPP_
