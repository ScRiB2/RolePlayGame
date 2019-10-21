#include <iostream>
#include <list>
#include "item/weapons/Weapon.h"
//#include "item/weapons/pistols/Pistol.h"
#include "item/weapons/shotgun/Shotgun.h"
#include "player/Player.h"
#include "item/weapons/rifle/Rifle.h"
#include "game/Game.h"

using namespace std;

int main() {
    system("chcp 65001");

    Player one = Player("Петя");
    Player two = Player("Вася");

    Rifle AK = Rifle("AK-47", 36, 2700, 30, 40); //2700
    Shotgun SWAG = Shotgun("SWAG-7", 50, 1800, 10, 30);  //1800

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
//    Game game;
//    game.start();

    return 0;
}