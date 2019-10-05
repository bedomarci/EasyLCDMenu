//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_NUMBERMENUITEM_HPP
#define EASYLCDMENU_NUMBERMENUITEM_HPP
#include "MenuItem.hpp"

class NumberMenuItem : public MenuItem<double> {
    void render();
    void navigate(EasyLCDMenuNavigation navigation);
};

#endif //EASYLCDMENU_NUMBERMENUITEM_HPP
