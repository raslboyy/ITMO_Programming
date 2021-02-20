#ifndef LAB2_01_SRC_BROKEN_HPP_
#define LAB2_01_SRC_BROKEN_HPP_

#include <vector>
#include <iostream>

#include "Segment.hpp"

class Broken {
 public:
  Broken(const Segment& segment);
  Broken(const Broken &other);
  explicit Broken(std::vector<Segment> segments); // const - ?

  void swap(Broken &other);
  Broken &operator=(const Broken &other);

  void add_point(const Point &a);
  [[nodiscard]] double len() const;
  [[nodiscard]] size_t count() const;
  [[nodiscard]] Segment get(int i) const;
  [[nodiscard]] bool is_closed() const;

 private:
  std::vector<Segment> segments_;
  double len_;
};

std::ostream &operator<<(std::ostream &os, const Broken &broken);

#endif //LAB2_01_SRC_BROKEN_HPP_