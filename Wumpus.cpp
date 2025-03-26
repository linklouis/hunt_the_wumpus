//
// Created by linkl on 3/25/2025.
//

#include "Wumpus.h"

#include <iostream>

std::string Wumpus::getHintMessage(const int playerX, const int playerY) {
  if (isAdjacent(playerX, playerY)) return "A stick snaps nearby...";
  return "";
}

bool Wumpus::playerEnters(Player player) {
  std::cout << std::endl << "You found the Wumpus! You are devoured." << std::endl;
  exit(0);
}