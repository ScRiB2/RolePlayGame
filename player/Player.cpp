//
// Created by asapronov on 30.09.2019.
//

#include "Player.h"

const string &Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

void Player::setHp(int hp) {
    Player::hp = hp;
}

int Player::getKilled() const {
    return killed;
}

void Player::setKilled(int killed) {
    Player::killed = killed;
}

int Player::getDamage() const {
    return damage;
}

void Player::setDamage(int damage) {
    Player::damage = damage;
}

bool Player::isArmor() const {
    return armor;
}

void Player::setArmor(bool armor) {
    Player::armor = armor;
}

const Weapon &Player::getWeapon() const {
    return weapon;
}

void Player::setWeapon(const Weapon &weapon) {
    Player::weapon = weapon;
}
