//
// Created by m4800 on 10/5/2019.
//

#ifndef EASYLCDMENU_SUBMENUITEM_HPP
#define EASYLCDMENU_SUBMENUITEM_HPP

#include "Arduino.h"
#include "LinkedList.h"
#include "MenuItem.hpp"

class SubMenuItem : public MenuItemTemplate<uint8_t> {
public:
    SubMenuItem();
    SubMenuItem(uint8_t *value, const char *label);
    void render(uint8_t **display, uint8_t rows, uint8_t columns) override;
    void navigate(EasyLCDMenuControl control) override;
    void add(MenuItem *menuItem);
protected:
    LinkedList<MenuItem *> *container;
    uint8_t                selectedMenuItemIndex = 0;
    uint8_t                cursorPosition        = 0;
    uint8_t                cursorPositionMax     = 0;
};

SubMenuItem::SubMenuItem() : MenuItemTemplate<uint8_t>() {
    this->container = new LinkedList<MenuItem *>();
    cursorPositionMax = this->menu->getRenderer()->getRows();
}

SubMenuItem::SubMenuItem(uint8_t *value, const char *label) : MenuItemTemplate<uint8_t>(value, label) {
    SubMenuItem();
}

void SubMenuItem::add(MenuItem *menuItem) {
    menuItem->setParent(this);
    menuItem->setMenu(this->menu);
    container->add(menuItem);
}

void SubMenuItem::navigate(EasyLCDMenuControl control) {
    switch (control) {
        case NEXT:
            selectedMenuItemIndex = constrain(++selectedMenuItemIndex, 0, container->size() - 1);
            cursorPosition        = constrain(++cursorPosition, 0, cursorPositionMax);
            break;
        case PREVIOUS:
            selectedMenuItemIndex = constrain(--selectedMenuItemIndex, 0, container->size() - 1);
            cursorPosition        = constrain(--cursorPosition, 0, cursorPositionMax);
            break;
        case GO:
            container->get(selectedMenuItemIndex)->enter();
            break;
        case BACK:
            leave();
            break;
    }
}

void SubMenuItem::render(uint8_t **display, uint8_t rows, uint8_t columns) {
    uint8_t startIndex = selectedMenuItemIndex - cursorPosition;

    for (uint8_t i = 0; i < getRows(); i++) {
        MenuItem *currentSubmenuItem = container->get(startIndex + i);
        this->setCursor(i, 1);
        this->print(display, currentSubmenuItem->getLabel());
    }
    this->setCursor(cursorPosition, 0);
    this->print(display, '>');
}


#endif //EASYLCDMENU_SUBMENUITEM_HPP
