//
// Created by asapronov on 16.09.2019.
//

#ifndef RPG_WEAPONTYPES_H
#define RPG_WEAPONTYPES_H

#include <string>

using namespace std;
namespace WeaponTypes {

    enum WeaponTypes {
        Pistol, Rifle, Shotgun
    };

    const WeaponTypes PISTOL = Pistol;
    const WeaponTypes RIFLE = Rifle;
    const WeaponTypes SHOTGUN = Shotgun;
}

#endif //RPG_WEAPONTYPES_H
