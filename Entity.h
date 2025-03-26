//
// Created by linkl on 3/25/2025.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity {
  char symbol = ' ';

protected:
  int x;
  int y;

  bool isAdjacent(int otherX, int otherY) const;

public:
  virtual ~Entity() = default;

  Entity(const int x, const int y, const char symbol) :symbol(symbol), x(x), y(y) {}

  virtual std::string getHintMessage(int playerX, int playerY) = 0;
  virtual bool playerEnters(class Player &player) = 0;

  char getSymbol() const {return symbol;}

  int getX() const {return x;}
  int getY() const {return y;}
};


#endif //ENTITY_H
