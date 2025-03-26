//
// Created by linkl on 3/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "ActiveEntity.h"


class Player final : public ActiveEntity {
  int numBullets = 1;
  int numKnives = 0;

public:
  Player(Map *map, const int x, const int y) : ActiveEntity(map, x, y, 'P') {}
  std::string getHintMessage(int playerX, int playerY) override {return  "";}
  bool playerEnters(Player player) override {return  false;}
};



#endif //PLAYER_H
