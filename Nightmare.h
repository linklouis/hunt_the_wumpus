//
// Created by linkl on 3/26/2025.
//

#ifndef NIGHTMARE_H
#define NIGHTMARE_H
#include "ActiveEntity.h"


class Nightmare final : public ActiveEntity {
  int activeTimer = 0;
  Vector home;
  const int HUNT_RANGE = 2;
  const int SOUND_RANGE = 3;
  int huntTimer = 3;

public:
  Nightmare(Map *map, const Vector position) : ActiveEntity(map, position, 'N'), home(position) {}
  std::string getHintMessage(Vector playerPosition) override;
  bool playerEnters(Player &player) override;
  void decrementTimer() {if (activeTimer > 0) activeTimer--;}
  // Should be the last thing to happen in the loop so it doesn't enter the player's room and attack them in the middle of a turn.
  // Also makes it more like it's "following" the player.
  void hunt(Player &player);

private:
  void returnHome() {
    move(home - position);
    resetHuntTimer();
  }
  void resetHuntTimer() {huntTimer = 3;}
  bool attack(Player &player);
};



#endif //NIGHTMARE_H
