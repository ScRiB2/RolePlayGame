//
// Created by asapronov on 30.09.2019.
//

#include "Player.h"

#include <utility>
#include "../item/weapons/pistols/Pistol.h"
#include "../item/weapons/rifle/Rifle.h"

string Player::getName() const {
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

Player::Player(const string &name) {
    this->name = name;
    respawn();
}

Weapon *Player::getWeapon() const {
    return weapon;
}

void Player::setWeapon(Weapon *weapon) {
    Player::weapon = weapon;
}

bool Player::isDie() {
    return (hp <= 0);
}

void Player::respawn() {
    hp = 100;
    weapon = new Rifle("AK-47", 36, 2700, 30, 40); //2700;
    damage = weapon->getDamage();
    money = 1000;
    std::cout << this->getName() << " возродился " << std::endl;
}

void Player::attack(Player *other) {
    // проверка есть ли патроны в магазине
    if (weapon->isEmpty()) {
        std::cout << this->getName() + " закончились патроны" << endl;
        return;
    }

    //проверка попал в противника или нет
    bool hit = false;
    // попадание с вероятностью = точность оружия
    std::random_device rd;
    std::uniform_int_distribution<int> uid(0, 100);
    if (uid(rd) < weapon->getAccuracy())
        hit = true;
    if (hit) {
        int resist = other->isArmor() ? 1 : 0;
        int lost = this->getDamage() - resist * ((int) (0.3 * this->getDamage()));
        //Чтобы не было урона больше, чем хп у противника
        if (lost > other->getHp())
            lost = other->getHp();
        other->setHp(other->getHp() - lost);
        std::cout << this->getName() + " наносит " + other->getName() + " " << lost << " урона"
                  << " c помощью " + weapon->getName() << endl;
        if (other->isDie()) {
            std::cout << this->getName() + " убивает " + other->getName() << endl;
            setKilled(getKilled() + 1);
            this->money += 500;
        }
        // -1 патрон после выстрела
        weapon->setAmount(weapon->getAmount() - 1);
    } else
        std::cout << this->getName() + " не попал" << endl;
}

void Player::action(Player *other)  {
    if (other->isDie() || this->isDie())
        return;
    int actionIndex = 0;
    std::cout << "Выберите действие: " << endl;
    std::cout << "1. Атаковать противника" << endl;
    std::cout << "2. Купить новое оружие" << endl;
    std::cout << "3. Атаковать противника" << endl;
    std::cin >> actionIndex;


    switch (actionIndex){

    }

    this->attack(other);
    // с вероятностью 30% противник контратакует
    std::random_device rd;
    std::uniform_int_distribution<int> uid(0, 100);
    if (uid(rd) > 70 && !other->isDie()) {
        std::cout << other->getName() + " контратакует" << std::endl;
        other->attack(this);
    }
}

Player Player::buyWeapon(Weapon weapon) {
    int cost = weapon.getCost();
    if(cost > money) {
        std::cout << "Не достаточно средств для покупки" << std::endl;
        return *this;
    }
    money -= cost;
    this->weapon = &weapon;
    setDamage(weapon.getDamage());
    std::cout << this->getName() << " купил " << weapon.getName() << std::endl;
    return *this;
}

void Player::upgradeWeapon(Upgrades upgrade) {
    switch (upgrade) {
        case Aim:
            if (money >= 200) {
                weapon->setAim();
                money -= 200;
                std::cout << this->getName() << " купил прицел на " << weapon->getName() << std::endl;
            }
            break;
    }
}

void Player::buyArmor()  {
    if(weapon->getCost() > money) {
        std::cout << "Не достаточно средств для покупки" << std::endl;
        return;
    }
    money -= 400;
    setArmor(true);
    std::cout << this->getName() + " купил броню" << std::endl;
}
