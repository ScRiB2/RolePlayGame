//
// Created by asapronov on 30.09.2019.
//

#include "Player.h"

#include "../item/weapons/pistols/Pistol.h"
#include <random>
#include <ctime>
#include <list>

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

Player::Player(const string &name, bool isBot) {
    this->name = name;
    this->isBot = isBot;
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
    weapon = new Pistol();
    damage = weapon->getDamage();
    money = 1000;
    std::cout << this->getName() << " заспавнился" << std::endl;
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
    int t = weapon->getAccuracy();
    srand(time(nullptr));
    int random = rand() % 100;
    if (random < weapon->getAccuracy())
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
        this->money += 500;
        if (other->isDie()) {
            std::cout << this->getName() + " убивает " + other->getName() << endl;
            setKilled(getKilled() + 1);
            this->money += 2000;
        }
        // -1 патрон после выстрела
        weapon->setAmount(weapon->getAmount() - 1);
    } else
        std::cout << this->getName() + " не попал" << endl;
}

void Player::action(Player *other, vector<Weapon> weapons) {
    srand(time(nullptr));
    if (other->isDie() || this->isDie())
        return;
    cout << "\nХодит " << this->getName() << endl;
    int actionId = -1;
    if (!this->isBot) {
        cout << endl;
        cout << "Ваш баланс: " << this->getMoney() << " руб." << endl;
        cout << endl;
        cout << "Выберите действие:" << endl;
        cout << "1. Атаковать противника" << endl;
        cout << "2. Купить оружие" << endl;
        cout << "3. Установить прицел" << endl;
        cout << "4. Купить броню (400 руб.)" << endl;
        cin >> actionId;
        cout << endl;
    } else {
        actionId = rand() % 4 + 1;
    }

    if (actionId == 1) {
        this->attack(other);
        // с вероятностью 30% противник контратакует
        srand(time(nullptr));
        int random = rand() % 100;
        if (random > 70 && !other->isDie()) {
            std::cout << other->getName() + " контратакует" << std::endl;
            other->attack(this);
        }
    } else if (actionId == 2) {
        int weaponId = 0;


        if (!this->isBot) {
            cout << "Ваш баланс: " << this->getMoney() << " руб." << endl;
            cout << "Выберите оружие:" << endl;
            int i = 0;
            for (Weapon someWeapon: weapons) {
                cout << ++i << ". " << someWeapon.getName() << " - "
                     << "урон: " << someWeapon.getDamage()
                     << ", точность: " << someWeapon.getAccuracy()
                     << ", стоимость: " << someWeapon.getCost() << " руб." << endl;
            }
            cin >> weaponId;
        } else
            weaponId = rand() % weapons.size() + 1;
        this->buyWeapon(&weapons[weaponId - 1]);
    } else if (actionId == 3) {
        this->getWeapon()->setAim();
    } else
        this->buyArmor();
}

Player Player::buyWeapon(Weapon *weapon) {
    int cost = weapon->getCost();
    if (cost > money) {
        std::cout << "Не достаточно средств для покупки" << std::endl;
        return *this;
    }
    money -= cost;
    this->weapon = weapon;
    setDamage(weapon->getDamage());
    std::cout << this->getName() << " купил " << weapon->getName() << std::endl;
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

void Player::buyArmor() {
    if (weapon->getCost() > money) {
        std::cout << "Не достаточно средств для покупки" << std::endl;
        return;
    }
    if (this->isArmor()) {
        std::cout << "Броня уже есть" << std::endl;
        return;
    }
    money -= 400;
    setArmor(true);
    std::cout << this->getName() + " купил броню" << std::endl;
}

int Player::getMoney() const {
    return money;
}
