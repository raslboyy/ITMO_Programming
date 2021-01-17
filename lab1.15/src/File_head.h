#ifndef LAB1_15_SRC_FILE_HEAD_H_
#define LAB1_15_SRC_FILE_HEAD_H_

typedef unsigned char BYTE1;
typedef unsigned short BYTE2;
typedef unsigned BYTE4;

typedef struct teg_File_head {
  BYTE2 size;
  BYTE1 *name;
  BYTE1 k;
  BYTE1 *haf_table;
} File_head;

void destruct_File_head(File_head *file_head);


#endif //LAB1_15_SRC_FILE_HEAD_H_
