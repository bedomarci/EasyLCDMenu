//
// Created by m4800 on 10/5/2019.
//

#ifndef EASYLCDMENU_MENU_HPP
#define EASYLCDMENU_MENU_HPP

#include "common.hpp"
//#include "MenuRenderer.h"
#include "etl/function.h"
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
    LCD* getLcd();
    void render();
    void setRows(uint8_t rows);
    uint8_t getRows();
    void setColumns(uint8_t _columns);
    uint8_t getColumns();

//    MenuRenderer* getRenderer();
protected:
    LCD* _lcd;
    Task *tTransition;
//    MenuRenderer        *_renderer;
    EasyLCDMenuFunction homeCallback = nullptr;
    MenuItem            *rootMenuItem   = nullptr;
    MenuItem            *activeMenuItem = nullptr;
    uint8_t             _rows, _columns;
    uint8_t **newDisplay;
    uint8_t **currentDisplay;
    bool active = false;
//    void render(MenuItem * menuItem);
    void makeStep();
    void makeTransition (uint8_t **from, uint8_t **to);
    void fill(uint8_t ** display);
    void print(uint8_t ** display);
public:
    bool isActive() const;
};


#endif //EASYLCDMENU_MENU_HPP
