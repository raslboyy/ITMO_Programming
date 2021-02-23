#ifndef LAB2_01_SRC_BROKEN_HPP_
#define LAB2_01_SRC_BROKEN_HPP_

#include <vector>
#include <iostream>

#include "Segment.hpp"

class Broken {
 public:
  explicit Broken(const Point& p);
  explicit Broken(std::vector<Point> points);
  Broken(const Broken &other);
//  Broken(const Broken &other) = default;

  void swap(Broken &other);
  Broken &operator=(const Broken &other);
//  Broken &operator=(const Broken &other) = default;

  void add_point(const Point &p);
  [[nodiscard]] double len() const;
  [[nodiscard]] unsigned count() const;
  [[nodiscard]] Point get(unsigned i) const;
  [[nodiscard]] Segment get(unsigned i, unsigned j) const;
  [[nodiscard]] bool is_closed() const;

 private:
  std::vector<Point> points_;
  bool is_closed_;
  double len_;
};

std::ostream &operator<<(std::ostream &os, const Broken &broken);

#endif //LAB2_01_SRC_BROKEN_HPP_