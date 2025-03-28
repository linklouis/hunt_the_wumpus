//
// Created by linkl on 3/27/2025.
//

#ifndef REMAINS_H
#define REMAINS_H
#include "Entity.h"
#include "Wumpus.h"


class Remains final : public Entity {
public:
  enum LootType {
    KNIFE,
    BULLET,
    NOTHING
  };

private:
  bool hasLoot = true;
  std::string description;
  std::string lootDescription;
  std::string afterCollectionText;
  LootType loot;

public:
  explicit Remains(Vector position, const Wumpus &wumpus, int descriptionNum);

  std::string getHintMessage(const Vector playerPosition) override {return isAdjacent(playerPosition) ? "A chill runs down your spine." : "";}

  bool playerEnters(Player &player) override;

private:
  void getInput(Player &player);
};



#endif //REMAINS_H
