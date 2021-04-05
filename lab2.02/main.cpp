#include <iostream>
#include "src/Polynomial.hpp"

int main() {
  Polynomial p1({1, 2, 3, 4});
  Polynomial p2(3, 1);
  Polynomial p3 = p1;
  std::cout << p1 << p2 << p3;
  std::cout << (p1 == p3) << std::endl;
  std::cout << (p1 != p2) << std::endl;
  p3 = -p3;
  std::cout << p3;
  std::cout << p1 + p3;
  p2 -= Polynomial{std::vector<double>({1, 1, 1})};
  std::cout << p2 * p1;
  std::cout << 5 * p1;
  std::cout << (10 * p1) / 2;
  p1 *= 2;
  std::cout << p1;
  std::cout << (p1 << 2);
  std::cout << (p1 >> 1);
  std::cout << p1[3] << std::endl;


  return 0;
}
