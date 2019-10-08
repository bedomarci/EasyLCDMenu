#include "Menu.hpp"

Menu::Menu() {
    _renderer = new MenuRenderer();
}

Menu::Menu(uint8_t rows, uint8_t columns) : Menu() {
    _rows = rows;
    _columns = columns;
}

void Menu::setActiveMenuItem(MenuItem *menuItem) {
    this->activeMenuItem = menuItem;
}

void Menu::enter() {
    Serial.println("ENTER MENU");
    if (!this->rootMenuItem) return;
    Serial.println("ENTER MENU2");
    this->rootMenuItem->enter();
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
    if (homeCallback) homeCallback();
    Serial.println("GO HOME");
}

void Menu::onHome(EasyLCDMenuFunction cb) {
    homeCallback = cb;
}

void Menu::begin(LCD *lcd) {
    _lcd = lcd;
    this->_renderer->begin(lcd);
}

LCD *Menu::getLcd() {
    return _lcd;
}

MenuRenderer *Menu::getRenderer() {
    return _renderer;
}

void Menu::render() {
    this->_renderer->render(this->activeMenuItem);
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



