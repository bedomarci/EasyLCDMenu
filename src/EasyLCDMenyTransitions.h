#ifndef EASYLCDMENU_EASYLCDMENYTRANSITIONS_H
#define EASYLCDMENU_EASYLCDMENYTRANSITIONS_H

#include "common.hpp"

inline void
EasyLCDMenuPushTransition(uint8_t **oldScreen, uint8_t **newScreen, LCD *lcd, uint8_t rows, uint8_t columns,
                          EasyLCDMenuTransition transition) {
    const uint8_t divider = 2;
    columns /= divider;
    uint8_t **_oldScreen = (transition == RIGHT) ? oldScreen : newScreen;
    uint8_t **_newScreen = (transition == RIGHT) ? newScreen : oldScreen;

    for (int step = 0; step < columns + 1; step++) {
        uint8_t oStep = step; // oriented step;
        if (transition == LEFT) oStep = columns - oStep; //reverse steps if
        for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
            lcd->setCursor(0, rowIndex);
            for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
                uint8_t scIndex;
                if (columnIndex <= (columns - oStep - 1)) {
                    scIndex = (columnIndex + oStep) * divider;
                    for (int chunk = 0; chunk < divider; chunk++)
                        lcd->print((char) _oldScreen[rowIndex][scIndex + chunk]);
                } else {
                    scIndex = (columns - columnIndex - oStep) * -1 * divider;
                    for (int chunk = 0; chunk < divider; chunk++)
                        lcd->print((char) _newScreen[rowIndex][scIndex + chunk]);
                };
            }
        }
        delay(100);
    }
}

#endif //EASYLCDMENU_EASYLCDMENYTRANSITIONS_H
