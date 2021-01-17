#ifndef LAB1_14_SRC_BMP_H_
#define LAB1_14_SRC_BMP_H_
#include <windows.h>
#include "Bit_map.h"

typedef struct tegBmp {
  BITMAPFILEHEADER file_header;
  BITMAPINFOHEADER info_header;
  WORD size_dif_header;
  BYTE *dif_header;
  WORD width;
  WORD width4;
  WORD height;
  Bit_map pixels;
} Bmp;

Bmp construct_Bmp(char *file_path);

void set_pixels(Bmp *bmp, Bit_map pixels);

void to_bmp(Bmp *bmp, char* file_path);

#endif //LAB1_14_SRC_BMP_H_
