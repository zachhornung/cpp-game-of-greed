#include "../header_files/game.h"
#include "../header_files/game_functions.h"
#include "../header_files/game_logic.h"
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

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

int Banker::get_balance(){
  return balance;
}

int Banker::get_shelved() {
  return shelved;
};

// member definitions for game_logic class
std::vector<int> Game_logic::roll_dice(int num_dice){
// this always returns a sorted vector, reduces downstream work
  std::vector<int> roll;

  for (int i = 0; i <= num_dice; i++) {
    int die = (rand() % (7 - 1)) + 1;
    roll.push_back(die);
  }

  std::sort(roll.begin(), roll.end());

  return roll;
};

int Game_logic::calculate_score(std::vector<int> dice){
  occurrences.clear();
  keys.clear();
  values.clear();
  // count how many times each die was rolled

  for (auto die : dice){
    occurrences[die] = std::count(dice.begin(), dice.end(), die);
  }

  for (auto kv : occurrences) {
    keys.push_back(kv.first); 
    values.push_back(kv.second);
  }

  // first check special scoring cases

  std::vector<int> straight{1,2,3,4,5,6};
  if (dice == straight) return scoresheet[6][0];

  if (occurrences.size() == 3){
    if (occurrences[values[0]] == 2 && occurrences[values[1]] == 2 && occurrences[values[2]] == 2) return scoresheet[6][0];
  }

  // then check regular scores
  int score{0};
  for (auto die : keys) {
    int num_rolled = occurrences[die];
    score += scoresheet[die-1][num_rolled-1];
    };

  return score;
};


std::vector<int> Game_logic::get_scorers(std::vector<int> dice){
  occurrences.clear();
  keys.clear();
  values.clear();
  // count how many times each die was rolled

  for (auto die : dice){
    occurrences[die] = std::count(dice.begin(), dice.end(), die);
  }

  for (auto kv : occurrences) {keys.push_back(kv.first); values.push_back(kv.second);}

  // find the dice that have a score associated with them
  std::vector<int> scoring_dice;
  for (auto die : keys){
    int score = scoresheet[die][occurrences[die]];
    scoring_dice.push_back(score);
  }

  return scoring_dice;
};

bool Game_logic::validate_keepers(std::vector<int> roll, std::vector<int> keepers){
  for (auto die : keepers){
    if (die > 0){
      int keeper_count = std::count(keepers.begin(), keepers.end(), die);
      int roll_count = std::count(roll.begin(), roll.end(), die);
      if (keeper_count > roll_count) return false;
    }
    else return false;
  }
  return true;
};
