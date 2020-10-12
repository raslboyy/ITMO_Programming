#include <stdio.h>

int get_sign(int a){
    return a >> 31;
}

int main() {
    int r = 6, l = 9;
    int a;
    scanf("%d", &a);

    printf("%d\n", (-get_sign(a - r) | -get_sign(l - a)) + 1 & 1);

    int b;
    scanf("%d", &b);
    printf("%d\n", (b >> 26) & 1);

    return 0;
}
