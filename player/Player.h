//
// Created by asapronov on 30.09.2019.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <string>
#include <utility>
#include "../item/weapons/Weapon.h"

using namespace std;


class Player {
private:
    const string name;
    int hp;
    int killed = 0;
    int damage;
    bool armor = false;
    Weapon weapon;

public:
    const string &getName() const;

    int getHp() const;

    void setHp(int hp);

    int getKilled() const;

    void setKilled(int killed);

    int getDamage() const;

    void setDamage(int damage);

    bool isArmor() const;

    void setArmor(bool armor);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);
};


#endif //RPG_PLAYER_H
