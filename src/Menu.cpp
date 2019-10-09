#include "Menu.hpp"

Menu::Menu(uint8_t rows, uint8_t columns) {
    _rows = rows;
    _columns = columns;
    _renderer = new MenuRenderer(rows, columns);
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
    this->_renderer->begin(lcd);
}

LCD *Menu::getLcd() {
    return _lcd;
}

MenuRenderer *Menu::getRenderer() {
    return _renderer;
}

void Menu::render() {
    if (isActive()) {
        this->_renderer->render(this->activeMenuItem);
    }
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



