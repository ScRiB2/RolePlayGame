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

    Game game;
    game.start("Петя", "Вася", false);
    game.start("Петя", "Бот", true);

    return 0;
}