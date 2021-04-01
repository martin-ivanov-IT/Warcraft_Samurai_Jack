#include"DeathKnight.h"
void initDeathKnight(DeathKnight* deathKnight, char* name, int maxMana, int baseManaRegenRate){
    heroBaseInit(&deathKnight->base, name, maxMana, baseManaRegenRate);
}

static void basicSpell(DeathKnight* deathKnight){
    
}

static void ultimateSpell(DeathKnight* deathKnight){
    
}

static void regenerate(DeathKnight* deathKnight){
    
}

void archmageAction(DeathKnight* deathKnight, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        basicSpell(deathKnight);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(deathKnight);
    }

    else if(actionType == REGENERATE_MANA){
        regenerate(deathKnight);
    }

}