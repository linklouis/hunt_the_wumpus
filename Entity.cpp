//
// Created by linkl on 3/25/2025.
//

#include "Entity.h"

bool Entity::isAdjacent(const int otherX, const int otherY) const {
  return (otherY == y && (otherX == x + 1 || otherX == x - 1)) || (otherX == x && (otherY == y + 1 || otherY == y - 1));
}

