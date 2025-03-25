//
// Created by linkl on 3/25/2025.
//

#ifndef ACTIVEENTITY_H
#define ACTIVEENTITY_H
#include "Entity.h"
#include "Map.h"


class ActiveEntity : public Entity {
  Map map;

public:
  ActiveEntity(const Map &map, const int x, const int y, const char symbol) : Entity(x, y, symbol), map(map) {}

  void move(int x, int y);

};



#endif //ACTIVEENTITY_H
