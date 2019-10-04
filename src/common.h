//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMON_H
#define EASYLCDMENU_COMMON_H

#include "Arduino.h"

const char * EasyLCDMenuTrue    = "On";
const char * EasyLCDMenuFalse   = "Off";

typedef void (*EasyLCDMenuFunction)();

enum EasyLCDMenuControl {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SELECT,
};



#endif //EASYLCDMENU_COMMON_H
