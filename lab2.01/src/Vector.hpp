#ifndef LAB2_01_SRC_VECTOR_HPP_
#define LAB2_01_SRC_VECTOR_HPP_

#include "Segment.hpp"

class Vector {
 public:
  Vector(const Segment &segment);
  double x() const;
  double y() const;
  double len() const;
 private:
  Point r;
  double len_;
};

double operator*(const Vector &v1, const Vector &v2);

#endif //LAB2_01_SRC_VECTOR_HPP_
