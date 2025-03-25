//
// Created by linkl on 3/25/2025.
//

#ifndef WUMPUS_H
#define WUMPUS_H
#include "Entity.h"
#include "Player.h"


class Wumpus : public Entity {
public:
  Wumpus(const int x, const int y) :Entity(x, y, 'W') {}

  std::string getHintMessage(int playerX, int playerY) override;
  std::string playerEnters(Player player) override;
};



#endif //WUMPUS_H
