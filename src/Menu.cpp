#include "Menu.hpp"

#include "TaskScheduler.h"

Menu::Menu(uint8_t rows, uint8_t columns) {
    _rows       = rows;
    _columns    = columns;
//    _renderer   = new MenuRenderer(rows, columns);
//    tTransition = new Task(EASYLCDMENU_DEFAULT_ANIM_INTERVAL, columns, [this]() { this->makeStep(); });
//    tTransition = new Task(EASYLCDMENU_DEFAULT_ANIM_INTERVAL, columns, []() {  });
//    tTransition = new Task(EASYLCDMENU_DEFAULT_ANIM_INTERVAL, columns, (etl::ifunction<void>*)etl::function_imv<&Menu, this, &Menu::makeStep>);

//    tTransition = new Task(EASYLCDMENU_DEFAULT_ANIM_INTERVAL, columns, etl::delegate<int(int)>::create([this]() { this->makeStep(); }));

    newDisplay     = new uint8_t *[getColumns()];
    currentDisplay = new uint8_t *[getColumns()];
    for (int i = 0; i < getRows(); i++) {
        newDisplay[i]     = new uint8_t[getColumns()];
        currentDisplay[i] = new uint8_t[getColumns()];
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
//    uint8_t **newDisplay;
//    newDisplay = new uint8_t *[getColumns()];
//    for (int i = 0; i < getRows(); i++) {
//        newDisplay[i] = new uint8_t[getColumns()];
//        for (int j = 0; j < getColumns(); j++) newDisplay[i][j] = ' ';
//    }
    this->fill(newDisplay);
    //Get screen data from menuitem
    this->activeMenuItem->render(newDisplay, getRows(), getColumns());
    this->print(newDisplay);

    //Print it out
//    this->_lcd->clear();
//    this->_lcd->home();
//    for (int i = 0; i < getRows(); i++) {
//        this->_lcd->setCursor(0, i);
//        for (int j = 0; j < getColumns(); j++) {
//            this->_lcd->print((char) newDisplay[i][j]);
//        }
//        delete (newDisplay[i]);
//    }
//    delete (newDisplay);
}

void Menu::makeStep() {

}

void Menu::makeTransition(uint8_t **from, uint8_t **to) {

    tTransition->restart();
}

void Menu::fill(uint8_t **display) {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++) {
            display[i][j] = ' ';
        }
    }
}

void Menu::print(uint8_t **display) {
    this->_lcd->clear();
    this->_lcd->home();
    for (int i = 0; i < getRows(); i++) {
        this->_lcd->setCursor(0, i);
        for (int j = 0; j < getColumns(); j++) {
            this->_lcd->print((char) display[i][j]);
        }
//        delete (display[i]);
    }
//    delete (display);
}


