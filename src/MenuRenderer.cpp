//
// Created by m4800 on 10/8/2019.
//

#include "MenuRenderer.h"

MenuRenderer::MenuRenderer(uint8_t rows, uint8_t columns) {
    _rows = rows;
    _columns = columns;
}

uint8_t MenuRenderer::getRows() {
    return _rows;
}

uint8_t MenuRenderer::getColumns() {
    return _columns;
}

size_t MenuRenderer::write(uint8_t value) {
    return _lcd->write(value);
}

void MenuRenderer::begin(LCD *lcd) {
    Serial.println("RENDERER BEGIN");
    _lcd = lcd;
}

void MenuRenderer::render(MenuItem *menuItem) {
    //Initialize screen matrix.
    uint8_t **newDisplay;
    Serial.print('.');
    newDisplay = new uint8_t *[getColumns()];
    for (int i = 0; i < getRows(); i++) {
        newDisplay[i] = new uint8_t[getColumns()];
        for (int j = 0; j < getColumns(); j++) newDisplay[i][j] = ' ';
    }
    //Get screen data from menuitem
    Serial.print(',');
    menuItem->render(newDisplay, getRows(), getColumns());
    Serial.print(':');

    //Print it out
    this->_lcd->clear();
    this->_lcd->home();
    for (int i = 0; i < getRows(); i++) {
        this->_lcd->setCursor(0, i);
//        Serial.println();
        for (int j = 0; j < getColumns(); j++) {
            this->_lcd->print((char)newDisplay[i][j]);
//            Serial.print((char)newDisplay[i][j]);
        }
        delete(newDisplay[i]);
    }
    delete(newDisplay);
    Serial.println('!');
//    Serial.println();
}

