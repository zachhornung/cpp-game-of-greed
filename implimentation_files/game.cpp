#include <vector>
#include <string>
#include "../header_files/game.h"

// this is the logic flow for one round of gameplay
void Game::play_round(){
  // always starts with 6 dice
  dice_count = 6;
  std::cout << "Starting round " << round_number << std::endl;
  // as long as there are dice to roll, keep repeating the following series of events
  while (dice_count > 0){
    std::vector<int> dice_roll = roll_the_dice();
    int score = manager.calculate_score(dice_roll);
    if (score == 0){
      print_zilcher();
      // if there are no scoring dice, the round is over
      return;
    }
    // if at least one die scores, ask the user which dice they want to keep. users must keep at least one scoring dice, per the game rules
    std::cout << "Enter dice to keep, or (q)uit:" << std::endl;
    std::vector<int> user_input = validate_user_input(dice_roll);
    shelve_points_and_adjust_dice_count(dice_roll, user_input);
    // ask the user if they want to keep rolling (risking shelved points), bank their shelved points, or quit
    std::cout << "(r)oll again, (b)ank your points or (q)uit:" << std::endl;

    // get the users decision
    std::string decision;
    std::cin >> decision;
    // if every die scores and is kept, the user gets a fresh set of dice
    if (dice_count == 0) dice_count = 6;

    if (decision == "q") quit_game();

    if (decision == "r") continue;
    // the round is over if the user banks their points
    if (decision == "b") {
      bank_points();
      return;
    }
  }
};

// initiates the game
void Game::play(){
  std::cout << "Welcome to Game of Greed" << std::endl;
  std::cout << "(y)es to play or (n)o to decline" << std::endl;
  std::string play;
  std::cin >> play;

  if (play == "n") std::cout << "Ok, maybe another time." << std::endl;

  if (play == "y"){
    // while there are still rounds to play, play one round of the game
    while(++round_number <= num_rounds) play_round();
    // after all rounds have been played, show the user their score
    std::cout << "Thanks for playing. You earned " << banker.get_balance() << " points" << std::endl;
  }
};