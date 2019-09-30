//
// Created by asapronov on 30.09.2019.
//

#ifndef RPG_SHOTGUN_H
#define RPG_SHOTGUN_H

#include <utility>

#include "../Weapon.h"
#include "../WeaponTypes.h"

class Shotgun : public Weapon {
public:

    Shotgun(string name, int damage, int cost, int accuracy) : Weapon(std::move(name), damage, cost, accuracy,
                                                                      SHOTGUN) {

    }

    void setAim() override {
        setAccuracy(getAccuracy() + (int) (0.05 * getAccuracy()));
    }
};


#endif //RPG_SHOTGUN_H
