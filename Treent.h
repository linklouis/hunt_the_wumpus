//
// Created by linkl on 3/25/2025.
//

#ifndef TREENT_H
#define TREENT_H
#include "Entity.h"
#include "Player.h"


class Treent final : public Entity {
public:
  Treent(const int x, const int y) :Entity(x, y, 'T') {}

  std::string getHintMessage(int playerX, int playerY) override;

  bool playerEnters(class Player &player) override;

};



#endif //TREENT_H
