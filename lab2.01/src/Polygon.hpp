#ifndef LAB2_01_SRC_POLYGON_HPP_
#define LAB2_01_SRC_POLYGON_HPP_

#include <iostream>
#include <cmath>

#include "Closed.hpp"

class Polygon : public Closed {
 public:
  explicit Polygon(const Broken &broken);
  Polygon(const Polygon &other);

  void swap(Polygon &other);
  Polygon &operator=(const Polygon &other);

  [[nodiscard]] bool is_triangle() const;
  [[nodiscard]] bool is_trapezoid() const;
  [[nodiscard]] bool is_regular() const;
  [[nodiscard]] virtual double area() const;

// private:
//  double area_;
};

std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

#endif //LAB2_01_SRC_POLYGON_HPP_
