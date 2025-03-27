//
// Created by linkl on 3/25/2025.
//

#ifndef MAP_H
#define MAP_H
#include "Room.h"


class Map {
public:
  static constexpr int WIDTH = 6;
  static constexpr int HEIGHT = 7;
  Map();
  ~Map();
  Map(const Map& other) = delete; // Delete copy constructor
  Map& operator=(const Map& other) = delete; // Delete assignment operator

  Room& getRoom(const int x, const int y) {return rooms[x][y];}
  Room& getRoom(const Vector position) {return rooms[position.getX()][position.getY()];}
  void add(Entity* entity) {getRoom(entity->getPosition()).addEntity(unique_ptr<Entity>(entity));}
  void display() const;
  Vector size() const {return Vector(WIDTH, HEIGHT);}

private:
  Room rooms[WIDTH][HEIGHT];
};



#endif //MAP_H
