#include "Segment.hpp"

const double EPS = 1e-8;

Segment::Segment(const Point &a, const Point &b) : a_(a), b_(b) {
  len_ = sqrt((a.x() - b.x()) * (a.x() - b.x())
                  + (a.y() - b.y()) * (a.y() - b.y()));
}
Segment::Segment(const Segment &other) : a_(other.a()), b_(other.b()), len_(other.len_) {}

void Segment::swap(Segment &other) {
  a_.swap(other.a_);
  b_.swap(other.b_);
  std::swap(len_, other.len_);
}
Segment &Segment::operator=(const Segment &other) {
  Segment(other).swap(*this);
  return *this;
}

Point Segment::a() const {
  return a_;
}
Point Segment::b() const {
  return b_;
}
double Segment::len() const {
  return len_;
}

bool operator||(const Segment &s1, const Segment &s2) {
  double k1 = (s1.b().y() - s1.a().y()) / (s1.b().x() - s1.a().x());
  double k2 = (s2.b().y() - s2.a().y()) / (s2.b().x() - s2.a().x());
  return std::fabs(k1 - k2) <= EPS;
}