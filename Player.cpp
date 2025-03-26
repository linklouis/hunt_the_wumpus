//
// Created by linkl on 3/25/2025.
//

#include "Player.h"

#include <iostream>

bool Player::defend() {
  if (numKnives > 0) {
    numKnives--;
    cout << std::endl << "You use a knife! Remaining: " << numKnives << std::endl;
    return true;
  }
  if (numBullets > 0) {
    numBullets--;
    cout << std::endl << "You shoot! Remaining bullets: " << numBullets << std::endl;
    return true;
  }
  return false;
}
