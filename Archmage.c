#include"Archmage.h"
#include "Defines.h"

void initArchmage(Archmage* archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier){
    heroBaseInit(&archmage->base, name, maxMana, baseManaRegenRate);
    archmage->manaRegenModifier = manaRegenModifier;
}

static void basicSpell(Archmage* archmage){
    
}

static void ultimateSpell(Archmage* archmage){
    
}

static void regenerate(Archmage* archmage){
    
}

void archmageAction(Archmage* archmage, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        basicSpell(archmage);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(archmage);
    }

    else if(actionType == REGENERATE_MANA){
        regenerate(archmage);
    }

}
