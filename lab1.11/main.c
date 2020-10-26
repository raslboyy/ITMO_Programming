#include <stdio.h>

#include "Triangle.h"

int main() {
  struct Triangle triangle = creat_from_console();
  printf("Perimeter = %f\n", perimeter(triangle));
  printf("Area = %f\n", area(triangle));

  return 0;
}