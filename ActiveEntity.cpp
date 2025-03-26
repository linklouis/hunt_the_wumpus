//
// Created by linkl on 3/25/2025.
//

#include "ActiveEntity.h"

#include <iostream>

#include "Map.h"

void ActiveEntity::move(const int x, const int y) {
  std::cout << x << " " << y << std::endl;
  Room& destination = map->getRoom(this->x + x, this->y + y);
  map->getRoom(this->x, this->y).transferEntity(destination, this);
  this->x += x;
  this->y += y;
}

