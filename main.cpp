#include <iostream>
#include <map>

#include "Map.h"
#include "Nightmare.h"
#include "Player.h"
#include "Treent.h"
#include "Wumpus.h"

using namespace std;

void runOneGameLoop(const Map& map, Player& player, Wumpus& wumpus, Treent& treent, Nightmare& nightmare);
void takeInput(Player& player, const map<char, bool> &validDirections);


[[noreturn]] int main() {
  srand(time(nullptr));
  auto map = Map();
  const auto playerPtr = new Player(&map, Vector(3));
  Vector position = Vector::random(6);
  while (position == playerPtr->getPosition()) {
    position = Vector::random(6);
  }
  const auto wumpusPtr = new Wumpus(position);
  while (position == playerPtr->getPosition() || position == wumpusPtr->getPosition()) {
    position = Vector::random(6);
  }
  const auto treentPtr = new Treent(position);
  while (position.dist(playerPtr->getPosition()) < 2|| position == wumpusPtr->getPosition() || position == treentPtr->getPosition()) {
    position = Vector::random(6);
  }
  const auto nightmarePtr = new Nightmare(&map, position);
  map.add(wumpusPtr);
  map.add(treentPtr);

  while (true) {
    runOneGameLoop(map, *playerPtr, *wumpusPtr, *treentPtr, *nightmarePtr);
  }
}


void printHelp() {
  cout << "Your goal is to find and hunt a creature known as the Wumpus. It is sneaky but large. Keep an ear out for strange noises."
          "\nYou are in a dangerous forest with several hazards."
          "\nWatch out for Treents:"
          "\n\tCarnivorous living trees who scoop up unsuspecting prey and pull them into their network of branches."
          "\n\tIf you manage to escape, pray that you were not swept too far away."
          "\n\tThe creaking of their branches is known as a heralder of death."
          "\nAlso be aware of Nightmares:"
          "\n\tIf you're close enough, you might hear their screams."
          "\n\tGet any closer, and they'll go silent as they start their hunt."
          "\n\tIf that happens, pray you don't smell their repugnant scent, or it may be the last thing you ever smell."
          "\n\tNightmares won't leave their territory, but if you stay close for too long, it will come find you."
          "\nYou're equipped with a rifle and a single shot."
          "\n\tIt can be used to defend yourself or to hunt your target."
          "\n\tIf you use it before you find your foe, search for what's left of those who came before you and pray that they have ammunition or a blade."
  << endl << endl;
}

void printBlockedPaths(map<char, bool> validDirections) {
  bool blocked = false;
  for (const auto& pair : validDirections) {
    if (!pair.second) blocked = true;
  }
  if (blocked) {
    cout << "The forest to the ";
    if (!validDirections['N']) cout << "North, ";
    if (!validDirections['S']) cout << "South, ";
    if (!validDirections['E']) cout << "East, ";
    if (!validDirections['W']) cout << "West ";
    cout << "is too thick to pass through.";
  }
}

void printValidCommands(map<char, bool> validDirections) {
  cout << endl << endl << "Action:";
  if (validDirections['N']) cout << " N)orth";
  if (validDirections['S']) cout << "  S)outh";
  if (validDirections['E']) cout << "  E)ast";
  if (validDirections['W']) cout << "  W)est";
  cout << "  H)elp  Q)uit: ";
}

void validateInput(Player& player, map<char, bool> validDirections, const char input) {
  if (validDirections.contains(input) && !validDirections[input]) {
    cout << "Can't go that way!";
    takeInput(player, validDirections);
    return;
  }

  switch (input) {
    case 'N': player.move(0, -1); break;
    case 'S': player.move(0, 1); break;
    case 'W': player.move(-1, 0); break;
    case 'E': player.move(1, 0); break;

    case 'H': printHelp(); break;
    case 'Q': exit(0);

    default:
      cout << "Command not recognized. Try again. ";
    takeInput(player, validDirections);
    break;
  }
}

void takeInput(Player& player, const map<char, bool> &validDirections) {
  printValidCommands(validDirections);

  char input;
  cin >> input;
  cout << endl;
  validateInput(player, validDirections, toupper(input));
}

map<char, bool> getValidDirections(const Map& map, const Player& player) {
  auto validDirections = std::map<char, bool>();
  if (player.getPosition().getY() == 0 || !player.getAdjacentRoom(Vector(0, -1)).isNavigable()) {
    validDirections['N'] = false;
  } else validDirections['N'] = true;
  if (player.getPosition().getY() == map.HEIGHT - 1 || !player.getAdjacentRoom(Vector(0, 1)).isNavigable()) {
    validDirections['S'] = false;
  } else validDirections['S'] = true;
  if (player.getPosition().getX() == 0 || !player.getAdjacentRoom(Vector(-1, 0)).isNavigable()) {
    validDirections['W'] = false;
  } else validDirections['W'] = true;
  if (player.getPosition().getX() == map.WIDTH || !player.getAdjacentRoom(Vector(1, 0)).isNavigable()) {
    validDirections['E'] = false;
  } else validDirections['E'] = true;
  return validDirections;
}

void requestInput(const Map& map, Player& player) {
  const auto validDirections = getValidDirections(map, player);
  printBlockedPaths(validDirections);
  takeInput(player, validDirections);
}

void runOneGameLoop(const Map& map, Player& player, Wumpus& wumpus, Treent& treent, Nightmare& nightmare) {
  nightmare.decrementTimer();
  Room& room = player.getRoom();
  cout << room.getDescription() << " ";
  map.display();  // TODO remove

  if (room.forEach([&player](const std::unique_ptr<Entity>& entity) {
    return entity->playerEnters(player);
  })) {
    return;
  }
  cout << treent.getHintMessage(player.getPosition()) << " ";
  cout << nightmare.getHintMessage(player.getPosition()) << " ";
  cout << wumpus.getHintMessage(player.getPosition()) << " ";

  nightmare.hunt(player);

  requestInput(map, player);
}
