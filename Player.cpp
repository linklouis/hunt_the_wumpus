//
// Created by linkl on 3/25/2025.
//

#include "Player.h"

#include <iostream>

bool Player::defend(const int threatLevel) {
  if (numKnives == 0 && numBullets == 0) return false;
  cout << "Defend yourself? K)nife[" << numKnives << "] G)un[" << numBullets << "]: ";
  if (getDefenceInput() || threatLevel <= 0) return true;
  cout << "Your opponent shrugs off the wound." << endl;
  return false;
}

bool Player::getDefenceInput() {
  char input;
  cin >> input;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
  switch (input) {
    case 'K': case 'k': {
      if (numKnives == 0) {
        cout << "You don't have any knives!";
        return getDefenceInput();
      }
      numKnives--;
      cout << endl << "You slash desperately with your knife!"
          "\nIt embeds itself into your foe, the handle breaking off as the blade sticks."
          "\nRemaining knives: " << numKnives << endl;
    }
      return false;
    case 'G': case 'g': {
      if (numBullets == 0) {
        cout << "You don't have any bullets!";
        return getDefenceInput();
      }
      numBullets--;
      cout << endl << "You shoot!"
          "\nRemaining bullets: " << numBullets << endl;
    }
      return true;
    default: cout << "Command not recognized. Please try again." << endl;
    return getDefenceInput();
  }
}
