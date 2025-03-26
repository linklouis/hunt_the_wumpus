//
// Created by linkl on 3/25/2025.
//

#include "ActiveEntity.h"

#include "Map.h"

void ActiveEntity::move(int x, int y) {
  if (this->x + x < 0 || this->x + x > map->SIZE) {
    x = 0;
  }
  if (this->y + y < 0 || this->y + y > map->SIZE) {
    y = 0;
  }
  Room& destination = map->getRoom(this->x + x, this->y + y);
  map->getRoom(this->x, this->y).transferEntity(destination, this);
  this->x += x;
  this->y += y;
}

