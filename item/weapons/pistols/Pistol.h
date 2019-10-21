//
// Created by asapronov on 05.10.2019.
//

#ifndef RPG_PISTOL_H
#define RPG_PISTOL_H


#include "../Weapon.h"

class Pistol: public Weapon {
public:
        Pistol(string name, int damage, int cost, int accuracy, int capacity) : Weapon(std::move(name), damage, cost,
                                                                                       accuracy, capacity,
                                                                                       WeaponTypes::Pistol) {

        }

        Pistol() : Weapon("Glock", 20, 1000, 40, 20, WeaponTypes::Pistol) {}

        void setAim() override;
};


#endif //RPG_PISTOL_H
