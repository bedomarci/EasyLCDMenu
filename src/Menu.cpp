
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
    this->rootMenuItem->enter();
    render();
}

void Menu::setRootMenuItem(MenuItem *menuItem) {
    this->rootMenuItem = menuItem;
    this->rootMenuItem->setMenu(this);
}

void Menu::navigate(EasyLCDMenuControl control) {
    if (this->activeMenuItem) {
        this->activeMenuItem->navigate(control);
        render();
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
    Serial.println("HOME");
}

void Menu::onHome(EasyLCDMenuFunction cb) {
    homeCallback = cb;
}

void Menu::begin(LCD *lcd) {
    _lcd = lcd;
//    this->_renderer->begin(lcd);
}

LCD *Menu::getLcd() {
    return _lcd;
}

//MenuRenderer *Menu::getRenderer() {
//    return _renderer;
//}

//void Menu::render() {
//    if (isActive()) {
////        this->_renderer->render(this->activeMenuItem);
//    }
//}

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

void Menu::render() {
    if (!isActive()) return;
    //Initialize screen matrix.
//    uint8_t **newScreen;
//    newScreen = new uint8_t *[getColumns()];
//    for (int i = 0; i < getRows(); i++) {
//        newScreen[i] = new uint8_t[getColumns()];
//        for (int j = 0; j < getColumns(); j++) newScreen[i][j] = ' ';
//    }
    this->fill(newScreen);
    //Get screen data from menuitem
    this->activeMenuItem->render(newScreen, getRows(), getColumns());
    if (transitionCallback) {
        this->transitionCallback(oldScreen, newScreen);
    } else {
        this->print(newScreen);
    }
    this->copy(oldScreen, newScreen);

    //Print it out
//    this->_lcd->clear();
//    this->_lcd->home();
//    for (int i = 0; i < getRows(); i++) {
//        this->_lcd->setCursor(0, i);
//        for (int j = 0; j < getColumns(); j++) {
//            this->_lcd->print((char) newScreen[i][j]);
//        }
//        delete (newScreen[i]);
//    }
//    delete (newScreen);
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
//        delete (screen[i]);
    }
//    delete (screen);
}

void Menu::setTransition(EasyLCDMenuTransition cb) {
    transitionCallback = cb;
}

void Menu::copy(uint8_t **oldScreen, uint8_t **newScreen) {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            oldScreen[i][j] = newScreen[i][j];
        }
    }
}


