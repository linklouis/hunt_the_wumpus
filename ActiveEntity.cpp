//
// Created by linkl on 3/25/2025.
//

#include "ActiveEntity.h"
#include "Map.h"

void ActiveEntity::move(const int x, const int y) const {
  Room& destination = map->getRoom(this->x + x, this->y + y);
  map->getRoom(this->x, this->y).transferEntity(destination, this);
}

