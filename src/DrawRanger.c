#include"DrawRanger.h"
static void basicSpell(DrawRanger* drawRanger, Spell spell);
static void drawRangerAction(DrawRanger* drawRanger, enum ActionType actionType);

// assign values to the DrawRanger struct elements (Hero struct)
void initDrawRanger(DrawRanger* drawRanger, char* name, int maxMana, int baseManaRegenRate){
    // assign values to the Hero struct elements  which are read from the standard input
    heroBaseInit(drawRanger, name, maxMana, baseManaRegenRate);
    // assign values to the Hero struct element sells which are defines
    heroSpellsInit(drawRanger, DRAW_RANGER_BASIC_SPELL_NAME,DRAW_RANGER_BASIC_SPELL_MANA_COST,
                DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
    drawRanger->action = &drawRangerAction;
}
// if basic spell is casted (true is returned by function baseSpellAction), bonus basic spell is casted for free
static void basicSpell(DrawRanger* drawRanger, Spell spell){
    if(baseSpellAction(drawRanger,spell)){
       printBonusSpellAction(drawRanger, spell);
    }   
}
// take action, according to read action type
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