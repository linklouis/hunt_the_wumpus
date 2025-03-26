//
// Created by linkl on 3/25/2025.
//

#include "Wumpus.h"

#include <iostream>

std::string Wumpus::getHintMessage(const int playerX, const int playerY) {
  if (isAdjacent(playerX, playerY)) return "A stick snaps nearby...";
  return "";
}

bool Wumpus::playerEnters(class Player &player) {
  std::cout << std::endl << "In front of you is the Wumpus! ";
  if (player.defend()) {
    std::cout << "You killed it!! >:0" << std::endl;
  } else {
    std::cout << "You are devoured." << std::endl;
  }
  exit(0);
}