//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_MENUITEM_HPP
#define EASYLCDMENU_MENUITEM_HPP

#include "../common.hpp"
#include "Arduino.h"

template<typename T>
class MenuItemTemplate : public MenuItem {
public:
    MenuItemTemplate();
    MenuItemTemplate(T *value, const char *label);
    virtual void render(uint8_t **display, uint8_t rows, uint8_t columns) = 0;
    virtual void navigate(EasyLCDMenuControl control) = 0;
    void enter(EasyLCDMenuTransition transition = NONE);
    void leave();
    void setValue(T value);
    T getValue();
    const char *getLabel();
    virtual void setMenu(Menu *menu);
    void setParent(MenuItem *parent);
protected:
    uint8_t icon;
    uint8_t cursorRow = 0, cursorColumn = 0;

    uint8_t getRows();

    uint8_t getColumns();

    MenuItem *getParent();

    Menu *getMenu();

    void setCursor(uint8_t row, uint8_t column);

    void print(uint8_t **display, const char *txt);

    void print(uint8_t **display, char c);

private:
    MenuItem   *parent = nullptr;
    Menu       *menu = nullptr;
    T          *_value = nullptr;
    const char *_label = nullptr;

};

template<typename T>
MenuItemTemplate<T>::MenuItemTemplate(T *value, const char *label) :MenuItemTemplate<T>() {
    this->_label = label;
    this->_value = value;
}

template<typename T>
MenuItemTemplate<T>::MenuItemTemplate() {
}

template<typename T>
void MenuItemTemplate<T>::setMenu(Menu *menu) {
    this->menu = menu;
}

template<typename T>
T MenuItemTemplate<T>::getValue() {
    return *_value;
}

template<typename T>
void MenuItemTemplate<T>::setValue(T value) {
    *this->_value = value;
}

template<typename T>
void MenuItemTemplate<T>::setParent(MenuItem *parent) {
    this->parent = parent;
}

template<typename T>
MenuItem *MenuItemTemplate<T>::getParent() {
    return this->parent;
}

template<typename T>
void MenuItemTemplate<T>::enter(EasyLCDMenuTransition transition) {
    if (!this->menu) return;
    menu->setActiveMenuItem(this);
    menu->render(transition);
    Serial.println(this->getLabel());
}

template<typename T>
void MenuItemTemplate<T>::leave() {
    MenuItem *parent = this->getParent();
    if (parent) {
        parent->enter(LEFT);
    } else {
        menu->home();
    }
}

template<typename T>
void MenuItemTemplate<T>::setCursor(uint8_t row, uint8_t column) {
    cursorRow    = row;
    cursorColumn = column;
}

template<typename T>
void MenuItemTemplate<T>::print(uint8_t **display, const char *txt) {
    uint8_t length = strlen(txt);
    memcpy(&display[cursorRow][cursorColumn], txt, length);
    cursorRow += length;
}

template<typename T>
void MenuItemTemplate<T>::print(uint8_t **display, char c) {
    display[cursorRow][cursorColumn] = c;
    cursorRow++;
}

template<typename T>
uint8_t MenuItemTemplate<T>::getRows() {
    return this->menu->getRows();
}

template<typename T>
uint8_t MenuItemTemplate<T>::getColumns() {
    return this->menu->getColumns();
}

template<typename T>
const char *MenuItemTemplate<T>::getLabel() {
    return this->_label;
}

template<typename T>
Menu *MenuItemTemplate<T>::getMenu() {
    return menu;
}


#endif //EASYLCDMENU_MENUITEM_HPP
