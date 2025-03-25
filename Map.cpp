//
// Created by linkl on 3/25/2025.
//

#include "Map.h"

#include <iostream>

using namespace std;

Map::Map() {
  // for (int i = 0; i < SIZE; ++i) {
  //   for (int j = 0; j < SIZE; ++j) {
  //     new (&rooms[i][j]) Room();
  //   }
  // }
}

Map::~Map(){
  // for (int i = 0; i < SIZE; ++i) {
  //   for (int j = 0; j < SIZE; ++j) {
  //     rooms[i][j].~Room();
  //   }
  // }
}

void Map::display() const {
  cout << endl;
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      cout << rooms[x][y].getSymbol() << " ";
    }
    cout << endl;
  }
}
