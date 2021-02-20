#include <iostream>
#include "src/Triangle.hpp"
#include "src/Trapezoid.hpp"

int main() {

  // Ломанная
  Broken broken({Point(1, 1), Point(2, 1)});
  std::cout << std::fixed;
  broken.add_point(Point(2, 2));
  broken.add_point(Point(1, 2));
  std::cout << broken << std::endl;
  Broken broken_copy = broken;
  std::cout << broken_copy << std::endl;
  Broken broken_assigment{{{1, 1}, {1, 1}}};
  broken_assigment = broken;
  std::cout << broken_assigment << std::endl;

  // Замкнутая ломанная
  broken.add_point(Point(1, 1));
  Closed closed(broken);
  std::cout << closed << std::endl;

  // Выпуклый многоугольник
  Polygon polygon(broken);
  std::cout << polygon << std::endl;

  // Треугольник
  Triangle triangle({1, 1}, {3, 1}, {2, 2});
  std::cout << triangle << std::endl;
  // Трапеция
  Trapezoid trapezoid(broken);
  std::cout << trapezoid << std::endl;
  // Правильный многоугольник


  return 0;
}
