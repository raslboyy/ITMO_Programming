#include "GeoObject.hpp"

double GeoObject::len(const GeoObject &a, const GeoObject &b) {
  double c1 = (b.fi_ - a.fi_) / 2;
  double c2 = (b.lambda_ - a.lambda_) / 2;
  double c = sin(c1) * sin(c1) + cos(a.fi_) * cos(b.fi_) * sin(c2) * sin(c2);
  return 2 * R * atan2(sqrt(c), sqrt(1 - c));
}