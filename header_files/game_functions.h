#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <string>
#include <iostream>
#include "game_logic.h"

// class definitions start here
class Game_functions{
  private:
    Banker banker;
    int num_rounds;
    int round_number;
    int dice_count;

  public:
    Game_functions(int num_rounds);
    void bank_points();
    void quit_game();
    bool validate_user_input(std::vector<int> dice_roll);
    void print_roll();
    void calculate_remaining_dice();
    void print_zilcher();
    std::vector<int> roll_the_dice();
    void shelve_points_and_adjust_dice_count(std::vector<int> dice_roll, std::vector<int> user_input);
};

#endif