#ifndef LAB2_01_SRC_REGULAR_HPP_
#define LAB2_01_SRC_REGULAR_HPP_

#include "Polygon.hpp"

class Regular : public Polygon {
 public:
  explicit Regular(const Broken &broken);
  Regular(const Regular &other) = default;
  Regular &operator=(const Regular &other);

  double area() const override;
};

#endif //LAB2_01_SRC_REGULAR_HPP_
