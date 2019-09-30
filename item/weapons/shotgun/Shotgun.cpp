//
// Created by asapronov on 30.09.2019.
//

#include "Shotgun.h"

void Shotgun::setAim() {
    setAccuracy(getAccuracy() + (int) (0.05 * getAccuracy()));
}