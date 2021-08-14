#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <random>
#include <unordered_map>

// global variables here
const int scoresheet[7][6] = {
      {100, 200, 1000, 2000, 3000, 4000}, 
      {0, 0, 200, 400, 600, 800}, 
      {0, 0, 300, 600, 900, 1200}, 
      {0, 0, 400, 800, 1200, 1600}, 
      {50, 100, 500, 1000, 1500, 2000},
      {0, 0, 600, 1200, 1800, 2400},
      {1500, 1500, 0, 0, 0, 0}
    };

// class definitions start here
class Banker{
  private:
    int shelved = 0, balance = 0;

  public:
    void shelf(int num);
    int bank();
    int clear_shelf();
    int get_balance();
    int get_shelved();
};


class Game_logic{
  private:
    std::unordered_map<int, int> occurrences;
    std::vector<int> keys;
    std::vector<int> values;

  public:
    std::vector<int> roll_dice(int num_dice);
    int calculate_score(std::vector<int> dice);
    std::vector<int> get_scorers(std::vector<int> dice);
    bool validate_keepers(std::vector<int> roll, std::vector<int> keepers);
};

#endif