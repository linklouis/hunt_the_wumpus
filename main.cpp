#include <iostream>
#include <map>

#include "Map.h"
#include "Nightmare.h"
#include "Player.h"
#include "Remains.h"
#include "Treent.h"
#include "Wumpus.h"

using namespace std;

Vector getValidPosition(const vector<Vector> &existingPositions, int minDist = 0);

void runOneGameLoop(const Map& map, Player& player, Nightmare& nightmare, const vector<Entity*>& entities);

void takeInput(Player& player, const map<char, bool> &validDirections);

[[noreturn]] int main() {
  srand(time(nullptr));
  auto map = Map();
  vector<Vector> occupiedPositions;

  const auto playerPtr = std::make_unique<Player>(&map, Vector(3));
  occupiedPositions.push_back(playerPtr->getPosition());

  const auto wumpusPtr = std::make_unique<Wumpus>(getValidPosition(occupiedPositions));
  occupiedPositions.push_back(wumpusPtr->getPosition());

  const auto treentPtr = std::make_unique<Treent>(getValidPosition(occupiedPositions));
  occupiedPositions.push_back(treentPtr->getPosition());

  const auto nightmarePtr = std::make_unique<Nightmare>(&map, getValidPosition(occupiedPositions, 2));
  occupiedPositions.push_back(nightmarePtr->getPosition());

  const auto remains1ptr = std::make_unique<Remains>(getValidPosition(occupiedPositions, 2), *wumpusPtr, 1);
  occupiedPositions.push_back(remains1ptr->getPosition());

  const auto remains2ptr = std::make_unique<Remains>(getValidPosition(occupiedPositions, 2), *wumpusPtr, 2);
  occupiedPositions.push_back(remains2ptr->getPosition());

  const auto remains3ptr = std::make_unique<Remains>(getValidPosition(occupiedPositions, 2), *wumpusPtr, 3);
  occupiedPositions.push_back(remains3ptr->getPosition());

  map.add(wumpusPtr.get());
  map.add(treentPtr.get());
  map.add(remains1ptr.get());
  map.add(remains2ptr.get());
  map.add(remains3ptr.get());

  const vector<Entity*> entities = { treentPtr.get(), nightmarePtr.get(), wumpusPtr.get(), remains1ptr.get(), remains2ptr.get(), remains3ptr.get() };

  while (true) {
    runOneGameLoop(map, *playerPtr, *nightmarePtr, entities);
  }
}

Vector getValidPosition(const vector<Vector> &existingPositions, int minDist) {
  Vector position = Vector::random(6);
  while (ranges::any_of(existingPositions,
                        [&position, minDist](const Vector& existingPos) { return position.dist(existingPos) < minDist || position == existingPos; })) {
    position = Vector::random(6);
      }
  return position;
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
          "\n\tGet any closer, and they'll go silent as they start their hunt, silently following."
          "\n\tIf that happens, pray you don't smell their repugnant scent, or it may be the last thing you ever smell."
          "\n\tNightmares won't leave their territory, but if you linger too long, it will come find you."
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
    case 'N': player.move(0, 1); break;
    case 'S': player.move(0, -1); break;
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
  if (player.getPosition().getY() == map.HEIGHT - 1 || !player.getAdjacentRoom(Vector(0, 1)).isNavigable()) {
    validDirections['N'] = false;
  } else validDirections['N'] = true;
  if (player.getPosition().getY() == 0 || !player.getAdjacentRoom(Vector(0, -1)).isNavigable()) {
    validDirections['S'] = false;
  } else validDirections['S'] = true;
  if (player.getPosition().getX() == 0 || !player.getAdjacentRoom(Vector(-1, 0)).isNavigable()) {
    validDirections['W'] = false;
  } else validDirections['W'] = true;
  if (player.getPosition().getX() == map.WIDTH - 1 || !player.getAdjacentRoom(Vector(1, 0)).isNavigable()) {
    validDirections['E'] = false;
  } else validDirections['E'] = true;
  return validDirections;
}

void requestInput(const Map& map, Player& player) {
  cout << endl;
  const auto validDirections = getValidDirections(map, player);
  printBlockedPaths(validDirections);
  takeInput(player, validDirections);
}

void runOneGameLoop(const Map& map, Player& player, Nightmare& nightmare, const vector<Entity*>& entities) {
  nightmare.decrementTimer();
  Room& room = player.getRoom();
  cout << room.getDescription() << " ";
  // map.display();

  if (room.forEach([&player](const std::unique_ptr<Entity>& entity) {
      return entity->playerEnters(player);
  })) {
    return;
  }

  for (const auto& entity : entities) {
    string hint = entity->getHintMessage(player.getPosition());
    cout << hint + (hint == "" ? "" : " ");
  }

  nightmare.hunt(player);
  requestInput(map, player);
}

