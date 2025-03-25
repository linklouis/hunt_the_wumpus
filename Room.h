//
// Created by linkl on 3/25/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include <algorithm>
#include <memory>

#include "Entity.h"
#include <vector>

using namespace std;

class Room {
  vector<unique_ptr<Entity>> contents;
  string description;
  bool navigable;

public:
  explicit Room(const bool navigable = false, const string &description = "") :description(description), navigable(navigable) {}
  Room(const Room& other) = delete; // Delete copy constructor
  Room& operator=(const Room& other) = delete; // Delete assignment operator

  ~Room() {
    contents.clear();
  }

  void addEntity(unique_ptr<Entity> entity) {contents.push_back(move(entity));}
  void transferEntity(Room& destination, const Entity* entity);
  char getSymbol() const;

private:
  unique_ptr<Entity> removeEntity(const Entity* entity);
};



#endif //ROOM_H
