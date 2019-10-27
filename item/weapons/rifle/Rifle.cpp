//
// Created by asapronov on 30.09.2019.
//

#include <iostream>
#include "Rifle.h"

void Rifle::setAim() {
    setAccuracy(getAccuracy() + (int) (0.2 * getAccuracy()));
    std::cout << "Прицел установлен" << endl;
}