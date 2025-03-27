//
// Created by linkl on 3/26/2025.
//

#include "Nightmare.h"

#include <math.h>
#include <valarray>

#include "Player.h"

std::string Nightmare::getHintMessage(const Vector playerPosition) {
  const int dist = home.dist(playerPosition);
  if (dist < HUNT_RANGE) return "You smell something foul. The forest is deathly quiet.";
  if (dist < SOUND_RANGE) return "Something inhuman screeches in the distance.";
  return "";
}

bool Nightmare::playerEnters(Player &player) {
  if (activeTimer > 0) return false;
  std::cout << std::endl << "A foul odor intensifies as a screech pierces through the silence. A Nightmare pounces on you from behind!";
  if (player.defend()) {
    std::cout << "You manage to ward off the beast... for now." << std::endl;
    returnHome();
    activeTimer = 2;
    moveTimer = 1;
    return true;
  }
  std::cout << "The Nightmare's screams of joy fill the night, drowning out those of it's prey. You are devoured." << std::endl;
  exit(0);
}

void Nightmare::hunt(const Player &player) {
  if (home.dist(player.getPosition()) < HUNT_RANGE) {
    if (moveTimer > 0) {
      moveTimer--;
      return;
    }
    Vector direc = player.getPosition() - getPosition();
    double absX = abs(direc.getX());
    double absY = abs(direc.getY());

    if      (absX > absY)     direc = Vector(direc.getX() / absX, 0); // The x distance is bigger
    else if (absX < absY)     direc = Vector(0, direc.getY() / absY); // The y distance is bigger
    else if (rand() % 2 == 0) direc = Vector(direc.getX() / absX, 0); // Same distance. Randomly choose to move on the x-axis
    else                      direc = Vector(0, direc.getY() / absY); // Randomly chose to move on the y-axis
    move(direc);
  } else {
    returnHome();
  }
  moveTimer = 1;
}

