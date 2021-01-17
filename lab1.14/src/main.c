#include <stdio.h>
#include <windows.h>
#include "Bmp.h"
#include "Game_of_life.h"

int main(int argc, char *argv[]) {

  Bmp bmp = construct_Bmp(argv[2]);
//  to_bmp(&bmp, ".\\out\\2.bmp");
  int width = bmp.width;
  int height = bmp.height;
  Game_of_life game = construct_Game_of_life(bmp.pixels, width, height);

  char file_name[] = "gen000000.bmp";
  char *file_path = malloc(100);
  file_path[0] = '.';
  file_path[1] = '\\';
  file_path[2] = 0;
  file_path = strcat(strcat(file_path, argv[4]), "\\");
  int n = 1e9;
  if (argc >= 7)
    n = atoi(argv[6]);
  int fr = 1;
  if (argc >= 9)
    fr = atoi(argv[8]);
  for (int i = 0; i < n; i++) {
    for (int k = i, j = 8; k; k /= 10, j--)
      file_name[j] = '0' + k % 10;
    if (i % fr != 0)
      continue;
    strcpy(file_path + strlen(argv[4]) + 3, file_name);
    to_bmp(&bmp, file_path);
    set_pixels(&bmp, generation(game));
  }

  return 0;
}
