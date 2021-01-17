#ifndef LAB1_14_SRC_GAME_OF_LIFE_H_
#define LAB1_14_SRC_GAME_OF_LIFE_H_
#include <windows.h>
#include "Bit_map.h"

typedef struct tegGame_of_life {
  int height;
  int width;
  int gen_count;
  Bit_map prev;
  Bit_map cur;
} Game_of_life;

Game_of_life construct_Game_of_life(Bit_map start, int width, int height);

Bit_map generation(Game_of_life game);

#endif //LAB1_14_SRC_GAME_OF_LIFE_H_
