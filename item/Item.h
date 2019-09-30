//
// Created by asapronov on 16.09.2019.
//

#ifndef RPG_ITEM_H
#define RPG_ITEM_H

#include <string>
#include <utility>

using namespace std;

#include "weapons/WeaponTypes.h"

class Item {
protected:
    string name;
    int cost;

    Item(string name, int cost) {
        this->name = std::move(name);
        this->cost = cost;
    }

    Item(){
        this->name = "";
        this->cost = 0;
    }

public:
    void setName(string newName) { this->name = std::move(newName); }

    string getName() { return name; }

    void setCost(int newCost) { cost = newCost; }

    int getCost() { return cost; }
};

#endif //RPG_ITEM_H
