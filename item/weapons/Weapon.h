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
    Weapon(string name, int damage, int cost, int accuracy, WeaponTypes type);

public:
    void setDamage(int newDamage);

    int getDamage();

    void setAccuracy(int newAccuracy);

    int getAccuracy();

    WeaponTypes getType();
};


#endif //RPG_WEAPON_H
