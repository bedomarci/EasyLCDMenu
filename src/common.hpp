//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMON_HPP
#define EASYLCDMENU_COMMON_HPP

#include "Arduino.h"
#include <LCD.h>


const char *const EasyLCDMenuTrue = "On";
const char *const EasyLCDMenuFalse = "Off";
const char EasyLCDMenuRight = B01111110;
const char EasyLCDMenuLeft = B01111111;
typedef enum {
    NEXT,
    PREVIOUS,
    GO,
    BACK,
} EasyLCDMenuControl;

typedef enum {
    NONE,
    LEFT,
    RIGHT,
} EasyLCDMenuTransition;

typedef void (*EasyLCDMenuFunction)();

typedef void (*EasyLCDMenuTransitionFunction)(uint8_t **oldScreen, uint8_t **newScreen, LCD *lcd, uint8_t rows, uint8_t columns,
                                      EasyLCDMenuTransition transition);


class Menu;

class MenuItem {
public:
    virtual void render(uint8_t **display, uint8_t rows, uint8_t columns) = 0;

    virtual void enter(EasyLCDMenuTransition transition = NONE) = 0;

    virtual void setMenu(Menu *menu) = 0;

    virtual void navigate(EasyLCDMenuControl control) = 0;

    virtual const char *getLabel() = 0;

    virtual void setParent(MenuItem *menuItem) = 0;
};

#endif //EASYLCDMENU_COMMON_HPP
