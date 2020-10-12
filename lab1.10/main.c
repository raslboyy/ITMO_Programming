#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// нод двух чисел a и b
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(&a, &b);
    }
    return a;
}

// нок двух чисел a и b
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// массив, содержащий цифры числа
int *toDigitalArray(int n) {
    int len = ceil(log10(n));
    int *DigitalArray = (int *) malloc((len + 1) * sizeof(int));
    for (int i = len - 1; i >= 0; i--) {
        DigitalArray[i] = n % 10;
        n /= 10;
    }
    DigitalArray[len] = -1;
    return DigitalArray;
}

int main() {

    int value1, value2;
    scanf("%d %d", &value1, &value2);
    printf("gcd(%d, %d) = %d\nlcm(%d, %d) = %d\n", value1, value2, gcd(value1, value2), value1, value2, lcm(value1, value2));
    int n;
    scanf("%d", &n);
    int* digitalArray = toDigitalArray(n);
    for (int i = 0; digitalArray[i] != -1; i++)
        printf("%d ", digitalArray[i]);

    return 0;
}
