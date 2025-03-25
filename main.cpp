#include "Map.h"
#include "Player.h"
#include "Wumpus.h"


bool runOneGameLoop(const Map& map);


int main() {
  auto map = Map();
  const auto playerPtr = new Player(&map, 3, 3);
  const auto wumpusPtr = new Wumpus(rand() % 6, rand() % 6);
  map.add(wumpusPtr);

  while (true) {
    if (!runOneGameLoop(map)) return 0;
  }
}

bool runOneGameLoop(const Map& map) {
  map.display();
  return false;
}
