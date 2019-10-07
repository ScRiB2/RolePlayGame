//
// Created by asapronov on 30.09.2019.
//

#ifndef RPG_SHOTGUN_H
#define RPG_SHOTGUN_H

#include <utility>
#include <iostream>

#include "../Weapon.h"
#include "../WeaponTypes.h"

class Shotgun : public Weapon {
public:

    Shotgun(string name, int damage, int cost, int accuracy, int capacity);

    void setAim() override;
};


#endif //RPG_SHOTGUN_H
