#ifndef LAB2_01_SRC_REGULAR_HPP_
#define LAB2_01_SRC_REGULAR_HPP_

#include "Polygon.hpp"

class Regular : public Polygon {
 public:
  explicit Regular(const Closed &closed);
  Regular(const Regular &other) = default;
  Regular &operator=(const Regular &other);

  [[nodiscard]] double area() const override;
  [[nodiscard]] bool is_regular() const override;
};

#endif //LAB2_01_SRC_REGULAR_HPP_
