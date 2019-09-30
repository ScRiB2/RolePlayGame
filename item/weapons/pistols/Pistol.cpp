//
// Created by asapronov on 23.09.2019.
//

#include "Pistol.h"

void Pistol::setAim() {
    setAccuracy(getAccuracy() + (int) (0.1 * getAccuracy()));
}
