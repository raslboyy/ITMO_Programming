#include <math.h>
#include <stdio.h>
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
int lcm(int a, int b) { return a * b / gcd(a, b); }

// массив, содержащий цифры числа
int *to_digital_array(int n) {
  int len = ceil(log10(n));
  int *digital_array = (int *)malloc((len + 1) * sizeof(int));
  for (int i = len - 1; i >= 0; i--) {
    digital_array[i] = n % 10;
    n /= 10;
  }
  digital_array[len] = -1;
  return digital_array;
}

int main() {
  int value1, value2;
  scanf("%d %d", &value1, &value2);
  printf("gcd(%d, %d) = %d\nlcm(%d, %d) = %d\n", value1, value2,
         gcd(value1, value2), value1, value2, lcm(value1, value2));

  int n;
  scanf("%d", &n);
  int *digital_array = to_digital_array(n);
  for (int i = 0; digital_array[i] != -1; i++) {
    printf("%d ", digital_array[i]);
  }

  return 0;
}
