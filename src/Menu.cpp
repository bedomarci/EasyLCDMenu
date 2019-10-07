//
// Created by m4800 on 10/5/2019.
//

#include "Menu.hpp"

void Menu::setActiveMenuItem(MenuItem *menuItem) {
    this->activeMenuItem = menuItem;
}

void Menu::enter() {
    if (!this->rootMenuItem) return;
    this->rootMenuItem->enter();
}

void Menu::setRootMenuItem(MenuItem *menuItem) {
    menuItem->setMenu(this);
    this->rootMenuItem = menuItem;
}

void Menu::navigate(EasyLCDMenuNavigation control) {
    this->activeMenuItem->navigate(control);
}

void Menu::select() {
    this->navigate(SELECT);
}

void Menu::right() {
    this->navigate(RIGHT);
}

void Menu::left() {
    this->navigate(LEFT);
}

void Menu::down() {
    this->navigate(DOWN);

}

void Menu::up() {
    this->navigate(UP);
}
