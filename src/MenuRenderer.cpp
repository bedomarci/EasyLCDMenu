//
// Created by m4800 on 10/8/2019.
//

#include "MenuRenderer.h"

void MenuRenderer::setRows(uint8_t rows) {
    this->_rows = rows;
}

uint8_t MenuRenderer::getRows() {
    return _rows;
}

void MenuRenderer::setColumns(uint8_t columns) {
    this->_columns = columns;
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
    newDisplay = new uint8_t *[getColumns()];
    for (int i = 0; i < getRows(); i++) {
        newDisplay[i] = new uint8_t[getColumns()];
    }
    //Get screen data from menuitem
    menuItem->render(newDisplay, getRows(), getColumns());

    //Print it out
    this->_lcd->clear();
    this->_lcd->home();
    for (int i = 0; i < getRows(); i++) {
        this->_lcd->setCursor(0, i);
        for (int j = 0; j < getColumns(); j++) {
            this->_lcd->print(newDisplay[i][j]);
        }
    }
}
