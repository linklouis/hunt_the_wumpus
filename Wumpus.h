//
// Created by linkl on 3/25/2025.
//

#ifndef WUMPUS_H
#define WUMPUS_H
#include "Entity.h"
#include "Player.h"


class Wumpus final : public Entity {
public:
  Wumpus(const int x, const int y) :Entity(x, y, 'W') {}

  std::string getHintMessage(int playerX, int playerY) override;

  bool playerEnters(class Player &player) override;
};



#endif //WUMPUS_H
