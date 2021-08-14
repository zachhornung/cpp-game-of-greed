#include "../header_files/game_logic.h"
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

// member definitions for banker class
// puts the score amount on the shelf. shelved points may be lost if the user rolls again without banking shelved points
void Banker::shelf(int num){
  shelved += num;
};

// saves shelved points to the balance, and resets the shelf for the next round
int Banker::bank(){
  int deposit = shelved;
  balance += deposit;
  shelved = 0;
  return deposit;
};

// removes points on the shelf
int Banker::clear_shelf(){
  shelved = 0;
  return shelved;
};

// getter for private member balance
int Banker::get_balance(){
  return balance;
}

// getter for private member shelved
int Banker::get_shelved() {
  return shelved;
};

// member definitions for game_logic class

// randomly generates numbers, representing rolling a given number of dice. returns the roll
std::vector<int> Game_logic::roll_dice(int num_dice){
// this always returns a sorted vector, reduces downstream work
  std::vector<int> roll;
  // for as many times as specified, generate a random number in the acceptable range and push it into the roll
  for (int i = 0; i < num_dice; i++) {
    int die = (rand() % (7 - 1)) + 1;
    roll.push_back(die);
  }
  // sort the dice to reduce potential downstream work
  std::sort(roll.begin(), roll.end());
  // return the sorted dice roll
  return roll;
};

// clears previous data from the hashmap and the related key/value vectors
void Game_logic::clear_map(){
  occurrences.clear();
  keys.clear();
  values.clear();
};

// counts the number of times a die was rolled
void Game_logic::count_dice_roll(std::vector<int> dice){
  for (auto die : dice){
    occurrences[die] = std::count(dice.begin(), dice.end(), die);
  }

  for (auto kv : occurrences) {
    keys.push_back(kv.first); 
    values.push_back(kv.second);
  }
};

// calculates the score for a given dice roll. 
int Game_logic::calculate_score(std::vector<int> dice){

  // clear and previous data from the hashmap, keys vector, and values vector before filling them again

  clear_map();

  // count how many times each die was rolled

  count_dice_roll(dice);

  // first check special scoring cases

  // straight
  std::vector<int> straight{1,2,3,4,5,6};
  if (dice == straight) return scoresheet[6][0];

  // three of a kind
  if (occurrences.size() == 3){
    if (occurrences[values[0]] == 2 && occurrences[values[1]] == 2 && occurrences[values[2]] == 2) return scoresheet[6][0];
  }

  // then check regular scores
  int score{0};
  for (auto die : keys) {
    int num_rolled = occurrences[die];
    score += scoresheet[die-1][num_rolled-1];
    };

  // return total score
  return score;
};

// checks to make sure that the user is keeping dice that are actually in the roll
bool Game_logic::validate_keepers(std::vector<int> roll, std::vector<int> keepers){

  // go through each die the user has specified to keep
  for (auto die : keepers){
    // make sure that it is within the acceptable range
    if (die > 0 && die < 7){
      // if it is, then check to make sure that they arent keeping more than are available
      int keeper_count = std::count(keepers.begin(), keepers.end(), die);
      int roll_count = std::count(roll.begin(), roll.end(), die);
      // if they keep more than are available, return that the user input is not valid
      if (keeper_count > roll_count) return false;
    }
    // if the number is not in the acceptable range, return that the user input is not valid
    else return false;
  }
  // if the loop finishes running, then return that the user input is valid
  return true;
};
