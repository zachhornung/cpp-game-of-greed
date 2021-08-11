#include "../header_files/game_logic.h"


// member definitions for banker class
void Banker::shelf(int num){
  shelved += num;
};

int Banker::bank(){
  int deposit = shelved;
  balance += deposit;
  shelved = 0;
  return deposit;
};

int Banker::clear_shelf(){
  shelved = 0;
  return shelved;
};

// member definitions for game_logic class
std::vector<int> Game_logic::roll_dice(int num_dice){
  
};

int Game_logic::calculate_score(){

};
std::vector<int> Game_logic::get_scorers(std::vector<int> dice){

};
bool Game_logic::validate_keepers(std::vector<int> roll, std::vector<int> keepers){

};