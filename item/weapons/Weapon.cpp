//
// Created by asapronov on 16.09.2019.
//

#include "Weapon.h"

Weapon::Weapon(string name, int damage, int cost, int accuracy, int capacity, WeaponTypes type) : Item(std::move(name), cost) {
    this->damage = damage;
    this->accuracy = accuracy;
    this->type = type;
    this->amount = this->capacity = capacity;

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

void Weapon::setAim() {

}

WeaponTypes Weapon::getType() {
    return type;
}

int Weapon::getCapacity() {
    return capacity;
}

void Weapon::setCapacity(int capacity) {
    Weapon::capacity = capacity;
}

int Weapon::getAmount() {
    return amount;
}

void Weapon::setAmount(int amount) {
    Weapon::amount = amount;
}
