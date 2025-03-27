//
// Created by linkl on 3/25/2025.
//

#include "Wumpus.h"

#include <iostream>


bool Wumpus::playerEnters(Player &player) {
  std::cout << std::endl << "In front of you is the Wumpus! ";
  if (player.defend()) {
    std::cout << "You killed it!! >:0" << std::endl;
  } else {
    std::cout << "You are devoured." << std::endl;
  }
  exit(0);
}