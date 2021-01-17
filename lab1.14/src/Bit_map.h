#ifndef LAB1_14_SRC_BIT_MAP_H_
#define LAB1_14_SRC_BIT_MAP_H_
#include <windows.h>

typedef struct tagBit_map {
  WORD width;
  WORD height;
  BYTE **matrix;
} Bit_map;

Bit_map construct_Bit_map(WORD width, WORD height);
Bit_map construct_copy_Bit_map(Bit_map other);

void destruct_Bit_map(Bit_map *bits);

BYTE get_bit(Bit_map bits, size_t i, size_t j);
void change_bit(Bit_map bits, size_t i, size_t j);
unsigned count_bits(Bit_map bits, int i, int j, int width, int height);



#endif //LAB1_14_SRC_BIT_MAP_H_
