#ifndef F3EDF77E_4079_4399_A8F2_8680A31CE6D2
#define F3EDF77E_4079_4399_A8F2_8680A31CE6D2

#include "math.h"

struct Point {
    float x;
    float y;
};

struct Triangle {
    struct Point a;
    struct Point b;
    struct Point c;
};

float perimeter(struct Triangle triangle);

float area(struct Triangle triangle);

struct Triangle creat_from_console();

#endif /* F3EDF77E_4079_4399_A8F2_8680A31CE6D2 */
