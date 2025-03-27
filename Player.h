//
// Created by linkl on 3/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "ActiveEntity.h"


class Player final : public ActiveEntity {
  int numBullets = 1;
  int numKnives = 0;

public:
  Player(Map *map, const Vector position) : ActiveEntity(map, position, 'P') {}
  std::string getHintMessage(Vector playerPosition) override {return  "";}
  bool playerEnters(Player &player) override {return  false;}
  bool defend();

private:
  void getDefenceInput();
};



#endif //PLAYER_H
