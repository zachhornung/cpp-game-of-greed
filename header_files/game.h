#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "./game_functions.h"
#include "./game_logic.h"

class Game : protected Game_functions {
  private:
    void play_round();
  public:
    void play();
};

#endif