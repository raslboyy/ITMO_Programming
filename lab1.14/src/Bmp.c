#include "Bmp.h"
#include <stdio.h>

WORD addition(WORD width) {
  return width + (32 - width % 32) % 32;
}

Bmp construct_Bmp(char *file_path) {
  Bmp bmp;
  FILE *file = fopen(file_path, "rb");
  fread(&bmp.file_header, sizeof(bmp.file_header), 1, file);
  fread(&bmp.info_header, sizeof(bmp.info_header), 1, file);

  bmp.width = bmp.info_header.biWidth;
  bmp.width4 = addition(bmp.width);
  bmp.height = bmp.info_header.biHeight;

  bmp.size_dif_header = bmp.file_header.bfOffBits - (sizeof(bmp.file_header) + sizeof(bmp.info_header));
  bmp.dif_header = malloc(bmp.size_dif_header);
  fread(bmp.dif_header, 1, bmp.size_dif_header, file);

  bmp.pixels = construct_Bit_map(bmp.width4, bmp.height);
  for (int i = bmp.height - 1; i >= 0; i--)
    fread(bmp.pixels.matrix[i], 1, bmp.width4 / 8, file);

  fclose(file);
  return bmp;
}

void set_pixels(Bmp *bmp, Bit_map pixels) {
  for (int i = 0; i < bmp->height; i++)
    for (int j = 0; j < bmp->width; j++)
      if (get_bit(bmp->pixels, i, j) != get_bit(pixels, i, j))
        change_bit(bmp->pixels, i, j);
}

void to_bmp(Bmp *bmp, char* file_path) {
  FILE *file = fopen(file_path, "wb");
  if (file == NULL)
    return ;
  fwrite(&bmp->file_header, sizeof(bmp->file_header), 1, file);
  fwrite(&bmp->info_header, sizeof(bmp->info_header), 1, file);
  fwrite(bmp->dif_header, 1, bmp->size_dif_header, file);
  for (int i = bmp->height - 1; i >= 0; i--)
    fwrite(bmp->pixels.matrix[i], 1, bmp->width4 / 8, file);

  fclose(file);
}