#include <vector>
#include<string>
#include "../header_files/game.h"

void Game::play_round(){
  dice_count = 6;
  std::cout << "Starting round " << round_number << std::endl;

  while (dice_count > 0){
    std::vector<int> dice_roll = roll_the_dice();
    int score = manager.calculate_score(dice_roll);
    if (score == 0){
      print_zilcher();
      return;
    }

    std::cout << "Enter dice to keep, or (q)uit:" << std::endl;
    std::vector<int> user_input = validate_user_input(dice_roll);
    shelve_points_and_adjust_dice_count(dice_roll, user_input);
    std::cout << "(r)oll again, (b)ank your points or (q)uit:" << std::endl;

    std::string decision;
    std::cin >> decision;

    if (dice_count == 0) dice_count = 6;

    if (decision == "q") quit_game();

    if (decision == "r") continue;

    if (decision == "b") {
      bank_points();
      return;
    }
  }
};

// Game::Game(int num_rounds) : Game_functions(num_rounds){};

void Game::play(){
  std::cout << "Welcome to Game of Greed" << std::endl;
  std::cout << "(y)es to play or (n)o to decline" << std::endl;
  std::string play;
  std::cin >> play;

  if (play == "n") std::cout << "Ok, maybe another time." << std::endl;

  if (play == "y"){
    while(++round_number <= num_rounds) play_round();
    std::cout << "Thanks for playing. You earned " << banker.get_balance() << " points" << std::endl;
  }
};