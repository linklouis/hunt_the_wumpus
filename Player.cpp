//
// Created by linkl on 3/25/2025.
//

#include "Player.h"

#include <iostream>

bool Player::defend() {
  if (numKnives == 0 && numBullets == 0) return false;
  cout << endl << "Defend yourself? K)nife[" << numKnives << "] G)un[" << numBullets << "]: ";
  getDefenceInput();
  return true;
}

void Player::getDefenceInput() {
  char input;
  cin >> input;
  switch (input) {
    case 'K': case 'k':
      if (numKnives == 0) {
        cout << "You don't have any knives!";
        getDefenceInput();
      } else {
        numKnives--;
        cout << endl << "You use a knife! Remaining: " << numKnives << endl;
      }
    return;
    case 'G': case 'g':
      if (numBullets == 0) {
        cout << "You don't have any bullets!";
        getDefenceInput();
      } else {
        numBullets--;
        cout << endl << "You shoot! Remaining bullets: " << numBullets << endl;
      }
    return;
    default: cout << "Command not recognized. Please try again." << endl;
    getDefenceInput();
  }
}
