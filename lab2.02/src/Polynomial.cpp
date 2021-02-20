#include "Polynomial.hpp"

#include <utility>
#include <algorithm>

Polynomial::Polynomial(double value) : P_({value}), n_(1) {}
Polynomial::Polynomial(std::vector<double> P) : P_(std::move(P)), n_(0) {
  n_ = P_.size();
}
Polynomial::Polynomial(int n, double value) : P_(std::vector(n, value)), n_(n) {}

void Polynomial::swap(Polynomial &other) {
  std::swap(P_, other.P_);
  std::swap(n_, other.n_);
}
Polynomial & Polynomial::operator=(const Polynomial &other) {
  Polynomial(other).swap(*this);
  return *this;
}

Polynomial Polynomial::operator-() const {
  Polynomial copy = *this;
  for (int i = 0; i < copy.n_; i++)
    copy.P_[i] = -copy.P_[i];
  return copy;
}
Polynomial Polynomial::operator+() const {
  return *this;
}
Polynomial & Polynomial::operator+=(const Polynomial &other) {
  for (int i = 0; i < std::min(n_, other.n_); i++)
    P_[i] += other.P_[i];
  return *this;
}
Polynomial & Polynomial::operator-=(const Polynomial &other) {
  for (int i = 0; i < std::min(n_, other.n_); i++)
    P_[i] -= other.P_[i];
  return *this;
}
Polynomial & Polynomial::operator*=(const Polynomial &other) {
  Polynomial copy(n_ + other.n_ - 1, 0);
  for (int i = 0; i < n_; i++)
    for (int j = 0; j < other.n_; j++)
      copy.P_[i + j] += this->P_[i] * other.P_[j];
  return (*this = copy);
}
Polynomial & Polynomial::operator/=(double value) {
  for (int i = 0; i < n_; i++)
    P_[i] /= value;
  return *this;
}

double Polynomial::operator[](int i) const {
  return P_[i];
}
Polynomial Polynomial::operator<<(int n) {
  Polynomial copy = *this;
  std::rotate(copy.P_.begin(), copy.P_.begin() + n % n_, copy.P_.end());
  return copy;
}
Polynomial Polynomial::operator>>(int n) {
  Polynomial copy = *this;
  std::rotate(copy.P_.rbegin(), copy.P_.rbegin() + n % n_, copy.P_.rend());
  return copy;
}

const std::vector<double> &Polynomial::get() const {
  return P_;
}
size_t Polynomial::size() const {
  return n_;
}

bool operator==(const Polynomial &p1, const Polynomial &p2) {
  return p1.get() == p2.get();
}
bool operator!=(const Polynomial &p1, const Polynomial &p2) {
  return !(p1 == p2);
}

Polynomial operator+(Polynomial p1, const Polynomial &p2) {
  return p1 += p2;
}
Polynomial operator-(Polynomial p1, const Polynomial &p2) {
  return p1 -= p2;
}
Polynomial operator*(Polynomial p1, const Polynomial &p2) {
  return p1 *= p2;
}
Polynomial operator/(Polynomial p1, double value) {
  return p1 /= value;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &p) {
  for (int i = 0; i < p.size(); i++)
    os << "(" << p.get()[i] << ") * x^" << i << " + ";
  os << "0\n";
  return os;
}