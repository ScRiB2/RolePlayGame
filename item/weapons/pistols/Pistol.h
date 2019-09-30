//
// Created by asapronov on 23.09.2019.
//

#ifndef RPG_PISTOL_H
#define RPG_PISTOL_H


#include <utility>

#include "../Weapon.h"
#include "../WeaponTypes.h"

class Pistol : public Weapon {
public:
    Pistol(string name, int damage, int cost, int accuracy, int capacity) : Weapon(std::move(name), damage, cost, accuracy, capacity, PISTOL) {

    }

    void setAim() override;
};


#endif //RPG_PISTOL_H
