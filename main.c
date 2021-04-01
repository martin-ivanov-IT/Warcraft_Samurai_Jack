#include <stdio.h>
#include <stdlib.h>
#include"Hero.h"
#include"Archmage.h"
#include"DrawRanger.h"
#include"DeathKnight.h"

void printArch(Archmage* archmage){
 printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\nmanaRegenModifier: %d\n"
        ,archmage->base.name, archmage->base.maxMana,archmage->base.manaRegenRate,archmage->manaRegenModifier);
}
void printDeathKnight(DeathKnight* deathKnight){
  printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\n"
        ,deathKnight->base.name, deathKnight->base.maxMana,deathKnight->base.manaRegenRate);
}
void printDrawRanger(DrawRanger* drawRanger){
  printf("name: %s\nmaxMana: %d\nbaseManaRegen: %d\n"
        ,drawRanger->base.name, drawRanger->base.maxMana,drawRanger->base.manaRegenRate);
}

int main() {
  char name[MAX_HERO_NAME_SIZE + 1];
  int maxMana = 0;
  int baseManaRegenRate = 0;
  int manaRegenModifier = 0;

  //read Archmage data
  printf("ARCH:\n");
  scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
  Archmage* archmage = malloc(sizeof(Archmage));
  initArchmage(archmage, name, maxMana, baseManaRegenRate, manaRegenModifier);
  archmageAction(archmage,0);
  printArch(archmage);

  //read Death Knight data
  printf("DN:\n");
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DeathKnight* deathKnight = malloc(sizeof(DeathKnight));
  initDeathKnight(deathKnight, name, maxMana, baseManaRegenRate);
  printDeathKnight(deathKnight);

  //read Draw Ranger data
  printf("Ranger\n");
  scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
  DrawRanger* drawRanger = malloc(sizeof(DrawRanger));
  initDrawRanger(drawRanger, name, maxMana, baseManaRegenRate);
  printDrawRanger(drawRanger);

  int commandsCount = 0;
  int currAction = 0;
  scanf("%d", &commandsCount);

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
    archmageAction(archmage, currAction);
    deathKnightAction(deathKnight, currAction);
    drawRangerAction(drawRanger, currAction);
  }

  return EXIT_SUCCESS;
}
