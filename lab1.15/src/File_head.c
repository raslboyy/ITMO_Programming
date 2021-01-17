#include "File_head.h"
#include <stdlib.h>

void destruct_File_head(File_head *file_head) {
  free(file_head->name);
  file_head->name = NULL;
}