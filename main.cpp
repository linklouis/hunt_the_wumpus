#include <iostream>

#include "Map.h"
#include "Player.h"
#include "Wumpus.h"

using namespace std;

void runOneGameLoop(const Map& map, Player& player, Wumpus& wumpus);


[[noreturn]] int main() {
  auto map = Map();
  const auto playerPtr = new Player(&map, 3, 3);
  const auto wumpusPtr = new Wumpus(rand() % 6, rand() % 6);
  map.add(wumpusPtr);

  while (true) {
    runOneGameLoop(map, *playerPtr, *wumpusPtr);
  }
}

bool encounterEnemy(Player player) {

}


void printHelp() {
  cout << "Your goal is to find and hunt a creature known as the Wumpus. It is sneaky but large. Keep an ear out for strange noises."
          "\nYou are in a dangerous forest with several hazards. Watch out for Treents: carnivorous living trees who scoop up unsuspecting prey and pull them into their network of branches. If you manage to escape, pray that you were not swept too far away. The creaking of their branches is known as a heralder of death."
          "\nAlso be aware of nightmares. If you're close enough, you might hear their screams. Get any closer, and they'll go silent as they start their hunt. If that happens, pray you don't smell their repugnant scent, or it may be the last thing you ever smell. Nightmares won't leave their territory, but if you stay close too long, it will come find you."
          "\nYou're equipped with a rifle and a single shot. It can be used to defend yourself or to hunt your target. If you use it before you find your foe, search for what's left of those who came before you and pray that they have ammunition or a blade."
  << endl;
}

void takeInput(Player &player) {
  cout << endl << "Action: N)orth  S)outh  E)ast  W)est H)elp  Q)uit: ";
  char input;
  cin >> input;

  switch (input) {
    case 'N': case 'n': player.move(0, -1); break;
    case 'S': case 's': player.move(0, 1); break;
    case 'W': case 'w': player.move(-1, 0); break;
    case 'E': case 'e': player.move(1, 0); break;

    case 'H': case 'h': printHelp(); break;
    case 'Q': case 'q': exit(0);

    default:
      cout << "Command not recognized. Try again. ";
    // takeInput(player); // Recursive call
  }
}

void runOneGameLoop(const Map& map, Player& player, Wumpus& wumpus) {
  map.display();
  Room& room = player.getRoom();
  cout << room.getDescription();

  if (room.forEach([&player](const std::unique_ptr<Entity>& entity) {
    return entity->playerEnters(player);
  })) {
    return;
  }
  cout << wumpus.getHintMessage(player.getX(), player.getY());

  takeInput(player);
}
