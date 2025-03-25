//
// Created by linkl on 3/25/2025.
//

#ifndef MAP_H
#define MAP_H
#include "Room.h"
#include <map>



class Map {
  static constexpr int SIZE = 20;
  std::map<std::char, int> roomTypes = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
  };
  Room room[SIZE][SIZE];

public:

};



#endif //MAP_H
