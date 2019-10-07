//
// Created by asapronov on 30.09.2019.
//

#ifndef RPG_RIFLE_H
#define RPG_RIFLE_H

#include <utility>

#include "../Weapon.h"
#include "../WeaponTypes.h"

class Rifle : public Weapon {
public:
    Rifle(string name, int damage, int cost, int accuracy, int capacity) : Weapon(std::move(name), damage, cost, accuracy, capacity, WeaponTypes::RIFLE){

    }

    void setAim() override;
};


#endif //RPG_RIFLE_H
