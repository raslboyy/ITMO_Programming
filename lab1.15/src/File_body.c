#include "File_body.h"
#include <stdlib.h>

void destruct_File_body(File_body *file_body) {
  free(file_body->data);
  file_body->data = NULL;
  for (int i = 0; i < 256; i++)
    free(file_body->huf[i].code);
}

void change_bit(BYTE1 *code, int i) {
  code[i / 8] |= (1 << (i % 8));
}
int get_bit(BYTE1 *code, int i) {
  return (code[i / 8] >> (i % 8)) & 1;
}

void add_to_bin_code(File_body *file_body, BYTE1 ch, BYTE1 a) {
  if (file_body->huf[ch].len % 8 == 0)
    file_body->huf[ch].code = realloc(file_body->huf[ch].code, file_body->huf[ch].len / 8 + 1);
  if (a == 1)
    change_bit(file_body->huf[ch].code, file_body->huf[ch].len);
  file_body->huf[ch].len++;
}
