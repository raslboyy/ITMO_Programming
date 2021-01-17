#ifndef LAB1_13__MP3_H_
#define LAB1_13__MP3_H_
#include <stdio.h>
#include "FrameID3v2.h"

typedef struct MP3 {
  char *filePath;
  unsigned char header[10];
  unsigned int ID3v2Size;
  unsigned int framesCount;
  FrameID3v2 frames[100];
  unsigned char* body;
  unsigned bodySize;
} MP3;

MP3 create_MP3(char *filePath);

void show(MP3 *mp3);

char *getValue(MP3 *mp3, char *frameID);

void setValue(MP3 *mp3, char *frameID, char *frameBoby);

void delete_MP3(MP3 *mp3);

#endif //LAB1_13__MP3_H_
