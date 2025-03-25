//
// Created by linkl on 3/25/2025.
//

#ifndef MAP_H
#define MAP_H
#include "Room.h"


class Map {
  static constexpr int SIZE = 6;
  Room rooms[SIZE][SIZE];

public:
  Map();
  ~Map();

  Room& getRoom(const int x, const int y) {return rooms[x][y];}
  void add(Entity* entity) {getRoom(entity->getX(), entity->getY()).addEntity(unique_ptr<Entity>(entity));}
  void display() const;

};



#endif //MAP_H
