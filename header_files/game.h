#ifndef GAME_H
#define GAME_H

#include "game_functions.h"

class Game : public Game_functions {
  private:
    void play_round();

  public:
    void play();
};

#endif