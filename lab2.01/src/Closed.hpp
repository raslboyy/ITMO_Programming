#ifndef LAB2_01_SRC_CLOSED_HPP_
#define LAB2_01_SRC_CLOSED_HPP_

#include "Broken.hpp"
#include "Vector.hpp"

class Closed {
 public:
  explicit Closed(const Broken &broken);
  Closed(const Closed &other);
  virtual ~Closed() = default;

  virtual void swap(Closed &other);
  Closed &operator=(const Closed &other);

  [[nodiscard]] double len() const;
  [[nodiscard]] bool is_convex() const;
  [[nodiscard]] const Broken &broken() const;
 protected:
  Broken broken_;
};

std::ostream &operator<<(std::ostream &os, const Closed &closed);

#endif //LAB2_01_SRC_CLOSED_HPP_
