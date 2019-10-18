//
// Created by m4800 on 10/5/2019.
//

#ifndef EASYLCDMENU_MENU_HPP
#define EASYLCDMENU_MENU_HPP

#include "common.hpp"
#include "TaskSchedulerDeclarations.h"
#include <LCD.h>


class Menu {
public:
    Menu(uint8_t rows, uint8_t columns);

    void begin(LCD *lcd);

    void onHome(EasyLCDMenuFunction cb);

    void home();

    void enter();

    void setActiveMenuItem(MenuItem *menuItem);

    void setRootMenuItem(MenuItem *menuItem);

    void next();

    void previous();

    void go();

    void back();

    void navigate(EasyLCDMenuControl control);

    LCD *getLcd();

    void render(EasyLCDMenuTransition transition = NONE);

    void setRows(uint8_t rows);

    uint8_t getRows();

    void setColumns(uint8_t _columns);

    uint8_t getColumns();


    void setTransition(EasyLCDMenuTransitionFunction cb);

//    MenuRenderer* getRenderer();
protected:
    LCD *_lcd;
    EasyLCDMenuTransitionFunction transitionCallback = nullptr;
    EasyLCDMenuFunction homeCallback = nullptr;
    MenuItem *rootMenuItem = nullptr;
    MenuItem *activeMenuItem = nullptr;
    uint8_t _rows, _columns;
    uint8_t **newScreen;
    uint8_t **oldScreen;
    bool active = false;

    void fill(uint8_t **screen);

    void print(uint8_t **screen);

    void copy(uint8_t **oldScreen, uint8_t **newScreen);

public:
    bool isActive() const;
};


#endif //EASYLCDMENU_MENU_HPP
