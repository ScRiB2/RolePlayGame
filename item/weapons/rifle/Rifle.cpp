//
// Created by asapronov on 30.09.2019.
//

#include "Rifle.h"

void Rifle::setAim() {
    setAccuracy(getAccuracy() + (int) (0.2 * getAccuracy()));
}