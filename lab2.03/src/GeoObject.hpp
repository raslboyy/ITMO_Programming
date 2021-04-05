#ifndef LAB2_03_SRC_GEOOBJECT_HPP_
#define LAB2_03_SRC_GEOOBJECT_HPP_

#include "GeoPoint.hpp"

class GeoObject {
 public:
  GeoObject(double x, double y) : point_(x, y) {};
  [[nodiscard]] double x() const { return point_.x(); }
  [[nodiscard]] double y() const { return point_.y(); };
  static double len(const GeoObject &a, const GeoObject &b) {
    return sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
  }
  virtual ~GeoObject() = default;
 private:
  GeoPoint point_;
};

#endif //LAB2_03_SRC_GEOOBJECT_HPP_
