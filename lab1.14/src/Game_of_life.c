#include <stdio.h>
#include "Game_of_life.h"

Game_of_life construct_Game_of_life(Bit_map start, int width, int height) {
  Game_of_life game;
  game.height = height;
  game.width = width;
  game.gen_count = 0;
  game.prev = construct_Bit_map(start.width, start.height);
  game.cur = construct_copy_Bit_map(start);
  return game;
}

Bit_map generation(Game_of_life game) {
  destruct_Bit_map(&game.prev);
  game.prev = construct_copy_Bit_map(game.cur);

  game.gen_count++;
  for (int i = 0; i < game.height; i++)
    for (int j = 0; j < game.width; j++) {
      unsigned count = 0;
      if (get_bit(game.prev, i, j) == 0) {
        count = count_bits(game.prev, i, j, game.width, game.height);
        if (count != 2 && count != 3)
          change_bit(game.cur, i, j);
      } else {
        count = count_bits(game.prev, i, j, game.width, game.height);
        if (count == 3)
          change_bit(game.cur, i, j);
      }
    }

//  for (int i = 0; i < game.height; i++) {
//    for (int j = 0; j < game.width; j++)
//      printf("%d ", get_bit(game.cur, i, j));
//    printf("\n");
//  }
//  printf("\n");

  return game.cur;
}