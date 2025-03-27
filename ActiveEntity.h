//
// Created by linkl on 3/25/2025.
//

#ifndef ACTIVEENTITY_H
#define ACTIVEENTITY_H

#include "Map.h"

class Entity;

class ActiveEntity : public Entity {
protected:
  Map* map;

public:
  ActiveEntity(Map *map, const Vector position, const char symbol) : Entity(position, symbol), map(map) {map->add(this);}

  void move(Vector translation);
  void move(const int x, const int y) {move(Vector(x, y));}
  Room& getRoom() const {return map->getRoom(position);}
};


#endif //ACTIVEENTITY_H
