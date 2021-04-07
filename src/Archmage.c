#include"Archmage.h"

// assign values to the Archmage struct elements (Hero struct and int manaRegenModifier)
void initArchmage(Archmage* archmage, char* name, int maxMana, int baseManaRegenRate, int manaRegenModifier){
    // assign values to the Hero struct elements  which are read from the standard input
    heroBaseInit(&archmage->base, name, maxMana, baseManaRegenRate);
    archmage->manaRegenModifier = manaRegenModifier;
    // assign values to the Hero struct element spells which are defines
    heroSpellsInit(&archmage->base, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST,
                ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
                
}
// multiply Mana regenerate rate, with modifier value, then increase current Mana with this rate, up to the initial Mana value(max mana)
static void regenerate(Archmage* archmage){
    int regenValue = archmage->base.manaRegenRate * archmage->manaRegenModifier;
    archmage->base.currMana += regenValue;
    if(archmage->base.currMana > archmage->base.maxMana){
        archmage->base.currMana = archmage->base.maxMana;
    }
}
// if ultimate spell is casted (true is returned by function baseSpellAction), regenerate Mana
static void ultimateSpell(Archmage* archmage, Spell spell){
    if(baseSpellAction(&archmage->base, spell)){
        regenerate(archmage);
    }
}
// take action, according to read action type
void archmageAction(Archmage* archmage, enum ActionType actionType){
    if(actionType == CAST_BASIC_SPELL){
        baseSpellAction(&archmage->base, archmage->base.spells[BASIC]);
    }
    else if(actionType == CAST_ULTIMATE_SPELL){
        ultimateSpell(archmage, archmage->base.spells[ULTIMATE]);
    }
    
    else if(actionType == REGENERATE_MANA){
        regenerate(archmage);
    }
}
