#ifndef LAB2_01_SRC_POLYGON_HPP_
#define LAB2_01_SRC_POLYGON_HPP_

#include "Closed.hpp"

class Polygon : public Closed {
 public:
  explicit Polygon(const Broken &broken);
  Polygon(const Polygon &other);
  Polygon &operator=(const Polygon &other);

  virtual double area() const;

  bool is_triangle() const;
  bool is_trapezoid() const;
  bool is_regular() const;

 private:
  double area_;
};

#endif //LAB2_01_SRC_POLYGON_HPP_
