#include <stdio.h>

int main() {

    int a;
    scanf("%d", &a);

    printf("%x\n", a);

    printf("%x\n", a);
    printf("%x\n", a<<2);

    printf("%x\n", a);
    printf("%x\n", ~a);

    int b;
    scanf("%x", &b);
    printf("%x\n", a ^ b);

    return 0;
}
