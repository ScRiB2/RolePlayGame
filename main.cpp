#include <iostream>
#include "item/weapons/Weapon.h"
#include "item/weapons/pistols/Pistol.h"

using namespace std;

int main() {
    Pistol glock = Pistol("Glock", 100, 1000, 80);
    cout << glock.getCost();
    return 0;
}