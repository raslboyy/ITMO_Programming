#include <stdio.h>
#include <stdlib.h>

int main() {
  const int size_array = 4;

  float array[4];
  array[0] = -3.4f;
  array[1] = 4.5f;
  array[2] = -5.6f;
  array[3] = 6.7f;

  float *pointer = array;
  for (int i = 0; i < size_array; i++) {
    printf("%f ", *(pointer + i));
  }
  printf("\n");

  float *dynamic_array = (float *)malloc(size_array * sizeof(float));
  for (int i = 0; i < size_array; i++) {
    dynamic_array[i] = *(pointer + i);
  }
  for (int i = 0; i < size_array; i++) {
    printf("%f ", dynamic_array[i]);
  }
  printf("\n");
  free(dynamic_array);

  return 0;
}
