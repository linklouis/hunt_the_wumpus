//
// Created by linkl on 3/25/2025.
//

#include "Treent.h"
#include <iostream>

using namespace std;

bool Treent::playerEnters(Player &player) {
  cout << endl << "Snakelike branches entangle your feet. You're hoisted into the air and dragged into the canopy!" << endl;
  if (player.defend()) {
    player.move(Vector::random(4, -2));
    cout << "You manage to escape from the branches. You fall back to the forest floor... Somewhere else." << endl;
    return true;
  }
  cout << "Your empty rifle falls out of the branches onto the ground. You are devoured." << endl;
  exit(0);
}
