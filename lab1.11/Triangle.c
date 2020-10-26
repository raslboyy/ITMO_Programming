#include "Triangle.h"

#include <stdio.h>

#include "math.h"

float len(struct Point a, struct Point b) {
  return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

float perimeter(struct Triangle triangle) {
  return len(triangle.a, triangle.b) + len(triangle.b, triangle.c) +
         len(triangle.c, triangle.a);
}

float area(struct Triangle triangle) {
  float P = perimeter(triangle);
  float p = P / 2;
  return sqrt(p * (p - len(triangle.a, triangle.b)) *
              (p - len(triangle.b, triangle.c)) *
              (p - len(triangle.c, triangle.a)));
}

struct Triangle creat_from_console() {
  struct Triangle triangle;
  scanf("%f %f", &(triangle.a.x), &(triangle.a.y));
  scanf("%f %f", &(triangle.b.x), &(triangle.b.y));
  scanf("%f %f", &(triangle.c.x), &(triangle.c.y));
  return triangle;
}