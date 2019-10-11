//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMON_HPP
#define EASYLCDMENU_COMMON_HPP

#include "Arduino.h"

#define EASYLCDMENU_DEFAULT_ANIM_INTERVAL 100

const char *const EasyLCDMenuTrue  = "On";
const char *const EasyLCDMenuFalse = "Off";
const char EasyLCDMenuRight = B01111110;
const char EasyLCDMenuLeft  = B01111111;

typedef void (*EasyLCDMenuFunction)();

typedef enum {
    NEXT,
    PREVIOUS,
    GO,
    BACK,
}            EasyLCDMenuControl;

class Menu;

class MenuItem {
public:
    virtual void render(uint8_t **display, uint8_t rows, uint8_t columns) = 0;
    virtual void enter() = 0;
    virtual void setMenu(Menu *menu) = 0;
    virtual void navigate(EasyLCDMenuControl control) = 0;
    virtual const char *getLabel() = 0;
    virtual void setParent(MenuItem *menuItem) = 0;
};

#endif //EASYLCDMENU_COMMON_HPP
