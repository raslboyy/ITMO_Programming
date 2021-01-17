#include "Bit_map.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

Bit_map construct_Bit_map(WORD width, WORD height) {
  Bit_map bits;
  bits.width = width;
  bits.height = height;
  BYTE **a = bits.matrix;
  bits.matrix = (BYTE **) malloc(height * sizeof(BYTE *));
  for (int i = 0; i < height; i++)
    bits.matrix[i] = (BYTE *) malloc(width / 8);
  for (int i = 0; i < height; i++)
    for (int j = 0; j < (width - 1) / 8 + 1; j++)
      bits.matrix[i][j] = 255;
  return bits;
}

Bit_map construct_copy_Bit_map(Bit_map other) {
  Bit_map bits = construct_Bit_map(other.width, other.height);
  for (int i = 0; i < bits.height; i++)
    for (int j = 0; j < bits.width / 8; j++)
      bits.matrix[i][j] = other.matrix[i][j];
  return bits;
}

void destruct_Bit_map(Bit_map *bits) {
//  for (int i = 0; i < bits->height; i++)
//    free(bits->matrix[i]);
//  free(bits->matrix);
}

BYTE get_bit(Bit_map bits, size_t i, size_t j) {
  return ((bits.matrix[i][j / 8] >> (7 - (j % 8))) & 1);
}

void change_bit(Bit_map bits, size_t i, size_t j) {
  if (get_bit(bits, i, j))
    bits.matrix[i][j / 8] &= ~(1 << (7 - (j % 8)));
  else
    bits.matrix[i][j / 8] |= (1 << (7 - (j % 8)));
}

unsigned count_bits(Bit_map bits, int i, int j, int width, int height) {
  int count = 0;
  for (int a = -1; a <= 1; a++)
    for (int b = -1; b <= 1; b++)
      if (a != 0 || b != 0)
        if (get_bit(bits, (i + a + height) % height, (j + b + width) % width) == 0)
          count++;
  return count;
}