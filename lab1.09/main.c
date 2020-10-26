#include <stdio.h>

int main() {
  // задание 1
  char buffer[256];
  gets(buffer);
  int count = 0;
  for (int i = 0; buffer[i] != '\0'; i++)
    if ((buffer[i] >= '0' && buffer[i] <= '9') ||
        (buffer[i] >= 'A' && buffer[i] <= 'Z') ||
        (buffer[i] >= 'a' && buffer[i] <= 'z')) {
      count++;
    }
  printf("%d\n", count);

  // задание 3
  char digitToString[10][10] = {"zero", "one", "two",   "three", "four",
                                "five", "six", "seven", "eight", "nine"};
  int digit;
  scanf("%d", &digit);
  printf("%s\n", digitToString[digit]);

  return 0;
}
