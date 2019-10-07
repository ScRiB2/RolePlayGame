//
// Created by asapronov on 30.09.2019.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <string>
#include <iostream>
#include <random>
#include <utility>
#include "../item/weapons/Weapon.h"
#include "../item/weapons/pistols/Pistol.h"
#include "../item/upgrades/Upgrades.h"

using namespace std;


class Player {
private:
    string name;
    int hp = 100;
    int killed = 0;
    int damage = 0;
    bool armor = false;
    Weapon *weapon;
    int money = 1000;

public:
    Player(const string& name);

    [[nodiscard]] string getName() const;

    [[nodiscard]] int getHp() const;

    void setHp(int hp);

    [[nodiscard]] int getKilled() const;

    void setKilled(int killed);

    [[nodiscard]] int getDamage() const;

    void setDamage(int damage);

    [[nodiscard]] bool isArmor() const;

    void setArmor(bool armor);

    [[nodiscard]] Weapon *getWeapon() const;

    void setWeapon(Weapon *weapon);

    bool isDie();

    void respawn();

    void attack(Player* other);

    void action(Player* other);

    Player buyWeapon(Weapon weapon);

    void upgradeWeapon(Upgrades upgrade);

    void buyArmor();
};


#endif //RPG_PLAYER_H
