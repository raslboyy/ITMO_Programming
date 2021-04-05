#ifndef LAB2_01_SRC_TRAPEZOID_HPP_
#define LAB2_01_SRC_TRAPEZOID_HPP_

#include <exception>

#include "Polygon.hpp"
#include "Triangle.hpp"

class Trapezoid : public Polygon {
 public:
  explicit Trapezoid(const Closed &closed);
  Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
  Trapezoid(const Trapezoid &other) = default;
  Trapezoid &operator=(const Trapezoid &other);

  [[nodiscard]] double h() const;
  [[nodiscard]] double area() const override;
  [[nodiscard]] bool is_trapezoid() const override;
};


#endif //LAB2_01_SRC_TRAPEZOID_HPP_
