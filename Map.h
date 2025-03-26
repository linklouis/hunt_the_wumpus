//
// Created by linkl on 3/25/2025.
//

#ifndef MAP_H
#define MAP_H
#include "Room.h"


class Map {
public:
  static constexpr int SIZE = 6;
  Map();
  ~Map();
  Map(const Map& other) = delete; // Delete copy constructor
  Map& operator=(const Map& other) = delete; // Delete assignment operator

  Room& getRoom(const int x, const int y) {return rooms[x][y];}
  void add(Entity* entity) {getRoom(entity->getX(), entity->getY()).addEntity(unique_ptr<Entity>(entity));}
  void display() const;

private:
  Room rooms[SIZE][SIZE];
};



#endif //MAP_H
