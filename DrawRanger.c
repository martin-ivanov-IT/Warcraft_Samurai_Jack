#include"DrawRanger.h"
#include"Defines.h"

void initDrawRanger(DrawRanger* drawRanger, char* name, int maxMana, int baseManaRegenRate){
    heroBaseInit(drawRanger, name, maxMana, baseManaRegenRate);
    heroSpellsInit(drawRanger, DRAW_RANGER_BASIC_SPELL_NAME,DRAW_RANGER_BASIC_SPELL_MANA_COST,
                DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);

}

static void basicSpell(DrawRanger* drawRanger, Spell spell){
    if(isSpellCastable(drawRanger, spell)){
        takeMana(drawRanger, spell);
        printSpellAction(drawRanger, spell);

        printBonusSpellAction(drawRanger, spell);
    }
    else{
        printManaLack(drawRanger, spell);
    }
}

void drawRangerAction(DrawRanger* drawRanger, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        basicSpell(drawRanger, drawRanger->spells[BASIC]);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        baseSpellAction(drawRanger, drawRanger->spells[ULTIMATE]);
    }

    else if(actionType == REGENERATE_MANA){
        baseRegenerate(drawRanger);
    }

}