#ifndef HERO_H_
#define HERO_H_

#include "Defines.h"
#include <stdbool.h>
#pragma pack(1)

#define MAX_SPELL_NAME_SIZE 20
#define MAX_HERO_NAME_SIZE 20
#define MAX_SPELLS 2

typedef struct {
  char name[MAX_SPELL_NAME_SIZE];
  int manaCost;
} Spell;

typedef struct {
  Spell spells[MAX_SPELLS];
  char name[MAX_HERO_NAME_SIZE];
  int maxMana;
  int currMana;
  int manaRegenRate;
} Hero;

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana,
                  int inputManaRegenRate);

void heroSpellsInit(Hero *hero, const char *basicSpellName,
                    int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost);

bool isSpellCastable(Hero* hero, Spell spell);
void takeMana(Hero* hero, Spell spell);
void baseRegenerate(Hero* hero);
void baseSpellAction(Hero* hero, Spell spell);

void printManaLack(Hero* hero, Spell spell);
void printSpellAction(Hero* hero, Spell spell);
void printBonusSpellAction(Hero* hero, Spell spell);

#endif /* HERO_H_ */
