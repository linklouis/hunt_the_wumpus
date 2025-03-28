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
  bool defend(int threatLevel=0);
  Room& getAdjacentRoom(const Vector direction) const {return map->getRoom(getPosition() + direction);}
  string getKnife() {numKnives++; return "Knives: " + to_string(numKnives);}
  string getBullet() {numBullets++; return "Bullets: " + to_string(numBullets);}

private:
  bool getDefenceInput();
};



#endif //PLAYER_H
