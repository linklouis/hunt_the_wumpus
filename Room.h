//
// Created by linkl on 3/25/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>

#include "Entity.h"
#include <vector>

using namespace std;

class Room {
  vector<unique_ptr<Entity>> contents;
  string description;
  bool navigable;

public:
  explicit Room(const bool navigable = false, const string &description = "Just more forest.") :description(description), navigable(navigable) {}
  Room(const Room& other) = delete; // Delete copy constructor
  Room& operator=(const Room& other) = delete; // Delete assignment operator

  ~Room() {contents.clear();}

  bool forEach(const function<bool(const std::unique_ptr<Entity>&)>& func);


  void addEntity(unique_ptr<Entity> entity) {contents.push_back(move(entity));}
  void transferEntity(Room& destination, const Entity* entity);
  char getSymbol() const;
  string getDescription() const {return description;}

private:
  unique_ptr<Entity> removeEntity(const Entity* entity);
};



#endif //ROOM_H
