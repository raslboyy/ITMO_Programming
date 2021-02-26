#ifndef LAB2_01_SRC_SEGMENT_HPP_
#define LAB2_01_SRC_SEGMENT_HPP_

#include <cmath>

#include "Point.hpp"

extern const double EPS;

class Segment {
 public:
  Segment(const Point &a, const Point &b);
  Segment(const Segment &other);

  void swap(Segment &other);
  Segment &operator=(const Segment &other);

  [[nodiscard]] Point a() const;
  [[nodiscard]] Point b() const;
  [[nodiscard]] double A() const;
  [[nodiscard]] double B() const;
  [[nodiscard]] double C() const;
  [[nodiscard]] double len() const;

 private:
  Point a_;
  Point b_;
  double len_;
};

bool operator||(const Segment &s1, const Segment &s2);

#endif //LAB2_01_SRC_SEGMENT_HPP_
