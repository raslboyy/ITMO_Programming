#include <stdio.h>

int main() {
  FILE *file = fopen("out.mp3", "wb");
  unsigned char arr[5] = "ID3dd";
  fwrite(arr, 1, 5, file);
  return 0;
}
