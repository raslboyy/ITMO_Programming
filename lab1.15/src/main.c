#include <stdio.h>
#include "Arc.h"

int main(int argc, char *argv[]) {

//  int argc = 8;
//  char *argv[] = {"lab1_15.exe", "arc", "--file", "archive.arc", "--extract", "doc.pdf", "audio.mp3", "image.bmp"};

//  if (argv[4][2] == 'c') {
//    char *array[100];
//    int size = argc - 5;
//    for (int i = 0; i < size; i++)
//      array[i] = argv[5 + i];
//    Arc arc = construct_Arc(array, size);
//    archive(&arc, argv[3]);
//    destruct_Arc(&arc);
//  }
//  else {
//    Arc arc = construct_Arc_(argv[3]);
//    if (argv[4][2] == 'e')
//      unarchive(&arc);
//    else
//      print_list(&arc);
//    destruct_Arc(&arc);
//  }
  char *array[1] = {"1.txt"};
  Arc arc = construct_Arc(array, 1);
//  archive(&arc, "archive.arc");
//  Arc arc = construct_Arc_("archive.arc");
  huffman(&arc);
//  unarchive(&arc);
//  print_list(&arc);


  return 0;
}
