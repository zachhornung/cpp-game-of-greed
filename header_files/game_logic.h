#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <random>
#include <unordered_map>

// the banker class keeps track of scored points, points kept, and the functionality for managing points in a round of gameplay
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

// the game logic class holds core gameplay computations
class Game_logic{
  private:
    // first index in the scoresheet is the face value of the die, second index is the number of times that face value was rolled.
    // for example, rolling 6 ones would be scoresheet[0][5], with a score of 4000.
    const int scoresheet[7][6] = {
      {100, 200, 1000, 2000, 3000, 4000}, 
      {0, 0, 200, 400, 600, 800}, 
      {0, 0, 300, 600, 900, 1200}, 
      {0, 0, 400, 800, 1200, 1600}, 
      {50, 100, 500, 1000, 1500, 2000},
      {0, 0, 600, 1200, 1800, 2400},
      {1500, 1500, 0, 0, 0, 0}
    };
    std::unordered_map<int, int> occurrences;
    std::vector<int> keys;
    std::vector<int> values;
    void clear_map();
    void count_dice_roll(std::vector<int> dice);

  public:
    std::vector<int> roll_dice(int num_dice);
    int calculate_score(std::vector<int> dice);
    bool validate_keepers(std::vector<int> roll, std::vector<int> keepers);
};

#endif