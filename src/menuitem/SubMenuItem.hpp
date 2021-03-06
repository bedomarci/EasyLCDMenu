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

    void render(uint8_t **screen, uint8_t rows, uint8_t columns) override;

    void navigate(EasyLCDMenuControl control) override;

    void add(MenuItem *menuItem);

    void setMenu(Menu *menu) override;

protected:
    LinkedList<MenuItem *> container;
    uint8_t selectedMenuItemIndex = 0;
    uint8_t selectedMenuItemIndexMax = 0;
    uint8_t cursorPosition = 0;
    uint8_t cursorPositionMax = 0;
};

SubMenuItem::SubMenuItem() : MenuItemTemplate<uint8_t>() {
    this->container = LinkedList<MenuItem *>();
}

SubMenuItem::SubMenuItem(uint8_t *value, const char *label) : MenuItemTemplate<uint8_t>(value, label) {
    SubMenuItem();
}

void SubMenuItem::add(MenuItem *menuItem) {
    container.add(menuItem);
    menuItem->setParent(this);
    if (this->getMenu()) {
        menuItem->setMenu(this->getMenu());
    }
}

void SubMenuItem::navigate(EasyLCDMenuControl control) {
    selectedMenuItemIndexMax = container.size() - 1;
    cursorPositionMax = this->getMenu()->getRows() - 1;

    switch (control) {
        case NEXT:
            selectedMenuItemIndex = constrain((selectedMenuItemIndex - 1), 0, selectedMenuItemIndexMax);
            cursorPosition = constrain((cursorPosition - 1), 0, cursorPositionMax);
            this->getMenu()->render(NONE);
            break;
        case PREVIOUS:
            selectedMenuItemIndex = constrain((selectedMenuItemIndex + 1), 0, selectedMenuItemIndexMax);
            cursorPosition = constrain((cursorPosition + 1), 0, cursorPositionMax);
            this->getMenu()->render(NONE);
            break;
        case GO:
            container.get(selectedMenuItemIndex)->enter(RIGHT);
            break;
        case BACK:
            this->leave();
            break;
    }
}

void SubMenuItem::render(uint8_t **screen, uint8_t rows, uint8_t columns) {

    uint8_t startIndex = selectedMenuItemIndex - cursorPosition;
    for (uint8_t i = 0; i < getRows() && i < container.size(); i++) {
        MenuItem *currentSubmenuItem = container.get(startIndex + i);
        this->setCursor(i, 1);
        this->print(screen, currentSubmenuItem->getLabel());
    }
    this->setCursor(cursorPosition, 0);
    this->print(screen, EasyLCDMenuRight);
}

void SubMenuItem::setMenu(Menu *menu) {
    MenuItemTemplate::setMenu(menu);
    MenuItem *item = nullptr;
    for (uint8_t i = 0; i < container.size(); i++) {
        item = container.get(i);
        item->setMenu(menu);
    }
}


#endif //EASYLCDMENU_SUBMENUITEM_HPP
