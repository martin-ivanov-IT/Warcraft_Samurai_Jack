#include"DrawRanger.h"

void initDrawRanger(DrawRanger* drawRanger, char* name, int maxMana, int baseManaRegenRate){
    heroBaseInit(&drawRanger->base, name, maxMana, baseManaRegenRate);
}

static void basicSpell(DrawRanger* drawRanger){
    
}

static void ultimateSpell(DrawRanger* drawRanger){
    
}

static void regenerate(DrawRanger* drawRanger){
    
}

void archmageAction(DrawRanger* drawRanger, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        basicSpell(drawRanger);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(drawRanger);
    }

    else if(actionType == REGENERATE_MANA){
        regenerate(drawRanger);
    }

}