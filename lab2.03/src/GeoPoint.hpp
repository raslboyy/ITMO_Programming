#ifndef LAB2_03_SRC_GEOPOINT_HPP_
#define LAB2_03_SRC_GEOPOINT_HPP_

#include <cmath>

// Если все методы разумно делать inline, то можно ли оставить определение в заголовке (простые классы) ?

class GeoPoint {
 public:
  GeoPoint(double x, double y) : x_(x), y_(y) {};
  [[nodiscard]] double x() const { return x_; }
  [[nodiscard]] double y() const { return y_; }
 private:
  double x_;
  double y_;
};

#endif //LAB2_03_SRC_GEOPOINT_HPP_
