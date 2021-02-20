#ifndef LAB2_01_SRC_POINT_HPP_
#define LAB2_01_SRC_POINT_HPP_

#include <iostream>

class Point {
 public:
  Point(double x, double y);
  Point(const Point &other);

  void swap(Point &other);
  Point &operator=(const Point &other);

  [[nodiscard]] double x() const;
  [[nodiscard]] double y() const;

 private:
  double x_;
  double y_;
};

bool operator==(const Point &p1, const Point &p2);
std::ostream &operator<<(std::ostream &os, const Point &p);

#endif //LAB2_01_SRC_POINT_HPP_
