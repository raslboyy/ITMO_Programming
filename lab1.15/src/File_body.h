#ifndef LAB1_15_SRC_FILE_BODY_H_
#define LAB1_15_SRC_FILE_BODY_H_

typedef unsigned char BYTE1;
typedef unsigned short BYTE2;
typedef unsigned BYTE4;

typedef struct teg_File_body {
  BYTE4 size;
  BYTE1 *data;
  struct {
    BYTE1 len;
    BYTE1 *code;
  } huf[256];
} File_body;

void destruct_File_body(File_body *file_body);

void change_bit(BYTE1 *code, int i);
int get_bit(BYTE1 *code, int i);

void add_to_bin_code(File_body *file_body, BYTE1 ch, BYTE1 a);

#endif //LAB1_15_SRC_FILE_BODY_H_
