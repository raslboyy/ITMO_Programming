#include <iostream>

#include "src/Triangle.hpp"
#include "src/Trapezoid.hpp"
#include "src/Regular.hpp"

int main() {

  std::cout.precision(2);
  std::cout << std::fixed;
  // Ломанная
  Broken broken(Point(1, 1));
  broken.add_point(Point(2, 1));
  broken.add_point(Point(2, 2));
  broken.add_point(Point(1, 2));
  std::cout << broken << std::endl;

  Broken broken_copy = broken;
  broken_copy.add_point({1, 1});
  Broken broken_assigment{{{1, 1}, {1, 1}}};
  broken_assigment = broken;
  broken_assigment.add_point({100, 100});
  std::cout << broken << std::endl;
  std::cout << broken_copy << std::endl;
  std::cout << broken_assigment << std::endl << std::endl;

  // Замкнутая ломанная
  broken.add_point(Point(1, 1));
  Closed closed(broken);
  std::cout << closed << std::endl << std::endl;

  // Выпуклый многоугольник
  Polygon polygon((Closed(broken)));
  std::cout << polygon << std::endl << std::endl;

  // Треугольник
  Triangle triangle({1, 1}, {3, 1}, {2, 2});
  std::cout << triangle << std::endl << std::endl;
  // Трапеция
  Trapezoid trapezoid((Closed(broken)));
  std::cout << trapezoid << std::endl << std::endl;
  // Правильный многоугольник
//  broken = Broken({
//                      {1, 1},
//                      {2, 1},
//                      {3, 3},
//                      {1, 1}
//  });
  Regular regular((Closed(broken)));
  std::cout << regular << std::endl << std::endl;

  // Динамический полиморфизм
  std::vector<Polygon *> array = {&triangle, &trapezoid, &regular};
  for (const auto item : array)
    std::cout << *item << std::endl;

  return 0;
}
