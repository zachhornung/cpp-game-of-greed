#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <random>

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
};


class Game_logic{
  public:
    std::vector<int> roll_dice(int num_dice);
    static int calculate_score(std::vector<int> dice);
    static std::vector<int> get_scorers(std::vector<int> dice);
    static bool validate_keepers(std::vector<int> roll, std::vector<int> keepers);
};

#endif

// int main( void )
// {
//   std::random_device os_seed;
//   const u32 seed = os_seed();

//   engine generator( seed );
//   std::uniform_int_distribution< u32 > distribute( 1, 6 );

//   for( int repetition = 0; repetition < 10; ++repetition )
//     std::cout << distribute( generator ) << std::endl;
//   return 0;
// }