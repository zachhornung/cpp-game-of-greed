#ifndef GAME_H
#define GAME_H

#include "game_functions.h"

class Game : public Game_functions {
  private:
    void play_round();

  public:
    // Game(int num_rounds) : Game_functions(num_rounds){};
    void play();
};

#endif