
#include "Menu.hpp"
#include "TaskScheduler.h"


Menu::Menu(uint8_t rows, uint8_t columns) {
    _rows     = rows;
    _columns  = columns;
    newScreen = new uint8_t *[getColumns()];
    oldScreen = new uint8_t *[getColumns()];
    for (int i = 0; i < getRows(); i++) {
        newScreen[i] = new uint8_t[getColumns()];
        oldScreen[i] = new uint8_t[getColumns()];
    }
}

void Menu::setActiveMenuItem(MenuItem *menuItem) {
    this->activeMenuItem = menuItem;
}

void Menu::enter() {
    if (!this->rootMenuItem) return;
    active = true;
    this->rootMenuItem->enter(NONE);
}

void Menu::setRootMenuItem(MenuItem *menuItem) {
    this->rootMenuItem = menuItem;
    this->rootMenuItem->setMenu(this);
}

void Menu::navigate(EasyLCDMenuControl control) {
    if (this->activeMenuItem) {
        this->activeMenuItem->navigate(control);
    }
}

void Menu::next() {
    this->navigate(NEXT);
}

void Menu::previous() {
    this->navigate(PREVIOUS);
}

void Menu::go() {
    this->navigate(GO);
}

void Menu::back() {
    this->navigate(BACK);
}

void Menu::home() {
    this->activeMenuItem = nullptr;
    if (homeCallback) {
        homeCallback();
    }
    active = false;
    fill(oldScreen);
}

void Menu::onHome(EasyLCDMenuFunction cb) {
    homeCallback = cb;
}

void Menu::begin(LCD *lcd) {
    _lcd = lcd;
}

LCD *Menu::getLcd() {
    return _lcd;
}

uint8_t Menu::getRows() {
    return _rows;
}

uint8_t Menu::getColumns() {
    return _columns;
}

void Menu::setColumns(uint8_t columns) {
    _columns = columns;
}

void Menu::setRows(uint8_t rows) {
    _rows = rows;
}

bool Menu::isActive() const {
    return active;
}

void Menu::render(EasyLCDMenuTransition transition) {
    if (!isActive()) return;
    //Initialize screen matrix.
    this->fill(newScreen);
    //Get screen data from menuitem
    this->activeMenuItem->render(newScreen, getRows(), getColumns());
    if (transitionCallback && transition != NONE) {
        this->transitionCallback(oldScreen, newScreen,  _lcd, getRows(), getColumns(), transition) ;
    } else {
        this->print(newScreen);
    }
    this->copy(oldScreen, newScreen);
}

void Menu::fill(uint8_t **screen) {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            screen[i][j] = ' ';
        }
    }
}

void Menu::print(uint8_t **screen) {
    this->_lcd->clear();
    this->_lcd->home();
    for (int i = 0; i < getRows(); i++) {
        this->_lcd->setCursor(0, i);
        for (int j = 0; j < getColumns(); j++) {
            this->_lcd->print((char) screen[i][j]);
        }
    }
}

void Menu::setTransition(EasyLCDMenuTransitionFunction cb) {
    transitionCallback = cb;
}

void Menu::copy(uint8_t **oldScreen, uint8_t **newScreen) {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            oldScreen[i][j] = newScreen[i][j];
        }
    }
}


