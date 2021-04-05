#ifndef LAB2_01_SRC_POLYGON_HPP_
#define LAB2_01_SRC_POLYGON_HPP_

#include <iostream>
#include <cmath>

#include "Closed.hpp"

class Polygon {
 public:
  explicit Polygon(const Closed &closed);
  Polygon(const Polygon &other);

  void swap(Polygon &other);
  Polygon &operator=(const Polygon &other);

  [[nodiscard]] virtual bool is_triangle() const;
  [[nodiscard]] virtual bool is_trapezoid() const;
  [[nodiscard]] virtual bool is_regular() const;
  [[nodiscard]] virtual double area() const;
  [[nodiscard]] const Closed &closed() const;

 protected:
  Closed closed_;
};

std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

#endif //LAB2_01_SRC_POLYGON_HPP_
