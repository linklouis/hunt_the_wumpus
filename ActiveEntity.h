//
// Created by linkl on 3/25/2025.
//

#ifndef ACTIVEENTITY_H
#define ACTIVEENTITY_H

#include "Map.h"

class Entity;

class ActiveEntity : public Entity {
  Map* map;

public:
  ActiveEntity(Map *map, const int x, const int y, const char symbol) : Entity(x, y, symbol), map(map) {map->add(this);}

  void move(int x, int y);
  Room& getRoom() const {return map->getRoom(x, y);}
};


#endif //ACTIVEENTITY_H
