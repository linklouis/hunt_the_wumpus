//
// Created by linkl on 3/27/2025.
//

#include "Remains.h"

#include "Wumpus.h"

Remains::Remains(const Vector position, const Wumpus &wumpus, const int descriptionNum) :Entity(position, 'R') {
  const string direction = (wumpus.getPosition() - getPosition()).direction();
  if (descriptionNum == 1) {
    description = "A hollow-eyed skeleton, slumps against a gnarled tree, its gaze fixed forlornly to the " + direction + ".";
    lootDescription = "A worn knife with a chipped blade rests in its bony hand."
                      "\nTake it? y/n: ";
    afterCollectionText = "You pick up the knife!";
    loot = KNIFE;
  } else if (descriptionNum == 2) {
    description = "The grim tableau of a fallen hunter rests on the forest floor:"
                  " his skeletal remains clutch a rusted rifle, aimed with desperate resolve towards the " + direction + ".";
    lootDescription = "A single spent cartridge gleams in the dirt."
                      "\nSearch the body? y/n: ";
    afterCollectionText = "You search the body, eventually finding an unused round still in the chamber of the rifle.";
    loot = BULLET;
  } else {
    description = "A strangely contorted form, half-buried in the earth, points a gnarled finger towards the " + direction + "."
                                                                                                                             "\nAn unnatural chill emanates from it.";
    lootDescription = "Search it? y/n: ";
    afterCollectionText = "You find nothing, not even clothes. The more you look at it, the less sure you are that whatever is laid to rest here was human."
                          "\nA chill runs down your spine.";
    loot = NOTHING;
  }

}

void Remains::getInput(Player &player) {
  char input;
  cin >> input;
  switch (input) {
    case 'Y': case 'y': cout << endl << afterCollectionText << endl;
    cout << (
      loot == BULLET
      ? player.getBullet()
      : loot == KNIFE
      ? player.getKnife()
      : ""
      );
    hasLoot = false;
    return;

    case 'N': case 'n': cout << "You turn away and try to rid your mind of the morbid scene." << endl;
    return;

    default: cout << "Command not recognized. Please try again." << endl;
    getInput(player);
  }
}

bool Remains::playerEnters(Player &player) {
  cout << description << endl;
  if (hasLoot) {
    cout << lootDescription << endl;
    getInput(player);
  }
  return false;
}