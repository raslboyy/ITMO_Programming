#include "MP3.h"
#include <string.h>
#include "stdlib.h"

MP3 create_MP3(char *filePath) {
  MP3 mp3;
  mp3.filePath = filePath;

  FILE *file = fopen(filePath, "rb");
  if (file == NULL)
    return mp3;

  unsigned char buffer[10];
  fread(buffer, sizeof(buffer), 1, file);
  mp3.ID3v2Size = (buffer[9]) | (buffer[8] << 7) | (buffer[7] << 14) | (buffer[6] << 21);
  for (int i = 0; i < 10; i++)
    mp3.header[i] = buffer[i];

  unsigned int countBytes = 0;
  mp3.framesCount = 0;
  while (countBytes + 10 < mp3.ID3v2Size) {
    fread(buffer, 1, 10, file);
    FrameID3v2 currentFrame = create_FrameID3v2(buffer);

    if (getFrameSize(&currentFrame) == 0)
      break;
    if (countBytes + getFrameSize(&currentFrame) + 10 > mp3.ID3v2Size)
      break;

    fread(getBody(&currentFrame), getFrameSize(&currentFrame), 1, file);
    mp3.frames[mp3.framesCount] = currentFrame;
    countBytes += getFrameSize(&mp3.frames[mp3.framesCount]) + 10;
    mp3.framesCount++;
  }

  char mp3BodyChar = 0;
  mp3.body = malloc(1000*1000*10);
  mp3.bodySize = 0;
  while (fread(&mp3BodyChar, 1, 1, file) == 1)
    mp3.body[mp3.bodySize++] = mp3BodyChar;

  fclose(file);
  return mp3;
}

void horizontal(int n) {
  printf("%c", '+');
  for (int i = 0; i < n-2; i++) {
    if (i != 6)
      printf("%c", '-');
    else
      printf("%c", '+');
  }
  printf("%c", '+');
}

void show(MP3 *mp3) {
  int n = 111;
  horizontal(n);
  printf("\n");
  for (int i = 0; i < mp3->framesCount; i++) {
    FrameID3v2 *currentFrame = &mp3->frames[i];
    printf("%c ", '|');
    printf("%s", getStringFrameID(currentFrame));
    printf(" %c ", '|');
    if (getFrameSize(currentFrame) <= 100)
      printf("%100s", getStringBody(currentFrame));
    else
      printf("%100s", "more 100 characters");
    printf(" %c", '|');
    printf("\n");
    horizontal(n);
    printf("\n");
  }
}

char *getValue(MP3 *mp3, char *frameID) {
  for (int i = 0; i < mp3->framesCount; i++)
    if (strcmp((char *)getStringFrameID(&mp3->frames[i]), frameID) == 0)
      return (char*)getStringBody(&mp3->frames[i]);
  char* error = (char *) malloc(strlen(frameID) + strlen("No could not find meta information field named ") + 1);
  char* error1 = "No could not find meta information field named ";
  strcpy(error, error1);
  strcat(error, frameID);
  error[strlen(error) - 1] = 0;
  return error;
}

void setValue(MP3 *mp3, char *frameID, char *frameBody) {
  FILE *file = fopen(mp3->filePath, "wb");

  int flag = 0;
  int countBytes = 0;
  for (int i = 0; i < mp3->framesCount; i++)
    if (strcmp((char *)getStringFrameID(&mp3->frames[i]), frameID) == 0) {
      mp3->ID3v2Size += strlen(frameBody) - strlen((char *)getStringBody(&mp3->frames[i])) + 1;
      setBody(&mp3->frames[i], (unsigned char *)frameBody);
      flag = 1;
    }

  if (flag == 0) {
    FrameID3v2 frame = create_FrameID3v2_(frameID, frameBody);
    mp3->frames[mp3->framesCount++] = frame;
    mp3->ID3v2Size += 10 + getFrameSize(&frame);
  }

  union {
    unsigned int value;
    struct {
      unsigned a: 7;
      unsigned b: 7;
      unsigned c: 7;
      unsigned d: 7;
    };
  } SizeToHeader;
  SizeToHeader.value = mp3->ID3v2Size;
  mp3->header[9] = SizeToHeader.a;
  mp3->header[8] = SizeToHeader.b;
  mp3->header[7] = SizeToHeader.c;
  mp3->header[6] = SizeToHeader.d;

  fwrite(mp3->header, 10, 1, file);
  for (int i = 0; i < mp3->framesCount; i++) {
    unsigned char header[10];
    for (int j = 0; j != 10; j++)
      header[j] = getHeader(&mp3->frames[i])[j];
    swap(&header[4], &header[7]);
    swap(&header[5], &header[6]);
    countBytes += 10;
    fwrite(header, 1, 10, file);
    countBytes += getFrameSize(&mp3->frames[i]);
    fwrite(getBody(&mp3->frames[i]), 1, getFrameSize(&mp3->frames[i]), file);
  }
  if (countBytes < mp3->ID3v2Size)
    fwrite(0, 1, mp3->ID3v2Size-countBytes, file);
  fwrite(mp3->body, 1, mp3->bodySize, file);

  fclose(file);
}

void delete_MP3(MP3 *mp3) {
  for (int i = 0; i < mp3->framesCount; i++)
    free(mp3->frames[i].body);
  free(mp3->body);
}