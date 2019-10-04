//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_NUMBERMENUITEM_HPP
#define EASYLCDMENU_NUMBERMENUITEM_HPP
#include "NumberMenuItem.hpp"

class NumberMenuItem : public MenuItem<double> {
    void render();
    void change(EasyLCDMenuControl control);
};

#endif //EASYLCDMENU_NUMBERMENUITEM_HPP
