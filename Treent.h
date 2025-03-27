//
// Created by linkl on 3/25/2025.
//

#ifndef TREENT_H
#define TREENT_H
#include "Entity.h"
#include "Player.h"


class Treent final : public Entity {
public:
  explicit Treent(const Vector position) :Entity(position, 'T') {}

  std::string getHintMessage(const Vector playerPosition) override {return isAdjacent(playerPosition) ? "Branches creak nearby." : "";}

  bool playerEnters(Player &player) override;

};



#endif //TREENT_H
