//
// Created by linkl on 3/25/2025.
//

#ifndef WUMPUS_H
#define WUMPUS_H
#include "Entity.h"
#include "Player.h"


class Wumpus final : public Entity {
public:
  explicit Wumpus(const Vector position) :Entity(position, 'W') {}

  std::string getHintMessage(Vector playerPosition) override {return isAdjacent(playerPosition) ? "A stick snaps nearby..." : "";}

  bool playerEnters(Player &player) override;
};



#endif //WUMPUS_H
