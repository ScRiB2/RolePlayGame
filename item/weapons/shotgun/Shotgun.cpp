//
// Created by asapronov on 30.09.2019.
//

#include "Shotgun.h"

Shotgun::Shotgun(string name, int damage, int cost, int accuracy, int capacity) : Weapon(std::move(name), damage, cost,
                                                                                         accuracy, capacity,
                                                                                         WeaponTypes::SHOTGUN) {
}

void Shotgun::setAim() {
    setAccuracy(getAccuracy() + (int) (0.05 * getAccuracy()));
}