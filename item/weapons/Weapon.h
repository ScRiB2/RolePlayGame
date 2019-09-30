//
// Created by asapronov on 16.09.2019.
//

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H


#include <utility>

#include "WeaponTypes.h"
#include "../Item.h"
#include "../upgrades/IAim.h"

class Weapon : public Item, public IAim {
    WeaponTypes type;
    int damage;
    int accuracy;

protected:
    Weapon(string name, int damage, int cost, int accuracy, WeaponTypes type) : Item(std::move(name), cost) {
        this->damage = damage;
        this->accuracy = accuracy;
        this->type = type;
    }

public:
    void setDamage(int newDamage) {
        this->damage = newDamage;
    }

    int getDamage() {
        return damage;
    }

    void setAccuracy(int newAccuracy) {
        this->accuracy = newAccuracy;
    }

    int getAccuracy() {
        return accuracy;
    }

    WeaponTypes getType() {
        return type;
    }
};


#endif //RPG_WEAPON_H
