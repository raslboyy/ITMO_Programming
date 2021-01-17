#ifndef LAB1_13__FRAMEID3V2_H_
#define LAB1_13__FRAMEID3V2_H_
#include <stdio.h>

void swap(unsigned char *a, unsigned char *b);
unsigned int min(unsigned int a, unsigned int b);

typedef struct FrameID3v2 {
  union {
    unsigned char bytesFrameHeader[10];
    struct {
      unsigned char frameID[4];
      unsigned int frameSize;
      unsigned int a: 1;
      unsigned int b: 1;
      unsigned int c: 1;
      unsigned int : 5;
      unsigned int i: 1;
      unsigned int j: 1;
      unsigned int k: 1;
      unsigned int : 5;
    } normalizedFrameHeader;
  } header;
  unsigned char *body;
} FrameID3v2;

FrameID3v2 create_FrameID3v2(const unsigned char *bytes);

FrameID3v2 create_FrameID3v2_(const unsigned char *frameID, const unsigned char *frameBody);

unsigned char* getStringFrameID(FrameID3v2 *frame);

unsigned int getFrameSize(FrameID3v2 *frame);

void setBody(FrameID3v2 *frame, unsigned char *frameBody);

unsigned char *getHeader(FrameID3v2 *frame);

unsigned char *getStringBody(FrameID3v2 *frame);

unsigned char *getBody(FrameID3v2 *frame);

#endif //LAB1_13__FRAMEID3V2_H_
