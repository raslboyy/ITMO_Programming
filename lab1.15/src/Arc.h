#ifndef LAB1_15_SRC_ARC_H_
#define LAB1_15_SRC_ARC_H_
#include "File_head.h"
#include "File_body.h"

typedef struct teg_Arc {
  union {
    BYTE4 bytes[2];
    struct {
      BYTE1 file_type[3];
      BYTE1 is_compress;
      BYTE4 number_of_files;
    };
  } head;
  File_head *files_table;
  File_body *files;
} Arc;

Arc construct_Arc(char *array[], int size);
Arc construct_Arc_(char *archive_name);

void huffman(Arc *arc);

void print_list(Arc *arc);

void archive(Arc *arc, char *file_name);
void unarchive(Arc *arc);

void destruct_Arc(Arc *arc);

#endif //LAB1_15_SRC_ARC_H_
