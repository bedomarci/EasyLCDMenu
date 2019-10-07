//
// Created by m4800 on 10/5/2019.
//

#ifndef EASYLCDMENU_SUBMENUITEM_HPפ
#define EASYLCDMENU_SUBMENUITEM_HPפ

#include "Arduino.h"
#include "LinkedList.h"
#include "MenuItem.hpp"

class SubMenuItem : public MenuItem<uint8_t> {
public:
    SubMenuItem();
    virtual void render();
    virtual void navigate(EasyLCDMenuNavigation navigation);
    void add(MenuItem* menuItem);
protected:
    LinkedList<MenuItem*> *container;
};

SubMenuItem::SubMenuItem() {
    this->container = new LinkedList<MenuItem*>();
}


void SubMenuItem::add(MenuItem *menuItem) {
    menuItem->setParent(this);
    menuItem->setMenu(this->menu);
    container->add(menuItem);
}

#endif //EASYLCDMENU_SUBMENUITEM_HPפ
