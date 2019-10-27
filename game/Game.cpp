//
// Created by asapronov on 05.10.2019.
//

#include "Game.h"
void Game::start(const string& firstPlayerName, const string& secondPlayerName,bool withBot){
    Player player = Player(firstPlayerName, false);
    Player bot = Player(secondPlayerName, withBot);

    Rifle AK = Rifle("AK-47", 36, 2700, 30, 40); //2700
    Shotgun SWAG = Shotgun("SWAG-7", 50, 1800, 10, 30);  //1800

    weapons.push_back(AK);
    weapons.push_back(SWAG);

    for (int i = 0; i < 5; i++) {
        while (!player.isDie() && !bot.isDie()) {
            player.action(&bot,this->getWeapons());
            bot.action(&player,this->getWeapons());
        }
        if (bot.isDie()) {
            bot.respawn();
        } else {
            player.respawn();
        }
    }

    cout << player.getName() + ": " << player.getKilled() << std::endl;
    cout << bot.getName() + ": " << bot.getKilled();
}