//
// Created by m4800 on 10/8/2019.
//

#ifndef EASYLCDMENU_MENURENDERER_H
#define EASYLCDMENU_MENURENDERER_H
#include "Arduino.h"
#include "common.hpp"
#include <LCD.h>

class MenuRenderer {
public:
    MenuRenderer(uint8_t rows, uint8_t columns);
    virtual void begin(LCD *lcd);
    uint8_t getRows();
    uint8_t getColumns();
    size_t write(uint8_t value);
    void render(MenuItem * menuItem);
private:
    uint8_t _rows    = 0;
    uint8_t _columns = 0;
    LCD *_lcd = nullptr;
//    Task tTransition();
//    void makeTransition (uint8_t **from, uint8_t **to);
};


#endif //EASYLCDMENU_MENURENDERER_H
