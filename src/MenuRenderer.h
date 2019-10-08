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
    virtual void begin(LCD *lcd);
    void setRows(uint8_t rows);
    uint8_t getRows();
    void setColumns(uint8_t columns);
    uint8_t getColumns();
    size_t write(uint8_t value);
    void render(MenuItem * menuItem);
private:
    uint8_t _rows    = 0;
    uint8_t _columns = 0;
    LCD *_lcd = nullptr;
};


#endif //EASYLCDMENU_MENURENDERER_H
