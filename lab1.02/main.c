#include <stdio.h>
#include "math.h"

int main() {

    double a;
    scanf("%lf", &a);

    double z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
    printf("%lf\n", z1);

    double z2 = 4 * cos(a / 2) * cos(a * 2.5) * cos(4 * a);
    printf("%lf\n", z2);

    return 0;
}
