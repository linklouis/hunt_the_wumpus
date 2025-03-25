//
// Created by linkl on 3/25/2025.
//

#ifndef MAP_H
#define MAP_H
#include "Room.h"
#include <map>



class Map {
  static constexpr int SIZE = 6;
  Room room[SIZE][SIZE];

public:
  Room getRoom(int x, int y);

};



#endif //MAP_H
