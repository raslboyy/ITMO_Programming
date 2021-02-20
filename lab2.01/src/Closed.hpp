#ifndef LAB2_01_SRC_CLOSED_HPP_
#define LAB2_01_SRC_CLOSED_HPP_

#include "Broken.hpp"

class Closed {
 public:
  Closed(const Broken &broken);
  Closed(const Closed &other);
  Closed &operator=(const Closed &other);
  virtual ~Closed() = default;

  void swap(Closed &other);
  double len() const;
  bool is_convex() const;
 protected:
  Broken broken_;
};

std::ostream &operator<<(std::ostream &os, const Closed &closed);

#endif //LAB2_01_SRC_CLOSED_HPP_
