//
// Created by linkl on 3/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "ActiveEntity.h"


class Player : public ActiveEntity {
  int numBullets = 1;
  int numKnives = 0;

  public:
  Player(const int x, const int y, const char symbol) : ActiveEntity(x, y, symbol) {}

};



#endif //PLAYER_H
