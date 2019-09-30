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
    Rifle(string name, int damage, int cost, int accuracy) : Weapon(std::move(name), damage, cost, accuracy, RIFLE) {

    }

    void setAim() override {
        setAccuracy(getAccuracy() + (int) (0.2 * getAccuracy()));
    }
};


#endif //RPG_RIFLE_H
