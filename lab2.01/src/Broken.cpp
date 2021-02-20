#include "Broken.hpp"

Broken::Broken(const Segment& segment) : len_(segment.len()), segments_({segment}) {}
Broken::Broken(const Broken &other) : segments_(other.segments_), len_(other.len_) {}
Broken::Broken(std::vector<Segment> segments) : segments_(std::move(segments)), len_(0) {
  for (const auto& i : segments_)
    len_ += i.len();
};

void Broken::swap(Broken &other) {
  std::swap(segments_, other.segments_);
  std::swap(len_, other.len_);
}
Broken &Broken::operator=(const Broken &other) {
  Broken(other).swap(*this);
  return *this;
}

double Broken::len() const {
  return len_;
}
void Broken::add_point(const Point &a) {
  segments_.emplace_back(Segment(segments_.back().b(), a));
  len_ += segments_.back().len();
}
size_t Broken::count() const {
  return segments_.size();
}
Segment Broken::get(int i) const {
  return segments_[i];
}
bool Broken::is_closed() const {
  return segments_[0].a() == segments_.back().b();
}

std::ostream &operator<<(std::ostream &os, const Broken &broken) {
  os << "len = " << broken.len();
  for (int i = 0; i < broken.count(); i++)
    os << " " << broken.get(i).a();
  return os;
}