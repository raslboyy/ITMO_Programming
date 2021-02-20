#ifndef LAB2_02_SRC_POLYNOMIAL_HPP_
#define LAB2_02_SRC_POLYNOMIAL_HPP_

#include <vector>
#include <iostream>

class Polynomial {
 public:
  Polynomial(double value);
  Polynomial(std::vector<double> P);
  Polynomial(int n, double value);
  Polynomial(const Polynomial &other) = default;
  ~Polynomial() = default;

  void swap(Polynomial &other);
  Polynomial &operator=(const Polynomial &other);

  Polynomial operator-() const;
  Polynomial operator+() const;
  Polynomial &operator+=(const Polynomial &other);
  Polynomial &operator-=(const Polynomial &other);
  Polynomial &operator*=(const Polynomial &other);
  Polynomial &operator/=(double value);

  double operator[](int i) const;
  Polynomial operator>>(int n);
  Polynomial operator<<(int n);

  [[nodiscard]] const std::vector<double> &get() const;
  [[nodiscard]] size_t size() const;

 private:
  std::vector<double> P_;
  int n_;
};

bool operator==(const Polynomial &p1, const Polynomial &p2);
bool operator!=(const Polynomial &p1, const Polynomial &p2);

Polynomial operator+(Polynomial p1, const Polynomial &p2);
Polynomial operator-(Polynomial p1, const Polynomial &p2);
Polynomial operator*(Polynomial p1, const Polynomial &p2);
Polynomial operator/(Polynomial p1, double value);

std::ostream &operator<<(std::ostream &os, const Polynomial &p);

#endif //LAB2_02_SRC_POLYNOMIAL_HPP_
