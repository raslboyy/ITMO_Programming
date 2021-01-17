#include "Arc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INF = 1e9;

typedef struct {
  int x;
  int size;
  int y[256];
} pair;

int compare (const void *a, const void *b) {
  pair *A = (pair *) a;
  pair *B = (pair *) b;
  return A->x - B->x;
}

Arc construct_Arc(char *array[], int size) {
  Arc arc;
  arc.head.file_type[0] = 'A';
  arc.head.file_type[1] = 'R';
  arc.head.file_type[2] = 'C';
  arc.head.is_compress = 0;
  arc.head.number_of_files = size;
  arc.files_table = (File_head *) malloc(size * sizeof(File_head));
  arc.files = (File_body *) malloc(size * sizeof(File_body));

  unsigned count_bytes = 0;
  BYTE1 *buffer = (BYTE1 *) malloc(50*1000*1000);
  for (int i = 0; i < size; i++) {
    File_head file_head;
    file_head.size = strlen(array[i]);
    file_head.name = (BYTE1 *) malloc(file_head.size);

    for (int j = 0; j < file_head.size; j++)
      file_head.name[j] = array[i][j];

    File_body file_body;
    for (int j = 0; j < 256; j++) {
      file_body.huf[j].len = 0;
      file_body.huf[j].code = malloc(1);
      file_body.huf[j].code[0] = 0;
    }
    file_body.size = 0;

    FILE *file = fopen(array[i], "rb");
    while (fread((buffer + file_body.size), 1, 1, file) == 1)
      file_body.size++;
    fclose(file);

    file_body.data = (BYTE1 *) malloc(file_body.size);
    for (int j = 0; j < file_body.size; j++)
      file_body.data[j] = buffer[j];

    arc.files[i] = file_body;
    arc.files_table[i] = file_head;
    count_bytes += file_head.size;

  }

  free(buffer);
  return arc;
}

Arc construct_Arc_(char *archive_name){
  FILE *file = fopen(archive_name, "rb");
  Arc arc;
  fread(arc.head.bytes, 4, 2, file);
  arc.files_table = (File_head *) malloc(arc.head.number_of_files * sizeof(File_head));
  arc.files = (File_body *) malloc(arc.head.number_of_files * sizeof(File_body));

  for (int i = 0; i < arc.head.number_of_files; i++) {
    File_head file_head;
    fread(&file_head.size, 2, 1, file);
    file_head.name = (BYTE1 *) malloc(file_head.size);
    fread(file_head.name, 1, file_head.size, file);
    arc.files_table[i] = file_head;
  }
  for (int i = 0; i < arc.head.number_of_files; i++) {
    File_body file_body;
    for (int j = 0; j < 256; j++) {
      file_body.huf[j].len = 0;
      file_body.huf[j].code = malloc(1);
      file_body.huf[j].code[0] = 0;
    }
    fread(&file_body.size, 4, 1, file);
    file_body.data = (BYTE1 *) malloc(file_body.size);
    fread(file_body.data, 1, file_body.size, file);
    arc.files[i] = file_body;
  }

  fclose(file);
  return arc;
}

void huffman(Arc *arc) {
  for (int i = 0; i < arc->head.number_of_files; i++) {
    pair count[256];
    for (int j = 0; j < 256; j++)
      count[j].x = INF, count[j].y[0] = j, count[j].size = 1;
    for (int j = 0; j < arc->files[i].size; j++) {
      if (count[arc->files[i].data[j]].x == INF)
        count[arc->files[i].data[j]].x = 0;
      count[arc->files[i].data[j]].x++;
    }
    int min1 = -1;
    int min2 = -1;
    while (1) {
      for (int j = 0; j < 256; j++) {
        if (min1 == -1 || count[j].x < count[min1].x)
          min2 = min1, min1 = j;
        else if (min2 == -1 || count[j].x < count[min2].x)
          min2 = j;
      }
      if (min1 == -1 || min2 == -1 || count[min1].x == INF || min1 == min2 || count[min2].x == INF)
        break;
      for (int k = 0; k < count[min1].size; k++)
        add_to_bin_code(&arc->files[i], count[min1].y[k], 0);
      for (int k = 0; k < count[min2].size; k++)
        add_to_bin_code(&arc->files[i], count[min2].y[k], 1);
      count[min1].x += count[min2].x;
      count[min2].x = INF;
      for (int k = count[min1].size; count[min1].size - k < count[min2].size; count[min1].size++)
        count[min1].y[count[min1].size] = count[min2].y[count[min1].size - k];
      min1 = min2 = 0;
    }
    BYTE1 *buffer = (BYTE1 *) malloc(50*1000*1000);
    int len = 0;
    for (int k = 0; k < arc->files[i].size; k++) {
      for (int t = len; len - t < arc->files[i].huf[arc->files[i].data[k]].len; len++)
        if (get_bit(arc->files[i].huf[arc->files[i].data[k]].code, len - t) != get_bit(buffer, len))
          change_bit(buffer, len);
    }
    for (int j = 0; j < len; j++)
      printf("%d ", get_bit(buffer, j));
  }

}

void print_list(Arc *arc){
  for (int i = 0; i < arc->head.number_of_files; i++) {
    char *file_name = malloc(arc->files_table[i].size + 1);
    for (int j = 0; j < arc->files_table[i].size; j++)
      file_name[j] = arc->files_table[i].name[j];
    file_name[arc->files_table[i].size] = 0;
    printf("%s\n", file_name);
    free(file_name);
  }
}

void archive(Arc *arc, char *file_name) {
  FILE *file = fopen(file_name, "wb");
  fwrite(arc->head.bytes, sizeof(arc->head.bytes), 1, file);
  for (int i = 0; i < arc->head.number_of_files; i++) {
    fwrite(&arc->files_table[i].size, 2, 1, file);
    fwrite(arc->files_table[i].name, arc->files_table[i].size, 1, file);
  }
  for (int i = 0; i < arc->head.number_of_files; i++) {
    fwrite(&arc->files[i].size, 4, 1, file);
    fwrite(arc->files[i].data, arc->files[i].size, 1, file);
  }
  fclose(file);
}

void unarchive(Arc *arc) {
  for (int i = 0; i < arc->head.number_of_files; i++) {
    char *file_name = (char *) malloc(arc->files_table[i].size + 1);
    for (int j = 0; j < arc->files_table[i].size; j++)
      file_name[j] = arc->files_table[i].name[j];
    file_name[arc->files_table[i].size] = 0;

    FILE *file = fopen(file_name, "wb");
    fwrite(arc->files[i].data, 1, arc->files[i].size, file);
    free(file_name);
    fclose(file);
  }
}

void destruct_Arc(Arc *arc) {
  for (int i = 0; i < arc->head.number_of_files; i++) {
    destruct_File_head(&arc->files_table[i]);
    destruct_File_body(&arc->files[i]);
  }
  free(arc->files_table);
  free(arc->files);
  arc->files_table = NULL;
  arc->files = NULL;
}