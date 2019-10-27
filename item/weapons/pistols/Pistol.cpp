//
// Created by asapronov on 05.10.2019.
//

#include <iostream>
#include "Pistol.h"

void Pistol::setAim() {
    setAccuracy(100);
    std::cout << "Прицел установлен" << endl;
}
