#include <stdlib.h>
#include "FrameID3v2.h"
#include <string.h>

unsigned int min(unsigned int a, unsigned int b) {
  if (a < b)
    return a;
  return b;
}

void swap(unsigned char *a, unsigned char *b) {
  unsigned char t = *a;
  *a = *b;
  *b = t;
}

FrameID3v2 create_FrameID3v2(const unsigned char *bytes) {
  FrameID3v2 frame;
  for (int i = 0; i < 4; i++)
    frame.header.bytesFrameHeader[i] = bytes[i];
  for (int i = 4, j = 7; i < 8; i++, j--)
    frame.header.bytesFrameHeader[i] = bytes[j];
  for (int i = 8; i < 10; i++)
    frame.header.bytesFrameHeader[i] = bytes[i];
  frame.body = (unsigned char *) malloc(getFrameSize(&frame) + 1);
  frame.body[getFrameSize(&frame)] = 0;
  return frame;
}

FrameID3v2 create_FrameID3v2_(const unsigned char *frameID, const unsigned char *frameBody) {
  FrameID3v2 frame;
  for (int i = 0; i < 10; i++)
    frame.header.bytesFrameHeader[i] = 0;
  for (int i = 0; i < 4; i++)
    frame.header.normalizedFrameHeader.frameID[i] = frameID[i];
  frame.header.normalizedFrameHeader.frameSize = strlen(frameBody) + 1;
  frame.body = (unsigned char *) malloc(getFrameSize(&frame));
  frame.body[0] = 0;
  for (int i = 0; i <= getFrameSize(&frame); i++)
    frame.body[i + 1] = frameBody[i];
  return frame;
}

unsigned int getFrameSize(FrameID3v2 *frame) {
  return frame->header.normalizedFrameHeader.frameSize;
}

unsigned char *getBody(FrameID3v2 *frame) {
  return frame->body;
}

void setBody(FrameID3v2 *frame, unsigned char *frameBody) {
  free(frame->body);
  unsigned new_size = strlen(frameBody) + 1;
  frame->header.normalizedFrameHeader.frameSize = new_size;
  frame->body = (unsigned char *) malloc(new_size);
  //frame->body[new_size] = 0;
  frame->body[0] = 0;
  for (int j = 1; frameBody[j - 1] != 0; j++)
    frame->body[j] = frameBody[j - 1];
}

unsigned char *getStringFrameID(FrameID3v2 *frame) {
  static unsigned char resultString[5];
  for (int i = 0; i < 4; i++)
    resultString[i] = frame->header.normalizedFrameHeader.frameID[i];
  resultString[4] = '\0';
  return resultString;
}

unsigned char *getStringBody(FrameID3v2 *frame) {
  static unsigned char resultString[101];
  for (int i = 0; i < min(getFrameSize(frame), 100); i++) {
    if (frame->body[i] != 0)
      resultString[i] = frame->body[i];
    else
      resultString[i] = ' ';
  }
  resultString[getFrameSize(frame)] = '\0';
  return resultString;
}

unsigned char* getHeader(FrameID3v2 *frame) {
  return frame->header.bytesFrameHeader;
}