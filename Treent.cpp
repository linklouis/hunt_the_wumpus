//
// Created by linkl on 3/25/2025.
//

#include "Treent.h"
#include <iostream>

std::string Treent::getHintMessage(const int playerX, const int playerY) {
  if (isAdjacent(playerX, playerY)) return "Branches creak nearby.";
  return "";
}

bool Treent::playerEnters(Player &player) {
  std::cout << std::endl << "Snakelike branches entangle your feet. You're hoisted into the air and dragged into the canopy!";
  if (player.defend()) {
    player.move(rand() % 4 - 2, rand() % 4 - 2);  // Works without this line
    std::cout << "You manage to escape from the branches. You fall back to the forest floor... Somewhere else." << std::endl;  // But runs this line even when it breaks
    return true;
  }
  std::cout << "Your empty rifle falls out of the branches onto the ground. You are devoured." << std::endl;
  exit(0);
}
