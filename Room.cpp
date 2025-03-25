//
// Created by linkl on 3/25/2025.
//

#include "Room.h"

void Room::transferEntity(Room& destination, const Entity* entity) {
  if (unique_ptr<Entity> entityPtr = removeEntity(entity)) {
    destination.addEntity(move(entityPtr));
  }
}

unique_ptr<Entity> Room::removeEntity(const Entity* entity) {
  const auto it = ranges::find_if(contents,
                                  [&](const unique_ptr<Entity>& ptr) {
                                    return ptr.get() == entity;
                                  });

  if (it == contents.end()) return nullptr; // Entity not found

  unique_ptr<Entity> removedEntity = std::move(*it);
  contents.erase(it);
  return removedEntity;
}

char Room::getSymbol() const {
  if (contents.empty()) return '.';
  return contents.front().get()->getSymbol();
}