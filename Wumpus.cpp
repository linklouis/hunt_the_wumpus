//
// Created by linkl on 3/25/2025.
//

#include "Wumpus.h"

std::string Wumpus::getHintMessage(const int playerX, const int playerY) {
  if (isAdjacent(playerX, playerY)) return "A stick snaps nearby...";
  return "";
}

std::string Wumpus::playerEnters(Player player) {
  return "You found the Wumpus!";
}