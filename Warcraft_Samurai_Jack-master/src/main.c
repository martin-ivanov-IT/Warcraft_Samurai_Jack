#include <stdio.h>
#include <stdlib.h>
#include"Archmage.h"
#include"DrawRanger.h"
#include"DeathKnight.h"

void printArch(Archmage* archmage){
 printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\nmanaRegenModifier: %d\n"
        ,archmage->base.name,
         archmage->base.maxMana,
         archmage->base.manaRegenRate,
         archmage->manaRegenModifier);
}
void printDeathKnight(DeathKnight* deathKnight){
  printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\n"
        ,deathKnight->name, deathKnight->maxMana,deathKnight->manaRegenRate);
}
void printDrawRanger(DrawRanger* drawRanger){
  printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\n"
        ,drawRanger->name, drawRanger->maxMana,drawRanger->manaRegenRate);
}

int main() {
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  int manaRegenModifier = 0;

  //read Archmage data
  scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
  Archmage* archmage = malloc(sizeof(Archmage));
  initArchmage(archmage, name, maxMana, baseManaRegenRate, manaRegenModifier);

  //read Death Knight data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DeathKnight* deathKnight = malloc(sizeof(DeathKnight));
  initDeathKnight(deathKnight, name, maxMana, baseManaRegenRate);

  //read Draw Ranger data
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DrawRanger* drawRanger = malloc(sizeof(DrawRanger));
  initDrawRanger(drawRanger, name, maxMana, baseManaRegenRate);

  int commandsCount = 0;
  int currAction = 0;
  scanf("%d", &commandsCount);

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
    archmageAction(archmage, currAction);
    deathKnightAction(deathKnight, currAction);
    drawRangerAction( drawRanger, currAction);
  }
 // free allocated memory 
  free(archmage);
  free(drawRanger);
  free(deathKnight);

  return EXIT_SUCCESS;
}
