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
    int capacity;   // ёмкость магазина
    int accuracy;   // точность
    int amount;     // текущее количество патронов в магазине

protected:
    Weapon(string name, int damage, int cost, int accuracy,int capacity, WeaponTypes type);

    Weapon() {}

public:
    void setDamage(int newDamage);

    int getDamage();

    void setAccuracy(int newAccuracy);

    int getAccuracy();

    void setAim() override;

    WeaponTypes getType();

    int getCapacity();

    void setCapacity(int capacity);

    int getAmount();

    void setAmount(int amount);


};


#endif //RPG_WEAPON_H
