//
// Created by asapronov on 05.10.2019.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "../player/Player.h"
#include "../item/weapons/rifle/Rifle.h"
#include "../item/weapons/shotgun/Shotgun.h"

class Game {
private:
    vector<Weapon> weapons;

public:
    void start(const string& firstPlayerName, const string& secondPlayerName, bool withBot= true);

    vector<Weapon> getWeapons(){
        return weapons;
    }
};


#endif //RPG_GAME_H
