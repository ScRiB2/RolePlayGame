//
// Created by asapronov on 05.10.2019.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "../player/Player.h"
#include "../item/weapons/rifle/Rifle.h"
#include "../item/weapons/shotgun/Shotgun.h"

class Game {
    vector<Weapon> weapons;

public:
    void start(){
        Player one = Player("Петя");
        Player two = Player("Вася");

        Rifle AK = Rifle("AK-47", 36, 2700, 30, 40); //2700
        Shotgun SWAG = Shotgun("SWAG-7", 50, 1800, 10, 30);  //1800

        weapons.push_back(AK);
        weapons.push_back(SWAG);

        one.buyWeapon(SWAG).upgradeWeapon(AIM);
        one.buyArmor();

        one.action(&two);

        for (int i = 0; i < 5; i++) {
            while (!two.isDie() && !one.isDie()) {
                one.action(&two);
                two.action(&one);
            }
            if (two.isDie()) {
                two.respawn();
                two.buyArmor();
            } else {
                one.respawn();
                one.buyArmor();
                one.buyWeapon(SWAG);
            }
        }

        cout << one.getName() + ": " << one.getKilled() << std::endl;
        cout << two.getName() + ": " << two.getKilled();

    }

    vector<Weapon> getWeapons(){
        return weapons;
    }
};


#endif //RPG_GAME_H
