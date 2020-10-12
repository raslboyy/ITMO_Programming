#include <stdio.h>

int main() {

    int l = 6, r = 9;
    int a;
    scanf("%d", &a);
    printf("%d\n", a >= l && a <= r);

    int b;
    scanf("%d", &b);
    printf("%d\n", (b >> 26) & 1);

    return 0;
}
