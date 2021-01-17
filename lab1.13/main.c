#include <stdio.h>
#include <string.h>
#include "MP3.h"

int main(int argc, char *argv[]) {

  char filePath[100];
  int sizeFilePath = 0;
  char commandType[100];
  int sizeCommandType = 0;
  char propName[100];
  int sizePropName = 0;
  char propValue[100];
  int sizePropValue = 0;

  for (char *i = strpbrk(argv[1], "=") + 1; *i != 0; i++)
    filePath[sizeFilePath++] = *i;
  filePath[sizeFilePath] = 0;

  for (char *i = argv[2]; *i != 0 && *i != '='; i++)
    commandType[sizeCommandType++] = *i;
  commandType[sizeCommandType] = 0;


  if (strcmp(commandType, "--show") != 0) {
    for (char *i = strpbrk(argv[2], "=") + 1; *i != 0; i++)
      propName[sizePropName++] = *i;
    propName[sizePropName] = 0;
  }
  if (argc > 3) {
    //propValue[0] = ' ';
    //sizePropValue++;
    for (char *i = strpbrk(argv[3], "=") + 1; *i != 0; i++)
      propValue[sizePropValue++] = *i;
//    printf("%s6\n", argv[4]);
    for (int i = 4; i < argc - 1; i++) {
      propValue[sizePropValue++] = ' ';
      for (int j = 0; argv[i][j] != 0; j++)
        propValue[sizePropValue++] = argv[i][j];
    }
    propValue[sizePropValue++] = 0;
    printf("%s4\n", propValue);
  }

  MP3 mp3 = create_MP3(filePath);
  if (mp3.ID3v2Size == 0) {
    printf("Cannot open file.\n");
    return 1;
  }
  if (strcmp(commandType, "--show") == 0)
    show(&mp3);
  else if (commandType[2] == 'g')
    printf("%s", getValue(&mp3, propName));
  else
    setValue(&mp3, propName, propValue);

  delete_MP3(&mp3);

  return 0;
}
