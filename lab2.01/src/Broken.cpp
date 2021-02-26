#include "Broken.hpp"

Broken::Broken(const Point &p) :
    len_(0),
    points_({p}),
    is_closed_(false) {}
Broken::Broken(std::vector<Point> points) :
    points_(std::move(points)),
    len_(0),
    is_closed_(false) {
  for (int i = 1; i < points_.size(); i++)
    len_ += Segment(points_[i - 1], points_[i]).len();
  if (!points_.empty())
    is_closed_ = points_[0] == points_.back();
};
Broken::Broken(const Broken &other) :
    points_(other.points_),
    len_(other.len_),
    is_closed_(other.is_closed_) {}

void Broken::swap(Broken &other) {
  std::swap(points_, other.points_);
  std::swap(len_, other.len_);
}
Broken &Broken::operator=(const Broken &other) {
  Broken(other).swap(*this);
  return *this;
}

void Broken::add_point(const Point &p) {
  len_ += Segment(points_.back(), p).len();
  points_.emplace_back(p);
  is_closed_ = points_[0] == points_.back();
}
double Broken::len() const {
  return len_;
}
unsigned Broken::count() const {
  return (is_closed_ ? points_.size() - 1 : points_.size());
}
Point Broken::get(unsigned i) const {
  return points_[i % count()];
}
Segment Broken::get(unsigned int i, unsigned int j) const {
  return Segment(points_[i % count()], points_[j % count()]);
}
bool Broken::is_closed() const {
  return is_closed_;
}

std::ostream &operator<<(std::ostream &os, const Broken &broken) {
  os << "len = " << broken.len();
  for (int i = 0; i < broken.count(); i++)
    os << " " << broken.get(i);
  return os;
}