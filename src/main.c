#include <stdio.h>
#include <stdlib.h>
#include"Archmage.h"
#include"DrawRanger.h"
#include"DeathKnight.h"

int main() {
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  int manaRegenModifier = 0;

  //read Archmage data
  scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
  Archmage archmage;
  initArchmage(&archmage, name, maxMana, baseManaRegenRate, manaRegenModifier);

  //read Death Knight data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DeathKnight deathKnight;
  initDeathKnight(&deathKnight, name, maxMana, baseManaRegenRate);

  //read Draw Ranger data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DrawRanger drawRanger;
  initDrawRanger(&drawRanger, name, maxMana, baseManaRegenRate);

  int commandsCount = 0;
  int currAction = 0;
  scanf("%d", &commandsCount);
 // for every command read, every Hero produce action according to the type of the command
  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
    archmageAction(&archmage, currAction);
    deathKnightAction(&deathKnight, currAction);
    drawRangerAction(&drawRanger, currAction);
  }
 

  return EXIT_SUCCESS;
}
