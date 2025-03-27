//
// Created by linkl on 3/25/2025.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <string>

#include "Vector.h"

class Entity {
  char symbol = ' ';

protected:
  Vector position;

  bool isAdjacent(const Vector otherPosition) const {return position.dist(otherPosition) == 1;}
  int getX() const {return position.getX();}
  int getY() const {return position.getY();}

public:
  virtual ~Entity() = default;

  Entity(const Vector position, const char symbol) :symbol(symbol), position(position) {}

  virtual std::string getHintMessage(Vector playerPosition) = 0;
  virtual bool playerEnters(class Player &player) = 0;

  char getSymbol() const {return symbol;}

  Vector getPosition() const {return position;}
};


#endif //ENTITY_H
