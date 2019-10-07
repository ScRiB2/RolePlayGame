//
// Created by asapronov on 23.09.2019.
//

#ifndef RPG_PISTOL_H
#define RPG_PISTOL_H


#include <utility>

#include "../Weapon.h"
#include "../WeaponTypes.h"

//namespace Pistoln {


    class Pistol : public Weapon {
    public:


        void setAim() override;
    };
//    class Pistol : public Weapon {
//    public:
//        Pistol(string name, int damage, int cost, int accuracy, int capacity) : Weapon(std::move(name), damage, cost,
//                                                                                       accuracy, capacity,
//                                                                                       WeaponTypes::Pistol) {
//
//        }
//
//        Pistol() : Weapon("Glock", 100, 1000, 99, 20, WeaponTypes::Pistol) {}
//
//        void setAim() override;
//    };
//}

#endif //RPG_PISTOL_H
