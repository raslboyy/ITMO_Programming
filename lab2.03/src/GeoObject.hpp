#ifndef LAB2_03_SRC_GEOOBJECT_HPP_
#define LAB2_03_SRC_GEOOBJECT_HPP_

#include "GeoPoint.hpp"
#include <cmath>

class GeoObject {
 public:
  GeoObject(double x, double y) :
      point_(x, y),
      fi_(x * (M_PI / 180)),
      lambda_(y * (M_PI / 180)) {};
  [[nodiscard]] double x() const { return point_.x(); }
  [[nodiscard]] double y() const { return point_.y(); };
  [[nodiscard]] double fi() const { return fi_; }
  [[nodiscard]] double lambda() const { return lambda_; }
  static double len(const GeoObject &a, const GeoObject &b);
  virtual ~GeoObject() = default;

  constexpr static double R = 6371;

 private:
  GeoPoint point_;
  double fi_;
  double lambda_;
};

#endif //LAB2_03_SRC_GEOOBJECT_HPP_
