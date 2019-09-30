//
// Created by asapronov on 16.09.2019.
//

#include "Weapon.h"

Weapon::Weapon(string name, int damage, int cost, int accuracy, WeaponTypes type) : Item(std::move(name), cost) {
    this->damage = damage;
    this->accuracy = accuracy;
    this->type = type;
}

void Weapon::setDamage(int newDamage) {
    this->damage = newDamage;
}

int Weapon::getDamage() {
    return damage;
}

void Weapon::setAccuracy(int newAccuracy) {
    this->accuracy = newAccuracy;
}

int Weapon::getAccuracy() {
    return accuracy;
}

WeaponTypes Weapon::getType() {
    return type;
}