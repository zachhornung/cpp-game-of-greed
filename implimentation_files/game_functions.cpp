#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ostream>
#include <iterator>

#include "../header_files/game_functions.h"



// Game_functions::Game_functions(int num_rounds) : num_rounds(num_rounds){};

void Game_functions::bank_points(){
  int banked = banker.bank();
  std::cout << "You banked " << banked << " points in round " << round_number << std::endl;
  std::cout << "Total score is " << banker.get_balance() << " points" << std::endl;
};

void Game_functions::quit_game(){
  std::cout << "Thanks for playing. You earned " << banker.get_balance() << " points." << std::endl;
  std::exit(EXIT_SUCCESS);
};

std::vector<int> Game_functions::get_and_format_user_input(){
  std::string s;
  std::vector<int> user_input;
  std::cin >> s;

  for (int i = 0; i < s.size(); ++i){
    if (isdigit(s[i])){
      int num = s[i]-48;
      user_input.push_back(num);
    }
    if (s[i] == 113) quit_game();
  }
  
  return user_input;
};

std::vector<int> Game_functions::validate_user_input(std::vector<int> dice_roll){

  std::vector<int> user_input = get_and_format_user_input();
  
  bool input_is_valid = manager.validate_keepers(dice_roll, user_input);
  if (input_is_valid) return user_input;

  std::cout << "Cheater!!! Or possibly made a typo..." << std::endl;

  while (!input_is_valid){
    print_roll(dice_roll);
    std::cout << "Enter dice to keep, or (q)uit:" << std::endl;
    input_is_valid = manager.validate_keepers(dice_roll, user_input);
    if (input_is_valid) return user_input;
  }

};

void Game_functions::print_roll(std::vector<int> roll){

  std::cout << "*** ";
  for (auto item : roll) std::cout << item << " ";
  std::cout << " ***" << std::endl;
};

void Game_functions::calculate_remaining_dice(std::vector<int> roll, std::vector<int> input){ 
  for (auto die : roll){
    bool die_is_in_input = std::find(input.begin(), input.end(), die) != input.end();
    if(die_is_in_input) {
      --dice_count;
    }
  }
};

void Game_functions::print_zilcher(){
  std::cout << "****************************************" << std::endl;
  std::cout << "**        Zilch!!! Round over         **" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "You banked 0 points in round " << round_number << std::endl;
  std::cout << "Total score is " << banker.get_balance() << std::endl;
  banker.clear_shelf();
};

std::vector<int> Game_functions::roll_the_dice(){
  std::cout << "Rolling " << dice_count << " dice..." << std::endl;
  std::vector<int> dice_roll = manager.roll_dice(dice_count);
  print_roll(dice_roll);
  return dice_roll;
};

void Game_functions::shelve_points_and_adjust_dice_count(std::vector<int> dice_roll, std::vector<int> user_input){
  int score = manager.calculate_score(user_input);
  banker.shelf(score);
  calculate_remaining_dice(dice_roll, user_input);
  std::cout << "You have " << banker.get_shelved() << " unbanked points and " << dice_count << " dice remaining." << std::endl;
};