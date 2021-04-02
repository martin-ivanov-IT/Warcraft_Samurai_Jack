#include"Archmage.h"
#include "Defines.h"
#include"Hero.h"

void initArchmage(Archmage* archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier){
    heroBaseInit(&archmage->base, name, maxMana, baseManaRegenRate);
    archmage->manaRegenModifier = manaRegenModifier;
    heroSpellsInit(&archmage->base, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST,
                ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
                
}

static void regenerate(Archmage* archmage){
    int regenValue = archmage->base.manaRegenRate * archmage->manaRegenModifier;
    archmage->base.currMana += regenValue;
    if(archmage->base.currMana > archmage->base.maxMana){
        archmage->base.currMana = archmage->base.maxMana;
    }
}

static void ultimateSpell(Archmage* archmage, Spell spell){
    if(isSpellCastable((Hero*)archmage, spell)){
        baseSpellAction((Hero*)archmage, spell);
        regenerate(archmage);
    }
    else{
        printManaLack((Hero*)archmage, spell);
    }
    
}

void archmageAction(Archmage* archmage, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        baseSpellAction((Hero*)archmage, archmage->base.spells[BASIC]);
    }

    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(archmage, archmage->base.spells[ULTIMATE]);
    }

    else if(actionType == REGENERATE_MANA){
        regenerate(archmage);
    }

}
