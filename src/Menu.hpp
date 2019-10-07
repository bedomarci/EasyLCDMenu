//
// Created by m4800 on 10/5/2019.
//

#ifndef EASYLCDMENU_MENU_HPP
#define EASYLCDMENU_MENU_HPP

#include "common.h"
#include "menuitem/MenuItem.hpp"

class Menu {
public:
    void home(EasyLCDMenuFunction cb);

    void enter();

    void setActiveMenuItem(MenuItem *menuItem);

    void setRootMenuItem(MenuItem *menuItem);

    void up();
    void down();
    void left();
    void right();
    void select();
    void navigate(EasyLCDMenuNavigation control);

protected:
    MenuItem *rootMenuItem   = nullptr;
    MenuItem *activeMenuItem = nullptr;
};


#endif //EASYLCDMENU_MENU_HPP
