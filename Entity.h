//
// Created by linkl on 3/25/2025.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <string>

#include "Player.h"


class Entity {
  char symbol;

protected:
  int x;
  int y;

  bool isAdjacent(int otherX, int otherY) const;

public:
  virtual ~Entity() = default;

  Entity(const int x, const int y, const char symbol) :symbol(symbol), x(x), y(y) {}

  virtual std::string getHintMessage(int playerX, int playerY) = 0;
  virtual std::string playerEnters(Player player) = 0;
};


#endif //ENTITY_H
