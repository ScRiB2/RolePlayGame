//
// Created by asapronov on 16.09.2019.
//

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H


#include "WeaponTypes.h"
#include "../Item.h"

class Weapon : public Item {
    WeaponTypes type;
    int damage;
    int accuracy;

protected:
    Weapon(string name, int damage, int cost, int accuracy, WeaponTypes type) : Item(name, cost) {
        this->damage = damage;
        this->type = type;
    }

public:
    void setDamage(int damage) {
        this->damage = damage;
    }

    int getDamage() {
        return damage;
    }

    WeaponTypes getType() {
        return type;
    }
};


#endif //RPG_WEAPON_H
