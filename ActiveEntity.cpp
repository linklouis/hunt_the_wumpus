//
// Created by linkl on 3/25/2025.
//

#include "ActiveEntity.h"

#include "Map.h"

void ActiveEntity::move(const Vector translation) {
  const Vector newPosition = (getPosition() + translation).clamp(Vector(0), map->size());
  Room& destination = map->getRoom(newPosition);
  getRoom().transferEntity(destination, this);
  position = newPosition;
}

