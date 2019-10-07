//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_MENUITEM_H
#define EASYLCDMENU_MENUITEM_H

#include "../Menu.hpp"
#include "common.h"

template<typename T>
class MenuItem {
public:
    virtual void render() = 0;

    virtual void navigate(EasyLCDMenuNavigation navigation) = 0;

    void enter();

    void setValue(T value);

    T getValue();

    void setMenu(Menu *menu);

    void setParent(MenuItem *parent);

    MenuItem *getParent();

protected:
    MenuItem   *parent;
    Menu       *menu;
    T          *value;
    const char *label;
    uint8_t    icon;

};

template<typename T>
void MenuItem<T>::setMenu(Menu *menu) {
    this->menu = menu;
}

template<typename T>
T MenuItem<T>::getValue() {
    return value;
}

template<typename T>
void MenuItem<T>::setValue(T value) {
    this->value = value;
}

template<typename T>
void MenuItem<T>::setParent(MenuItem *parent) {
    this->parent = parent;
}

template<typename T>
MenuItem *MenuItem<T>::getParent() {
    return this->parent;
}

template<typename T>
void MenuItem<T>::enter() {
    if (!this->menu) return;
    menu->setActiveMenuItem(this);
}

#endif //EASYLCDMENU_MENUITEM_H
